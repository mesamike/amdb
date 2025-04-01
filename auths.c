#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "amdb.h"

FILE *facfile;
FILE *lfvfile;
FILE *antfile;
FILE *appfile;

static char lfvbuf[BUFF_SIZE];
static char antbuf[BUFF_SIZE];
static char buffer[BUFF_SIZE];

int get_app(char *app_uuid, appfac *app)
{
   char buffer[BUFF_SIZE];
   fseek(appfile, 0, SEEK_SET);
   while (fgets(buffer, BUFF_SIZE, appfile)) {
      parse_appfac(buffer, app);
      if( !strcmp(app->app_uuid, app_uuid)) {
         return 1;
      }
   }
   return 0;
}


int get_lfv(char *filing_id, lic_fil_ver *lfv)
{
   static long fpos;

   fseek(lfvfile, fpos, SEEK_SET);
   fgets(lfvbuf, BUFF_SIZE, lfvfile);
   while(!feof(lfvfile)) { 
   /* buffer has info we haven't examined yet, so examine it before reading next */
      parse_lfv(lfvbuf, lfv);
      if(!strcmp(lfv->filing_id, filing_id)) {
         fpos = ftell(lfvfile);
         return 1;
      }
      fgets(lfvbuf, BUFF_SIZE, lfvfile);
   }
   return 0;
}

/* get an antenna authorization given a filing_version */
/* there may be more than one authorization for a given filing_version */
int get_ant(char *filing_ver, antenna *ant)
{
   static long fpos;
   static int found;

   fseek(antfile, fpos, SEEK_SET);
   fgets(antbuf, BUFF_SIZE, antfile);
   while(!feof(antfile)) {
      /* buffer has info we haven't examined yet, so examine it before reding next */
      parse_ant(antbuf, ant);
      if(!(strcmp(ant->app_uuid, filing_ver))) {
         fpos = ftell(antfile);
         return 1;
      }
      fgets(antbuf, BUFF_SIZE, antfile);
   }
   fpos = 0;  /* we've reached end of file, start over for next customer */
   return 0;
}

int main ()
{
   facility fac;
   antenna ant;
   lic_fil_ver lfv;
   appfac app;

   if(!(facfile = fopen("fac.dat", "r")))
      perror("fac.dat"), exit(1);
   if(!(lfvfile = fopen("licfilver.dat", "r")))
      perror("licfilver.dat"), exit(1);
   if(!(antfile = fopen("ant.dat", "r")))
      perror("ant.dat"), exit(1);
   if(!(appfile = fopen("appfac.dat", "r")))
      perror("appfac.dat"), exit(1);



   /* for each entry in facfile */
   fgets(buffer, BUFF_SIZE, facfile);
   while (!feof(facfile)) {
      parse_fac(buffer, &fac);
      /* use filing_id to get license_filing_version */
      /* a particular facility may have more than one curent license_filing_version */
      /* we need to assume licfilver is sorted in ascending order by filing_id */
      while (get_lfv(fac.filing_id, &lfv)) {

         /* antenna authorizations for this license_filing_version */
         while (get_ant(lfv.filing_version, &ant)) {
           /* find the associated application to get city, state and frequency */
           if(get_app(lfv.filing_version, &app)) {
#if 0
            printf("%s|%c|%f|%7.4f|%8.4f|%s|\n",
               fac.callsign, 
               ant.hours_operation, 
               ant.power, 
               ant.lat, 
               ant.lon, 
               fac.fac_status);
#endif
            printf("%d|%s|%s|%s|%s|%s|%s|%c|%f|%7.4f|%8.4f|%s|\n",
               fac.fac_id, 
               fac.fac_uuid,
               app.app_uuid, 
               app.am_freq, 
               fac.callsign, 
               app.comm_state,
               app.comm_city, 
               ant.hours_operation, 
               ant.power, 
               ant.lat, 
               ant.lon, 
               fac.fac_status);
            }
         }  /* else fprintf(stderr, "Cant find facility %lu\n", app.fac_id); */
      } // else  fprintf(stderr, "filing version not found for filing ID %s\n", fac.filing_id);
      fgets(buffer, BUFF_SIZE, facfile); /* get next entry in facfile */
   }
   fclose(antfile);
   fclose(lfvfile);
   fclose(facfile);
   return 0;
}

