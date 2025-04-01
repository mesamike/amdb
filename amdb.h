#ifndef AMDB_H
#define AMDB_H

#define BUFF_SIZE 1024

typedef struct {
   char active_ind;
   char callsign[20];
   int seq_num;
   char fac_uuid[36];
} callsign_history;

typedef struct {
   unsigned long fac_id;
   char fac_uuid[60];
   char app_uuid[60];
   float freq;
   char callsign[13];
   char state[3];
   char city[80];
   char hours_operation;
   float power;
   float lat;
   float lon;
   char status[6];
} authorization;    

typedef struct {
   char active_ind;
   char app_uuid[36];
   unsigned long fac_id;
   char am_freq[10];
   char comm_city[40];
   char comm_state[5];
   char app_service[5];
   char app_type[6];
} appfac;

typedef struct {
   char app_uuid[100];
   char active_ind;
   char hours_operation;
   int lat_deg;
   char lat_dir;
   int lat_min;
   float lat_sec;
   int lon_deg;
   char lon_dir;
   int lon_min;
   float lon_sec;
   float power;
} lms_antenna;

typedef struct {
   char app_uuid[36];
   char hours_operation;
   float power;
   float lat;
   float lon;
} antenna;

typedef struct power_t {
   int flag;
   char *city;
   char *state;
   char *ant_id;
   float c;
   float d;
   float n;
   float p;
   float r;
   float u;
} power;

typedef struct {
   char  callsign[13]; 
   char  comm_city[21];
   char  comm_state[3];
   int   fac_id;
   char  fac_uuid[100];
   char  filing_id[100];
   char  fac_status[6];
   int   fac_freq;
   char  service_code[4];
   char  call_date[25]; 
   char  status_date[36];
} facility;

typedef struct {
   char active_ind;
   char auth_type_code[10];
   char status_code[10];
   char discriminator_code[10];
   char filing_version_id[100];
   char filing_id[100];
   char previous_filing_version_id[100];
   char purpose_code[10];
   char service_code[10];
   char sub_purpose_code[10];
} lms_lic_fil_ver;
   
typedef struct {
   char filing_id[100];
   char filing_version[100];
   char prev_filing_version[100];
} lic_fil_ver;

void lms_parse_application_facility(char *, appfac *);
void lms_parse_app_am_antenna(char *, lms_antenna *);
void lms_parse_facility(char *, facility *);
void lms_parse_license_filing_version(char *, lms_lic_fil_ver *);

void parse_appfac(char *, appfac *);
void parse_fac(char *, facility *);
void parse_ant(char *, antenna *);
void parse_lfv(char *, lic_fil_ver *);
void parse_auth(char *, authorization *);
void parse_callhist(char *, callsign_history *);
#endif
