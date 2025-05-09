#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "amdb.h"

FILE *authfile;
FILE *callhistfile;

static char callhist[BUFF_SIZE];

void get_callhist(char* fac_uuid)
{
   static char buffer[BUFF_SIZE];
   char prev[20];
   callsign_history ch;

   if(!(callhistfile = fopen("fachist.dat", "r")))
      perror("fachist.dat"), exit(1);

   bzero(callhist, sizeof(callhist));
   bzero(prev, sizeof(prev));

   /* run through call history file looking for entries that match our facility id */
   while(fgets(buffer, BUFF_SIZE, callhistfile)) {
      parse_callhist(buffer, &ch);
      if(!strcmp(ch.fac_uuid, fac_uuid)) {
         char *call = ch.callsign;

         /* if callsign starts with D (deleted), remove the D */
         while(call[0] == 'D') call++; /* there may be more than one D, remove them all */

         /* if we found a callsign previously and it's different from new one, save it */
         if(strlen(prev) && strcmp(prev, call)) {
            /* add a comma if it's not the first entry */
            if(strlen(callhist))
               strcat(callhist, ", ");

            /* add call sign to list */
            strcat(callhist, prev);
          }

          /* callsign from current entry becomes previous call sign next time around */
          if(strlen(call) < 5)  /* filter out temporary callsigns */
             strcpy(prev, call);
      }
   }
   /* no more call signs found, don't save the last one we 
      found because it's the same as the current facility callsign */

   fclose(callhistfile);
}

int print_line(power *pwr, authorization *auth)
{
         printf("%ld|%04d|%s|%s|%s|", 
            auth->fac_id, (unsigned)auth->freq, auth->callsign, auth->state, auth->city);
         if(pwr->d) printf("%.0f", pwr->d);
         putchar('|');
         if(pwr->n) printf("%.0f", pwr->n);
         putchar('|');
         if(pwr->c) printf("%.0f", pwr->c);

         putchar('|'); // place holder of ant_mode

         printf("|%.4f|%.4f|%s|%s", auth->lat, auth->lon, auth->status, callhist);
         ////printf("|%.4f|%.4f|%s|", auth->lat, auth->lon, auth->status);
         putchar('\n');
}       
       



int main ()
{
   authorization auth1, auth2;
   authorization *ap[2] = {&auth1, &auth2};
   int i = 0;
   unsigned long cur_fac_id = 0;
   float cur_lat;
   float cur_lon;
   int cur_freq = 0;
   power pwr;
   float watts;
   char buffer[BUFF_SIZE];

   if(!(authfile = fopen("auths.dat", "r")))
      perror("auths.dat"), exit(1);


   while(fgets(buffer, BUFF_SIZE, authfile)) {
      parse_auth(buffer, ap[i]); 


      /* workaround for night auths that don't specify coords */ 
      //if( (ap[i]->lat==0.0) && (ap[i]->lon ==0.0) ){
      //   ap[i]->lat = cur_lat; ap[i]->lon = cur_lon;
      // }
      /* new entry if different facility or different transmitter site or different frequency */
      if(   (ap[i]->fac_id != cur_fac_id) || 
            (ap[i]->freq != cur_freq) ||
            (fabs(ap[i]->lat-cur_lat) > 0.01)  || 
            (fabs(ap[i]->lon-cur_lon) > 0.01) ) {
         //if(cur_fac_id) print_line(&pwr, ap[1-i], callhistory); /* print previous */
         if(cur_fac_id) print_line(&pwr, ap[1-i]); /* print previous */

         /* workaround for auths that don't include antenna mode */
         //if (strlen(ap[i]->ant_mode)) strcpy (ant_mode, ap[i]->ant_mode);

         cur_fac_id = ap[i]->fac_id;
         cur_freq = ap[i]->freq;
         cur_lat = ap[i]->lat;
         cur_lon = ap[i]->lon;
         bzero(&pwr, sizeof(power));
      }


/* workaround for auths that don't include antenna mode */

      watts = ap[i]->power*1000.0;
      switch(ap[i]->hours_operation) {
         case 'U': pwr.d = pwr.n = watts; break;
         case 'D': pwr.d = watts; break;
         case 'N': pwr.n = watts; break;
         case 'R': 
         case 'C': pwr.c = watts; break;
      }

      get_callhist(ap[i]->fac_uuid);

      i = 1 - i;   /* switch to other auth structure */
   }


   //print_line(&pwr, ap[i], callhistory);
   print_line(&pwr, ap[i]);
   fclose(authfile);
   return 0;
}

