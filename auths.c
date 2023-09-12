#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "amdb.h"

FILE *facfile;
FILE *appfile;
FILE *antfile;

int get_fac(unsigned long fac_id, facility *fac)
{
   char buffer[BUFF_SIZE];
   fseek(facfile, 0, SEEK_SET);
   while (fgets(buffer, BUFF_SIZE, facfile)) {
      parse_fac(buffer, fac);
      if(fac->fac_id == fac_id) {
         return 1;
      }
   }
   return 0;
}

int get_app(unsigned long app_id, application *app)
{
   char buffer[BUFF_SIZE];
   fseek(appfile, 0, SEEK_SET);
   while (fgets(buffer, BUFF_SIZE, appfile)) {
      parse_app(buffer, app);
      if(app->app_id == app_id) {
         return 1;
      }
   }
   return 0;
}

int main ()
{
   char buffer[BUFF_SIZE];	
   facility fac;
   application app;
   antenna ant;


   if(!(facfile = fopen("fac.dat", "r")))
      perror("fac.dat"), exit(1);
   if(!(appfile = fopen("app.dat", "r")))
      perror("appl.dat"), exit(1);
   if(!(antfile = fopen("ant.dat", "r")))
      perror("ant.dat"), exit(1);

   while (fgets(buffer, BUFF_SIZE, antfile)) {
      parse_ant(buffer, &ant);
      if(get_app(ant.app_id, &app)) {
         if(get_fac(app.fac_id, &fac)) {
            printf("%ld|%ld|%f|%s|%s|%s|%c|%s|%f|%7.4f|%8.4f|%s|\n",
               app.fac_id, 
               app.app_id, 
               app.fac_freq, 
               fac.callsign, 
               app.comm_state,
               app.comm_city, 
               ant.hours_operation, 
               ant.ant_mode,
               ant.power, 
               ant.lat, 
               ant.lon, 
               fac.fac_status);
         }  else fprintf(stderr, "Cant find facility %lu\n", app.fac_id); 
      }  else fprintf(stderr, "Can't find app_id %lu\n", ant.app_id);   
   }
   fclose(antfile);
   fclose(appfile);
   fclose(facfile);
   return 0;
}

