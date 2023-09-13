#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "amdb.h"

FILE *authfile;
FILE *callhistfile;
static char callhistory[BUFF_SIZE];

void get_callsigns(int facid)
{
   callsign_hist ch;
   char buffer[BUFF_SIZE];
   char prev[13];
   int found = 0;

   if(!(callhistfile = fopen("callhist.dat", "r")))
      perror("callhist.dat"), exit(1);
   
   bzero(callhistory, sizeof(callhistory));
   bzero(prev, sizeof(prev));

   /* run through call history file looking for entries that match our facility id */
   while(fgets(buffer, BUFF_SIZE, callhistfile)) {
      parse_callhist(buffer, &ch); 
      if(ch.fac_id == facid) { 
         char *call = ch.callsign; 
         found = 1;
         /* if callsign starts with D (deleted), remove the D */ 
         if(call[0] == 'D') call++;
         /* if we found a callsign previously and it's different from new one, save it */
         if(strlen(prev) && strcmp(prev, ch.callsign)) {
            if(strlen(callhistory))
               strcat(callhistory, ", ");
            strcat(callhistory, prev); 
          }
          /* callsign from current entry becomes previous call sign next time around */
          if(strlen(call) < 5)  /* filter out temporary callsigns */
             strcpy(prev, call);
      }
      if(found && !(facid == ch.fac_id)) break;
   }
   /* no more call signs found, don't save the last one we 
      found because it's the same as the current facility callsign */
   
   fclose(callhistfile);
}

int print_line(power *pwr, authorization *auth, char *callhist)
{
         printf("%ld|%04d|%s|%s|%s|", 
            auth->fac_id, (unsigned)auth->freq, auth->callsign, auth->state, auth->city);
         if(pwr->d) printf("%.0f", pwr->d);
         putchar('|');
         if(pwr->n) printf("%.0f", pwr->n);
         putchar('|');
         if(pwr->c) printf("%.0f", pwr->c);

         printf("|%s", auth->ant_mode);
         printf("|%.4f|%.4f|%s|", auth->lat, auth->lon, auth->status);
        
         if(callhist) 
            printf("%s", callhist);
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
   power pwr;
   float watts;
   char buffer[BUFF_SIZE];

   if(!(authfile = fopen("auths.dat", "r")))
      perror("auths.dat"), exit(1);


   while(fgets(buffer, BUFF_SIZE, authfile)) {
      parse_auth(buffer, ap[i]); 


      /* workaround for night auths that don't specify coords */ 
      if( (ap[i]->lat==0.0) && (ap[i]->lon ==0.0) ){
         ap[i]->lat = cur_lat; ap[i]->lon = cur_lon;
      }
      /* new entry if different facility or different transmitter site */
      if(   (ap[i]->fac_id != cur_fac_id) || 
            (fabs(ap[i]->lat-cur_lat) > 0.01)  || 
            (fabs(ap[i]->lon-cur_lon) > 0.01) ) {
         if(cur_fac_id) print_line(&pwr, ap[1-i], callhistory); /* print previous */
         cur_fac_id = ap[i]->fac_id;
         cur_lat = ap[i]->lat;
         cur_lon = ap[i]->lon;
         bzero(&pwr, sizeof(power));
      }



      watts = ap[i]->power*1000.0;
      switch(ap[i]->hours_operation) {
         case 'U': pwr.d = pwr.n = watts; break;
         case 'D': pwr.d = watts; break;
         case 'N': pwr.n = watts; break;
         case 'R': 
         case 'C': pwr.c = watts; break;
      }

      get_callsigns(ap[i]->fac_id);

      i = 1 - i;   /* switch to other auth structure */
   }


   print_line(&pwr, ap[i], callhistory);
   fclose(authfile);
   return 0;
}

