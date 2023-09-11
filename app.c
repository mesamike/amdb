#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "amdb.h"

FILE *infile;

int main ()
{
   char buffer[1024];	
   application ap;

   infile = fopen("gis_application.dat", "r");
   while (fgets(buffer, 1024, infile)) {
      lms_parse_application(buffer, &ap);
      if(!strcmp(ap.app_service, "AM")&& (ap.fac_freq>0) &&
	  ( !strncmp(ap.app_type, "ML", 2) 
	  || !strncmp(ap.app_type, "MML", 3) 
          || !strncmp(ap.app_type, "L", 1) 
          || !strncmp(ap.app_type, "Z", 1) 
          || !strncmp(ap.app_type, "STA", 3) 
          || !strncmp(ap.app_type, "NP", 2) 
          || !strncmp(ap.app_type, "MP", 2)) 
      ) {
         printf("%ld|%ld|%f|%s|%s|\n",
            ap.app_id,
            ap.fac_id,
            ap.fac_freq,
            ap.comm_city,
            ap.comm_state);
      }
   }
   fclose(infile);
   return 0;
}

   
