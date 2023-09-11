/*  structures of the LMS data files as received frm the FCC */
/*  For reference only; We won't need to use these; */

#ifndef LMS_H
#define LMS_H

/* gis_am_ant_sys table structure */
typedef struct {
   char am_dom_status;
   char ant_dir_ind;
   char ant_mode[4];
   unsigned long ant_sys_id;
   unsigned long application_id;
   unsigned short aug_cnt;
   char augmented_indl
   char bad_data_switch;
   double biased_lat;
   double biased_lon
   char domestic_pattern;
   char dummy_data_switch;
   float efficiency_restricted;
   float efficiency_theoretical;
   char eng_record_type;
   char feed_circ_other[255];
   char feed_circ_type[3];
   char grandfathered_ind;
   char hours_operation;
   char last_update_date[30];
   int lat_deg;
   char lat_dir;
   int lat_min;
   float lat_sec;
   int lat_whole_secs;
   int lon_deg;
   char lon_dir;
   int lon_min;
   float lon_sec;
   int lon_whole_secs
   char mainkey[17];
   float power;
   float q_factor;
   char q_factor_custom_ind;
   float rms_augmented;
   float rms_standard;
   float rms_theoretical;
   char specified_hours_range[26];
   unsigned int tower_cnt;
   char eol;
} gis_am_ant_sys;


/* Braodcast facility data table structure */
typedef struct {
   char  active_ind;            /* 'Y' or 'N' */
   char  atcs3_ind;             /* 'Y' or 'N' */
   char  callsign[13]; 
   char  callsign_date[30];
   int   channel;
   char  chan_share_ind;        /* 'Y' or 'N' */
   char  comm_city[21];
   char  comm_state[3];
   char  create_ts[30];
   char  digital_op;             /* 'A' or 'H' */
   char  exp_date[30];
   int   fac_id;
   char  fac_status[6];
   char  fac_type[4];            /* "CDT" or "EDT" */
   char  fac_uuid[40];
   int   fac_zone_code;
   int   fac_freq;
   char  last_update_ts[30];
   char  latest_filing_version_id[40];
   char  license_filing_id[40];
   char  network_affiliation[80];
   char  nielson_dma_rank[80];
   int   primary_station;          /* facility ID of promasry station */
   char  satellite_tv_ind;         /* 'N' or 'Y' */
   char  service_code[4];          /* "AM", "FM", etc */
   char  station_type;             /* 'M' or 'N' */
   int   tsid_dtv;
   int   tsid_ntsc;
   int   tv_virtual_channel;
   char  eol;                      /* always '^' */
} lms_facility;
   
#endif
