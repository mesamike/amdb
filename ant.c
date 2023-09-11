#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "amdb.h"

FILE *antfile;
char buffer[1024];	


int main ()
{
   antenna ant;

   antfile = fopen("gis_am_ant_sys.dat", "r");
   while (fgets(buffer, 1024, antfile)) {
      lms_parse_am_ant_sys(buffer, &ant);
      if((ant.hours_operation != 'X') 
         && (ant.eng_record_type == 'C')
         && ((ant.am_dom_status == 'L') ))
            printf("%ld|%c|%f|%f|%f|%s|\n",
               ant.app_id,
               ant.hours_operation,
               ant.power,       
               ant.lat,
               ant.lon,
               ant.ant_mode);
   }
   fclose(antfile);
   return 0;
}

