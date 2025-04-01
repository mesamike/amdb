#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "amdb.h"

FILE *lfvfile;
char buffer[BUFF_SIZE];	


int main ()
{
   lms_lic_fil_ver lfv;

   lfvfile = fopen("license_filing_version.dat", "r");

   /* don't try to parse the headers! */
   fgets(buffer, BUFF_SIZE, lfvfile);

   /* get first data record */
   fgets(buffer, BUFF_SIZE, lfvfile);

   while (!feof(lfvfile))  {
      lms_parse_license_filing_version(buffer, &lfv);
      if( (lfv.active_ind == 'Y')  
         && !strcmp(lfv.discriminator_code, "AM") 
         && !strcmp(lfv.status_code, "GRA")
         && ( !strcmp(lfv.purpose_code, "L2C") || 
              !strcmp(lfv.purpose_code, "MOD") || 
              !strcmp(lfv.purpose_code, "AMD") || 
              !strcmp(lfv.purpose_code, "REN"))   ) {

            printf("%s|%s|\n", lfv.filing_id, lfv.filing_version_id);
      }   
      fgets(buffer, BUFF_SIZE, lfvfile);
   }
   fclose(lfvfile);
   return 0;
}

