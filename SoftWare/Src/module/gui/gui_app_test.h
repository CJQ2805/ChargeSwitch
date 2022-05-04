#ifndef __GUI_APP_TEST_H
#define __GUI_APP_TEST_H
#include "lv_port_disp.h"

void img_test(void);

void start_rise_img_anim(void);
void start_fall_img_anim(void);

void app_del_start(void);
void app_digital_clock_create(void);


typedef struct _LV_CLOCK_S
{
    lv_obj_t *location;
    lv_obj_t *weather;
    lv_obj_t *weather_name;
    lv_obj_t * temp_img;
    lv_obj_t * temp;
    lv_obj_t * humi_img;
    lv_obj_t * humi;

    lv_obj_t *clock_label;
    lv_obj_t *date_label;
    lv_obj_t *week_label;
}LV_CLOCK_S;


#endif

