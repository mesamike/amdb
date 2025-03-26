#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "amdb.h"

FILE *antfile;
char buffer[BUFF_SIZE];	


int main ()
{
   lms_antenna ant;
   float lat;
   float lon;

   antfile = fopen("app_am_antenna.dat", "r");
   while (fgets(buffer, BUFF_SIZE, antfile)) {
      lms_parse_app_am_antenna(buffer, &ant);
      if( (ant.active_ind == 'Y')  
         && (ant.hours_operation) ) { /* not blank */
            lat = ant.lat_deg + ant.lat_min/60.0 + ant.lat_sec/3600.0;
            lat = (ant.lat_dir == 'S') ? -lat : lat;
            lon = ant.lon_deg + ant.lon_min/60.0 + ant.lon_sec/3600.0;
            lon = (ant.lon_dir == 'W') ? -lon : lon;
            printf("%s|%c|%f|%f|%f|\n",
               ant.app_uuid,
               ant.hours_operation,
               ant.power,       
               lat,
               lon);
         }   
   }
   fclose(antfile);
   return 0;
}

