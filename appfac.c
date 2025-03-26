#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "amdb.h"

FILE *infile;

int main ()
{
   char buffer[BUFF_SIZE];	
   appfac af;

   infile = fopen("application_facility.dat", "r");
   while (fgets(buffer, BUFF_SIZE, infile)) {
      lms_parse_application_facility(buffer, &af);
      
       if (    strlen(af.am_freq)   /* if am frequency is non-blank, then this is for an AM station */      
            && (af.active_ind == 'Y') )  /*  we want active entries only */ 
         printf("%ld|%s|%s|%s|%s|\n",
            af.fac_id,
            af.app_uuid,
            af.am_freq,
            af.comm_city,
            af.comm_state);
   }      
   fclose(infile);
   return 0;
}

   
