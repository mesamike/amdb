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
               !strcmp(fac.fac_status, "CPOFF"))
      ) {
         /* We should pick up city, state and frequency from application record */
         printf("%s|%s|%s|%d|%s|%s|%s|%d|%s|\n", 
                 fac.callsign,
                 fac.comm_city,
                 fac.comm_state,
                 fac.fac_id,
                 fac.fac_uuid,
                 fac.filing_id,
                 fac.fac_status,
                 fac.fac_freq, 
                 fac.service_code);
      }
          
   }
   fclose(infile);
   return 0;
}

