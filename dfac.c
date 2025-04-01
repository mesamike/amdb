#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "amdb.h"

FILE *infile;

int main () 
{
   char buffer[1024];	
   char buffer2[1024];	
   facility fac;

   infile = fopen("facility.dat", "r");
   while (fgets(buffer, 1024, infile)) {
      strcpy(buffer2, buffer);
      lms_parse_facility(buffer2, &fac);

      if(
         !strcmp(fac.service_code, "AM") && 
         //!strcmp(fac.fac_country, "US") && 
         (fac.callsign[0] == 'D') &&
         (!strcmp(fac.fac_status, "LICAN") || !strcmp(fac.fac_status, "PRCAN") )  

      ) {
         *strchr(buffer,'\n') = 0;
         *strrchr(buffer,'|') = 0;
         *strrchr(buffer,'^') = 0;
/* status_date | status | fac_id | callsign | freq | state | city | */
         printf("%s|%s|%d|%s|%d|%s|%s|\n",
            fac.status_date, 
            fac.fac_status, 
            fac.fac_id, 
            fac.callsign,
            fac.fac_freq,
            fac.comm_state,
            fac.comm_city);
      }
          
   }
   fclose(infile);
   return 0;
}

