#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "amdb.h"


void parse_auth(char *buffer, authorization *auth)
{
   char *p1=buffer, *p2;

   /* fac_id */
   *(p2 = strchr(p1, '|')) = 0;
   auth->fac_id = atol(p1);

   /* app_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   auth->app_id = atol(p1);

   /* freq */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   auth->freq = atof(p1); 

   /* call sign */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(auth->callsign, p1);

   /* state */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(auth->state, p1);
 
   /* city */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(auth->city, p1);

   /* hours of operation */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   auth->hours_operation = *p1;

   /* ant_mode */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(auth->ant_mode, p1);

   /* power */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   auth->power = atof(p1);

   /* latitude */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   auth->lat = atof(p1);

   /* longitude */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   auth->lon = atof(p1);

   /* status */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(auth->status, p1);
}

void parse_callhist(char *buffer, callsign_hist *ch)
{
   char *p1=buffer, *p2;


   /* begin date */
   *(p2 = strchr(p1, '|')) = 0;
   strcpy (ch->begin_date, p1);
 
   /* callsign */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy (ch->callsign, p1);

   /* hist_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ch->hist_id = atoi(p1);

   /* seq_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ch->seq_id = atoi(p1);

   /* fac_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ch->fac_id = atoi(p1);

   /* change_date */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(ch->change_date, p1);

}

void lms_parse_application(char *buffer, application *ap)
{
   char *p1=buffer, *p2;

   /* app_arn */
   *(p2 = strchr(p1, '|')) = 0;
   
   /* app_service */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(ap->app_service, p1);
   
   /* app_type */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(ap->app_type, p1);
   
   /* app_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ap->app_id = atoi(p1);
   
   /* assoc_facility_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   
  /* comm_city */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(ap->comm_city, p1);

   /* comm_county */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   
   /* comm_state */ 
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(ap->comm_state, p1);
   
   /* comm_zip1 */ 
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   
   /* comm_zip2 */ 
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   
   /* corresp_ind */ 
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   
   /* dtv_type */ 
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   
   /* fac_callsign */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   
   /* fac_frequency */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ap->fac_freq = atof(p1);
   
   /* facility_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ap->fac_id = atoi(p1);

/* we don't need anything below here */
#if 0
   /* file_prefix */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* fm */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* general_app_service */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* network_affil */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* paper_filled_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* sat_tv_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* shortform_app_arn */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* shortform_file_prefix */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* station_channel */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* eol */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
#endif
}

void parse_fac(char *buffer, facility *fac)
{
   char *p1=buffer, *p2;

   /*  fac_id */
   *(p2 = strchr(p1, '|')) = 0;
   fac->fac_id = atoi(p1);

   /*  Callsign */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->callsign, p1);
   
   /*  fac_status */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->fac_status, p1);

#if 0
   /*  comm_city */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->comm_city, p1);

   /*  comm_state */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->comm_state, p1);

   /*  freq */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   fac->fac_freq = atof(p1);

   /*  service_code */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->service_code, p1);
#endif

}


   
void lms_parse_facility(char *buffer, facility *fac)
{
   char *p1=buffer, *p2;

   /* 1: active_ind */
   *(p2 = strchr(p1, '|')) = 0;

   /* 2: atcs3_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 3: callsign */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->callsign, p1);

   /* 4: callsign_date */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 5: channel */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 6: chan_share_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 7: comm_city */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->comm_city, p1);

   /* 8: comm_state */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->comm_state, p1);
   
   /* 9: create_ts */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   
   /* 10: digital_op */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   
   /* 11: exp_date */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 12: fac_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   fac->fac_id = atoi(p1);

   /* 13: fac_status */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->fac_status, p1);

   /* 14: fac_type */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 15: fac_uuid */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 16: fac_zone_code */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 17: freq */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   fac->fac_freq = atof(p1);

   /* 18: last_update_ts */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 19: latest_filing_version_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 20: license_filing_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 21: network_affiliation */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 22: nielson_dma_rank */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 23: primary_station */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 24: satellite_tv_ind  */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 25: service_code */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->service_code, p1);

/* we don't need anything beyond here */
#if 0
   /* 26: station_type */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 27: tsid_dv */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 28: tsid_ntsc */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 29: virtual_channel */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 30: eol */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
#endif
}

void lms_parse_am_ant_sys(char *buffer, antenna *ant)
{
   char *p1=buffer, *p2;

   /* am_dom_status */
   *(p2 = strchr(p1, '|')) = 0;
   ant->am_dom_status = *p1;

   /* ant_dir_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* ant_mode */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(ant->ant_mode, p1);

   /* ant_sys_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* application_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->app_id = atoi(p1);

   /* aug_count */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* augmnted_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* bad_data_switch */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* biased_lat */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->lat =  atof(p1) - 90.0;

   /* biased_lon */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->lon =  180.0 - atof(p1);

   /* domestic_pattern */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* dummy_data_switch */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* efficiency_restricted */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* efficiency_theoretical */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* eng_record_type */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->eng_record_type = *p1;

   /* feed_circ_other */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* feed_circ_type */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* grandfathered_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* hours_operation */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->hours_operation = *p1;

   /* last_update_date */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* lat_deg */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* lat_dir */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* lat_min */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* lat_sec */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* lat_whole_secs */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* lon_deg */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* lon_dir */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* lon_min */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* lon_sec */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* lon_whole_secs */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* mainkey */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* power */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   if(strlen(p1))
      ant->power =  atof(p1);
   else
      ant->power = 0.0;

/* we don't need anything beyond here */
#if 0
   /* q_factor */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* q_factor_custom_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* rms_augmented */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* rms_standard */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* rms_theoretical */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* specified_hours_range */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* tower_count */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
#endif
}

void parse_app(char *buffer, application *app)
{
   char *p1=buffer, *p2;

   /* app_id */
   *(p2 = strchr(p1, '|')) = 0;
   app->app_id = atol(p1);
   
   /* facility_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   app->fac_id = atoi(p1);

   /* fac_frequency */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   app->fac_freq = atof(p1);

   /* comm_city */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(app->comm_city, p1);

   /* comm_state */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(app->comm_state, p1);
}

void parse_ant(char *buffer, antenna *ant)
{
  char *p1=buffer, *p2;
  
   /* app_id */
   *(p2 = strchr(p1, '|')) = 0;
   ant->app_id = atol(p1);

   /* hours_operation */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->hours_operation = *p1;

   /* power */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->power = atof(p1);
 
   /* lat */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->lat = strtod(p1, NULL);
 
   /* lon */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->lon = strtod(p1, NULL);

   /* ant_mode */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(ant->ant_mode, p1);

   /* we don;t need the rest */
#if 0
   /* am_dom_status */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->am_dom_status = *p1;
   
   /* eng_rec_type */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant-> eng_rec_type = *p1);
#endif

}

