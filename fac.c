/* Distill the facility information we need from the FCC facility.dat file */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "amdb.h"

FILE *infile;

int main ()
{
   char buffer[1024];	
   facility fac;

   infile = fopen("facility.dat", "r");
   while (fgets(buffer, 1024, infile)) {

      lms_parse_facility(buffer, &fac);

      if(
         !strcmp(fac.service_code, "AM") && 
              (!strcmp(fac.fac_status, "LICEN") || 
               !strcmp(fac.fac_status, "LICSL") || 
               !strcmp(fac.fac_status, "LICRP") || 
               !strcmp(fac.fac_status, "LICSU") || 
               !strcmp(fac.fac_status, "INTOP") || 
               !strcmp(fac.fac_status, "AUCTN") || 
               !strcmp(fac.fac_status, "EXPER") || 
               /* !strcmp(fac.fac_status, "UNKNO") || */ 
               !strcmp(fac.fac_status, "CPOFF"))
#if 0
 &&
         (
            (fac.callsign[0] == 'K') || 
            (fac.callsign[0] == 'W') ||
            ((fac.callsign[0] == 'D') && ((fac.callsign[1] == 'K')||(fac.callsign[1]='W'))) 
         )  
#endif
      ) {
         /* We'll pick up city and state from application record */
         printf("%d|%s|%s|\n", 
                 fac.fac_id,
                 fac.callsign,
                 fac.fac_status);
      }
          
   }
   fclose(infile);
   return 0;
}

