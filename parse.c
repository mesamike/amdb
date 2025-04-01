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
   strcpy(auth->app_uuid, p1);

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


void parse_fac(char *buffer, facility *fac)
{
   char *p1=buffer, *p2;

   /*  Callsign */
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->callsign, p1);
   
   /*  comm_city */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->comm_city, p1);

   /*  comm_state */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->comm_state, p1);

   /*  fac_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   fac->fac_id = atoi(p1);

   /*  fac_uuid */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->fac_uuid, p1);
   
   /*  filing_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->filing_id, p1);
   
   /*  fac_status */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->fac_status, p1);

   /*  freq */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   fac->fac_freq = atoi(p1);

   /*  service_code */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->service_code, p1);
}

void lms_parse_application_facility(char *buffer, appfac *app)
{
   char *p1=buffer, *p2;

   /* active_ind */
   *(p2 = strchr(p1, '|')) = 0;
   app->active_ind = *p1;

   /* afac_application_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(app->app_uuid, p1);

   /* afac_channel */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* afac_community_city */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(app->comm_city, p1);

   /* afac_community_state */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(app->comm_state, p1);

   /* afac_facility_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   app->fac_id = atoi(p1);

   /* afac_facility_record_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* afac_facility_type */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* afac_facility_type_change_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* afac_facility_zone_code */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* afac_license_filing_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* afac_primary_station_facility_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* afac_station_type */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* afac_tsid_dtv */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* afac_tsid_ntsc */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* afac_tv_virtual_channel */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* am_ant_mode_critical_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* am_ant_mode_daytime_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* am_ant_mode_nighttime_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* am_ant_mode_unlimited_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* am_filing_type */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* am_frequency */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(app->am_freq, p1);

/* we don't need anything beyond here */
#if 0
   /* am_region_2_class */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* atsc3_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* country_code */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* create_tsi */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* foreign_record_active */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* foreign_record_status */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* last_update_tsi */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* licensee_name */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* station_class_code */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

#endif
}

void parse_appfac(char *buffer, appfac *app)
{
   char *p1=buffer, *p2;

   /* facility_id */
   *(p2 = strchr(p1, '|')) = 0;
   app->fac_id = atol(p1);

   /* app_uuid */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(app->app_uuid,p1);

   /* am_frequency */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(app->am_freq, p1);

   /* comm_city */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(app->comm_city, p1);

   /* comm_state */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(app->comm_state, p1);
}

   
void lms_parse_facility(char *buffer, facility *fac)
{
   char *p1=buffer, *p2;

   /* 1: active_ind */
   *(p2 = strchr(p1, '|')) = 0;

   /* 2: atcs3_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 2.5 authorizing_act (FCC added this field 20231108 )*/
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 3: callsign */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->callsign, p1);

   /* 4: callsign_date */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->call_date, p1);

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
   strcpy(fac->fac_uuid, p1);

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
   strcpy(fac->filing_id, p1);

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

   /* 26: station_type */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 27: status_date */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(fac->status_date, p1);

/* we don't need anything beyond here */
#if 0
   /* 28: tsid_dtv */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 29: tsid_ntsc */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 30: virtual_channel */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* 31: eol */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
#endif
}

void lms_parse_app_am_antenna(char *buffer, lms_antenna *ant)
{
   char *p1=buffer, *p2;

   /* aapp_application_id */
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(ant->app_uuid, p1);

   /* active_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->active_ind = *p1;     /*Y or N */

   /* am_ant_mode_code */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->hours_operation = *p1;   /* D, N, U, or C */

   /* am_antenna_record_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* am_excitation_code*/
   p1 = p2+1;
   *(p2 = strchr(p1, '|' )) = 0;

   /* ant_input_power */
   p1 = p2+1;
   *(p2 = strchr(p1, '|' )) = 0;

   /* ant_monitor_manufacturer */
   p1 = p2+1;
   *(p2 = strchr(p1, '|' )) = 0;

   /* ant_monitor_type */
   p1 = p2+1;
   *(p2 = strchr(p1, '|' )) = 0;

   /* ant_sys_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* aug_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* aug_rms */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* create_ts */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* desc_sampling_system */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* dir_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* geo_coordinets */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* intl_tracking_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* last_update_ts */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* lat_deg */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->lat_deg = atoi(p1);

   /* lat_deg_nad27 */
   p1 = p2+1;
  *(p2 = strchr(p1, '|')) = 0;

   /* lat_dir */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->lat_dir = *p1;

   /* lat_dir_nad27 */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* lat_min */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->lat_min = atoi(p1);

   /* lat_min_nad27 */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* lat_sec */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->lat_sec = atof(p1);

   /* lat_sec_nad27 */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* long_deg */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->lon_deg = atoi(p1);

   /* long_deg_nad27 */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* long_dir */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->lon_dir = *p1;

   /* long_dir_nad27 */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

  /* long_min */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->lon_min = atoi(p1);

   /* long_min_nad27 */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* long_sec */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->lon_sec = atof(p1);

   /* long_sec_nad27 */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* measured_ant */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* overall_hgt_ag */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* overall_hgt_ag_obst */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* pattern_aug_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* power */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->power = atof(p1);

/* we don't need anything beyond here */
#if 0
   /* proof_performance */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* ref_antenna_record_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* rf_common_point  */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* sampling_system_cert_ind */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* site_elev */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* specified_q */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* standard_rms */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* theoretical_rms */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
#endif
}

void parse_ant(char *buffer, antenna *ant)
{
  char *p1=buffer, *p2;
  
   /* app_id */
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(ant->app_uuid, p1);

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

#if 0
   /* ant_mode */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(ant->ant_mode, p1);

   /* we don;t need the rest */
   /* am_dom_status */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->am_dom_status = *p1;
   
   /* eng_rec_type */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   ant->eng_rec_type = *p1);
#endif

}

void parse_lfv(char *buffer, lic_fil_ver *lfv)
{
   char *p1=buffer, *p2;

   /* license_filing_version */
   //*(p2 = strchr(p1, '|')) = 0;
   p2 = strchr(p1, '|');
   *p2 = 0;
   strcpy(lfv->filing_id, p1); 
   
   /* license_filing_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(lfv->filing_version, p1); 
} 





void lms_parse_license_filing_version(char *buffer, lms_lic_fil_ver *lfv)
{
   char *p1=buffer, *p2;

   /* active_ind */
   *(p2 = strchr(p1, '|')) = 0;
   lfv->active_ind = *p1;     /*Y or N */
   
   /* auth_type_code */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(lfv->auth_type_code, p1);
 
   /* creat_ts */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* current_status_code */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(lfv->status_code, p1);

   /* discriminator_code */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(lfv->discriminator_code, p1);

   /* filing_verion_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(lfv->filing_version_id, p1);

   /* last_update_ts */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* license_filing_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(lfv->filing_id, p1);

   /* original_auth_type_code */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* original_purpose_code */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* prev_filing_version_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(lfv->previous_filing_version_id, p1);

   /* processing_status */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* purpose_code */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(lfv->purpose_code, p1);

   /* ref_filing_version_id */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* service_code  */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(lfv->service_code, p1);

   /* status_date */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;

   /* sub_purpose_code */
   p1 = p2+1;
   *(p2 = strchr(p1, '|')) = 0;
   strcpy(lfv->sub_purpose_code, p1);
}


