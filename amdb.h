#ifndef AMDB_H
#define AMDB_H

#define BUFF_SIZE 1024

typedef struct {
   char begin_date[20];
   char callsign[13];
   unsigned long hist_id;
   unsigned short seq_id;
   unsigned long fac_id;
   char change_date[20];
} callsign_hist;

typedef struct {
   unsigned long app_id;
   unsigned long fac_id;
   float freq;
   char callsign[13];
   char state[3];
   char city[80];
   char hours_operation;
   float power;
   float lat;
   float lon;
   char status[6];
   char ant_mode[10];
} authorization;    

typedef struct {
   unsigned long app_id;
   unsigned long fac_id;
   float fac_freq;
   char comm_city[40];
   char comm_state[5];
   char app_service[5];
   char app_type[5];
} application;


typedef struct {
   unsigned long app_id;
   char hours_operation;
   float power;
   double lat;
   double lon;
   char ant_mode[4];
   char am_dom_status;
   char eng_record_type;
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
   char  fac_status[6];
   int   fac_freq;
   char service_code[4];
} facility;
   

void lms_parse_application(char *, application *);
void lms_parse_am_ant_sys(char *, antenna *);
void lms_parse_facility(char *, facility *);
void parse_fac(char *, facility *);
void parse_app(char *, application *);
void parse_ant(char *, antenna *);
void parse_auth(char *, authorization *);
void parse_callhist(char *, callsign_hist *);
#endif
