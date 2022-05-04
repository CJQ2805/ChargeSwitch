#include "gui_app_test.h"
#include "lv_port_disp.h"
#include "gui_app_anim.h"



LV_FONT_DECLARE(my_font_icon_num60);//申明字体 申明字体
LV_FONT_DECLARE(my_font_icon_num20);//申明字体 申明字体
LV_FONT_DECLARE(my_font_icon_30);//申明字体 申明字体
LV_FONT_DECLARE(my_font_icon_31);//申明字体 申明字体
#define MY_ICON_RUNING "\xEE\x98\xA6" //申明图标字体
#define MY_ICON_TEMP "\xEE\x9B\x9E" //申明图标字体 

static lv_obj_t *tstart_img; //定义开始背景图片img
static lv_obj_t *main_img; //定义主背景图片Img
static lv_obj_t *bat_img; //定义主背景电量图片Img
static lv_obj_t *charge_img; 

lv_obj_t *scr;
lv_obj_t *anim_cont; //太空人动图容器
lv_obj_t *pt_upscr_cont; //时间容器
lv_obj_t *time_cont; //时间容器
lv_obj_t *sec_cont; //秒容器
lv_obj_t *data_cont; //日期容器
lv_obj_t *week_cont; //星期容器


/* Clock & Date */
#define TIME_DATE_W                     320 
#define TIME_DATE_H                     80 
#define TIME_DATE_ALIGN_CENTER_X        0
#define TIME_DATE_ALIGN_CENTER_Y        80

#define CLOCK_WIDTH                     180 
#define CLOCK_HEIGHT                    60    
#define CLOCK_POS_X                     10
#define CLOCK_POS_Y                     10

#define DATE_WIDTH                      110 
#define DATE_HEIGHT                     60    
#define DATE_POS_X                      200
#define DATE_POS_Y                      10

#define CLOCK_LABEL_ALIGN_CENTER_X      0 
#define CLOCK_LABEL_ALIGN_CENTER_Y      0 
#define DATE_LABEL_IN_TOP_MID_X         0 
#define DATE_LABEL_IN_TOP_MID_Y         10 
#define WEEK_LABEL_IN_BOTTOM_MID_X      0 
#define WEEK_LABEL_IN_BOTTOM_MID_Y      -5 

LV_IMG_DECLARE(heart)

void img_test(void)
{
    scr = lv_scr_act();	
	lv_obj_set_style_local_bg_color(scr, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE); 	//设置背景颜色为白色
	tstart_img = lv_img_create(scr, NULL);
	lv_obj_set_size(tstart_img, 300, 300); //设置大小
	lv_obj_align(tstart_img, scr, LV_ALIGN_CENTER, 0, 0); //设置图片位置
	lv_img_set_src(tstart_img, &heart); //然后显示此图片
	lv_obj_set_style_local_image_opa(tstart_img, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_0); //图片透明
}


void gui_app_test(void)
{
//    lv_obj_t * obj1;
//    tv = lv_tabview_create(lv_scr_act(), NULL);
//    lv_obj_set_style_local_pad_left(tv, LV_TABVIEW_PART_TAB_BG, LV_STATE_DEFAULT, LV_HOR_RES / 2);	
//	
//    obj1 = lv_obj_create(lv_scr_act(), NULL);
//    lv_obj_set_size(obj1, 200, 100);
//            if(lv_theme_get_flags() & LV_THEME_MATERIAL_FLAG_DARK)
//                lv_switch_on(obj1, LV_ANIM_OFF);
//  lv_obj_set_event_cb(obj1, color_chg_event_cb);
//    lv_obj_set_pos(obj1, LV_DPX(10), LV_DPX(10));	
//  lv_obj_set_style(obj1, &lv_style_plain_color);
//	lv_obj_set_style_local_value_str(obj1, LV_SWITCH_PART_BG, LV_STATE_DEFAULT, "Dark");
//	lv_obj_set_style_local_value_align(obj1, LV_SWITCH_PART_BG, LV_STATE_DEFAULT, LV_ALIGN_OUT_RIGHT_TOP);
//	lv_obj_set_style_local_value_ofs_x(obj1, LV_SWITCH_PART_BG, LV_STATE_DEFAULT, LV_DPI/35);
//    lv_obj_align(obj1, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, 0, 0);

//    static const char * btns[] = {"Cancel", "Ok", ""};

//    lv_obj_t * m = lv_msgbox_create(lv_scr_act(), NULL);
//    lv_msgbox_add_btns(m, btns);
//    lv_obj_t * btnm = lv_msgbox_get_btnmatrix(m);
//    lv_btnmatrix_set_btn_ctrl(btnm, 1, LV_BTNMATRIX_CTRL_CHECK_STATE);
//    lv_obj_t * obj2;
//    obj2 = lv_obj_create(lv_scr_act(), obj1);
//    lv_obj_set_style(obj2, &lv_style_pretty_color);
//    lv_obj_align(obj2, NULL, LV_ALIGN_CENTER, 0, 0);

}



//开始图片的渐变动画
void start_rise_img_anim(void)
{
	lv_anim_t trise_anim;
	lv_anim_t tfall_anim;
	lv_anim_init(&trise_anim);

	lv_anim_set_var(&trise_anim, tstart_img); //动画对象

	lv_anim_set_exec_cb(&trise_anim, (lv_anim_exec_xcb_t)img_anim_exec_xcb); //渐变函数
	lv_anim_set_time(&trise_anim, lv_anim_speed_to_time(10, 0, 20));

	trise_anim.start = LV_OPA_TRANSP;		//起始值
	trise_anim.end = LV_OPA_COVER;			//结束值
	trise_anim.path.cb = lv_anim_path_linear; //线性
	trise_anim.playback_time = 0;				//回放时间设为0不执行动画回放
//	anim.trise_anim = 100000;
	lv_anim_start(&trise_anim);
}

//开始图片的渐变动画
void start_fall_img_anim(void)
{

	lv_anim_t tfall_anim;
	lv_anim_init(&tfall_anim);

	lv_anim_set_var(&tfall_anim, tstart_img); //动画对象

	lv_anim_set_exec_cb(&tfall_anim, (lv_anim_exec_xcb_t)img_anim_exec_xcb); //渐变函数
	lv_anim_set_time(&tfall_anim, lv_anim_speed_to_time(10, 0, 20));

	tfall_anim.start = LV_OPA_COVER;		//起始值
	tfall_anim.end = LV_OPA_TRANSP;			//结束值
	tfall_anim.path.cb = lv_anim_path_linear; //线性
	tfall_anim.playback_time = 0;				//回放时间设为0不执行动画回放
//	anim.trise_anim = 100000;
	lv_anim_start(&tfall_anim);
}





//删除开始图片
void app_del_start(void)
{
	lv_obj_del(tstart_img); //删除启动图片对象
}

static LV_CLOCK_S stClock;
lv_obj_t *pstWall;
static void clock_task(lv_task_t *t)
{
	static unsigned char count = 0;
    static unsigned int curr_id = 0;
    static const char *week[7] = { "日","一","二","三","四","五","六" };
	
    lv_label_set_text_fmt(stClock.clock_label, "%.2d:%.2d:%.2d", 1, 1, 1);
    lv_label_set_text_fmt(stClock.date_label, "%d.%.2d.%.2d", 2021, 
            12, 18);	

	lv_obj_align(stClock.clock_label, lv_obj_get_parent(stClock.clock_label),
		LV_ALIGN_CENTER, CLOCK_LABEL_ALIGN_CENTER_X, CLOCK_LABEL_ALIGN_CENTER_Y);
	lv_obj_align(stClock.date_label, lv_obj_get_parent(stClock.date_label),
		LV_ALIGN_IN_TOP_MID, DATE_LABEL_IN_TOP_MID_X, DATE_LABEL_IN_TOP_MID_Y);	
}





static lv_task_t *pstTask;
static lv_obj_t *people_img;	//定义主背景图片img

lv_obj_t* label_sec;
lv_obj_t* label_data;
lv_obj_t* label_week;
lv_obj_t* label_time;  //时间标签

void app_digital_clock_create(void)
{
	scr = lv_scr_act();  //获取屏幕对象

	main_img = lv_img_create(scr, NULL);

//	lv_obj_set_pos(main_img, -10, 5);		 //设置位置
//	lv_img_set_src(main_img, &main_back); //然后显示此图片
        /***********************创建上半屏幕控件****************************/
	pt_upscr_cont = lv_cont_create(scr, NULL);															  //创建时间容器
	lv_obj_set_pos(pt_upscr_cont, 0, 0);																  //设置容器位置
	lv_obj_set_size(pt_upscr_cont, 135, 120);															  //设置容器尺寸
	lv_obj_set_style_local_bg_opa(pt_upscr_cont, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_100);	  //设置背景透明
	lv_obj_set_style_local_border_opa(pt_upscr_cont, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_100); //设置边框透明
	lv_cont_set_layout(pt_upscr_cont, LV_LAYOUT_COLUMN_MID);												  //设置容器的布局方式: 开启自动布局
	lv_obj_set_style_local_pad_inner(pt_upscr_cont, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);			  //设置子对象之间的间距
	/***********************创建上半屏幕控件****************************/

//	    /***********************创建时间控件****************************/
//        time_cont = lv_cont_create(pt_upscr_cont, NULL);													  //创建时间容器
//        lv_obj_set_pos(time_cont, 0, 30);																  //设置容器位置
//        lv_obj_set_size(time_cont, 135, 30);															  //设置容器尺寸
//        lv_obj_set_style_local_bg_opa(time_cont, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_TRANSP);	  //设置背景透明
//        lv_obj_set_style_local_border_opa(time_cont, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_TRANSP); //设置边框透明
//        lv_cont_set_layout(time_cont, LV_LAYOUT_ROW_MID);												  //设置容器的布局方式: 开启自动布局
//        lv_obj_set_style_local_pad_inner(time_cont, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);			  //设置子对象之间的间距

//        label_time = lv_label_create(time_cont, NULL); 
//        lv_obj_align(label_time, time_cont, LV_ALIGN_IN_BOTTOM_LEFT, 0, 0);
//        lv_obj_set_style_local_text_font(label_time, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &my_font_icon_num60); //设置字体
//        lv_obj_set_style_local_text_color(label_time, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_RED);		  //设置颜色
//	/***********************创建时间控件****************************/
//	
//	
//		/***********************创建秒控件****************************/
//        sec_cont = lv_cont_create(pt_upscr_cont, NULL);															  //创建秒容器
//        lv_obj_set_pos(sec_cont, 100, 70);																  //设置容器位置
//        lv_obj_set_size(sec_cont, 50, 30);															  //设置容器尺寸
//        lv_obj_set_style_local_bg_opa(sec_cont, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_TRANSP);	  //设置背景透明
//        lv_obj_set_style_local_border_opa(sec_cont, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_TRANSP); //设置边框透明
//        lv_cont_set_layout(sec_cont, LV_LAYOUT_ROW_MID);												  //设置容器的布局方式: 开启自动布局
//        lv_obj_set_style_local_pad_inner(sec_cont, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);			  //设置子对象之间的间距

//        label_sec = lv_label_create(sec_cont, NULL); //创建秒label
//        lv_obj_align(label_sec, NULL, LV_ALIGN_CENTER, 100, 0);
//        lv_obj_set_style_local_text_font(label_sec, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &my_font_icon_num20); //设置字体
//        lv_obj_set_style_local_text_color(label_sec, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_RED);		  //设置颜色

//	/***********************创建秒控件****************************/
//	
//	
//	/***********************创建日期控件****************************/
//        data_cont = lv_cont_create(pt_upscr_cont, NULL);															  //创建日期容器
//        lv_obj_set_pos(data_cont, 0, 70);																  //设置容器位置
//        lv_obj_set_size(data_cont, 90, 30);															  //设置容器尺寸
//        lv_obj_set_style_local_bg_opa(data_cont, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_TRANSP);	  //设置背景透明
//        lv_obj_set_style_local_border_opa(data_cont, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_TRANSP); //设置边框透明
//        lv_cont_set_layout(data_cont, LV_LAYOUT_ROW_MID);												  //设置容器的布局方式: 开启自动布局
//        lv_obj_set_style_local_pad_inner(data_cont, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);			  //设置子对象之间的间距

//        label_data = lv_label_create(data_cont, NULL); //创建秒label
//        lv_obj_align(label_data, NULL, LV_ALIGN_CENTER, 100, 0);
//        lv_obj_set_style_local_text_font(label_data, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &my_font_icon_num20); //设置字体
//        lv_obj_set_style_local_text_color(label_data, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_RED);		  //设置颜色

//	/***********************创建日期控件****************************/
//	
//	
//	/***********************创建星期控件****************************/    
//        week_cont = lv_cont_create(pt_upscr_cont, NULL);															  //创建日期容器
//        lv_obj_set_pos(week_cont, 0, 0);																  //设置容器位置
//        lv_obj_set_size(week_cont, 135, 30);															  //设置容器尺寸
//        lv_obj_set_style_local_bg_opa(week_cont, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_TRANSP);	  //设置背景透明
//        lv_obj_set_style_local_border_opa(week_cont, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_TRANSP); //设置边框透明
//        lv_cont_set_layout(week_cont, LV_LAYOUT_OFF);												  //设置容器的布局方式: 开启自动布局
//        lv_obj_set_style_local_pad_inner(week_cont, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);			  //设置子对象之间的间距

//        label_week = lv_label_create(week_cont, NULL); //创建秒label
//        lv_obj_align(label_week, week_cont, LV_ALIGN_IN_TOP_LEFT, 0, 0);  //label 的位置定位
//        lv_obj_set_style_local_text_font(label_week, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16); //设置字体
//        lv_obj_set_style_local_text_color(label_week, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK);		  //设置颜色

// 	/***********************创建星期控件****************************/
//	
//	
}


/**
//	create time clock 
//*/
//void app_digital_clock_create(void)
//{
//	static lv_style_t time_style;
//	static lv_style_t clock_style;
//	static lv_style_t date_style; 
//    static lv_style_t clock_label_style;	
//    static lv_style_t date_label_style;
//	
//	pstWall = lv_img_create(lv_scr_act(), NULL);	
//	lv_style_init(&time_style);
//    lv_style_set_radius(&time_style, LV_STATE_DEFAULT, 0);
//    lv_style_set_bg_opa(&time_style, LV_STATE_DEFAULT, LV_OPA_20);
//    lv_style_set_border_width(&time_style, LV_STATE_DEFAULT, 0);
//    lv_style_set_bg_color(&time_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);

//    lv_style_init(&clock_style);
//    lv_style_set_bg_opa(&clock_style, LV_STATE_DEFAULT, LV_OPA_20);
//    lv_style_set_border_width(&clock_style, LV_STATE_DEFAULT, 0);
//    lv_style_set_clip_corner(&clock_style, 0, true);
//    lv_style_set_radius(&clock_style, 0, 8);
//    lv_style_set_bg_color(&clock_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);

//    lv_style_init(&date_style);
//    lv_style_copy(&date_style, &clock_style);
//	
//	/* Clock font */
//    lv_style_init(&clock_label_style);
//    lv_style_set_text_color(&clock_label_style, LV_STATE_DEFAULT, LV_COLOR_YELLOW);
//    lv_style_set_text_font(&clock_label_style, LV_STATE_DEFAULT, &lv_font_montserrat_32);
//    lv_style_set_text_opa(&clock_label_style, LV_STATE_DEFAULT, LV_OPA_COVER);
//    lv_style_set_bg_opa(&clock_label_style, LV_STATE_DEFAULT, LV_OPA_100);

//	/* Date font */
//    lv_style_init(&date_label_style);
//    lv_style_copy(&date_label_style, &clock_label_style);
//    lv_style_set_text_color(&date_label_style, LV_STATE_DEFAULT, LV_COLOR_RED);
//    lv_style_set_text_font(&date_label_style, LV_STATE_DEFAULT, &lv_font_montserrat_16);	
//	
//	
//	/* Time & Date */
//	lv_obj_t *time_obj = lv_obj_create(pstWall, NULL);
//	lv_obj_set_click(time_obj, false);
//	lv_obj_set_size(time_obj, TIME_DATE_W, TIME_DATE_H);
//	lv_obj_align(time_obj, pstWall, LV_ALIGN_CENTER, TIME_DATE_ALIGN_CENTER_X, TIME_DATE_ALIGN_CENTER_Y);
//	lv_obj_add_style(time_obj, LV_OBJ_PART_MAIN, &time_style);

//    /*Clock display*/
//    lv_obj_t *clock_obj = lv_obj_create(time_obj, NULL);
//    lv_obj_set_size(clock_obj, CLOCK_WIDTH, CLOCK_HEIGHT);
//    lv_obj_set_pos(clock_obj, CLOCK_POS_X, CLOCK_POS_Y);
//    lv_obj_add_style(clock_obj, LV_OBJ_PART_MAIN, &clock_style);
//	
//    stClock.clock_label = lv_label_create(clock_obj, NULL);
//    lv_obj_add_style(stClock.clock_label, LV_LABEL_PART_MAIN, &clock_label_style);

//    /*Date display*/
//    lv_obj_t *date_obj = lv_obj_create(time_obj, NULL);
//    lv_obj_set_size(date_obj, DATE_WIDTH, DATE_HEIGHT);
//    lv_obj_set_pos(date_obj, DATE_POS_X, DATE_POS_Y);
//    lv_obj_add_style(date_obj, LV_OBJ_PART_MAIN, &date_style);

//    stClock.date_label = lv_label_create(date_obj, NULL);
//    lv_obj_add_style(stClock.date_label, LV_LABEL_PART_MAIN, &date_label_style);
//	
////    /*Week display*/
////    stClock.week_label = lv_label_create(date_obj, NULL);
////    lv_obj_add_style(stClock.week_label, LV_LABEL_PART_MAIN, &week_lable_style);

//	  lv_obj_align(stClock.clock_label, clock_obj, LV_ALIGN_CENTER, CLOCK_LABEL_ALIGN_CENTER_X, CLOCK_LABEL_ALIGN_CENTER_Y);
//	  lv_obj_align(stClock.date_label, date_obj, LV_ALIGN_CENTER, DATE_LABEL_IN_TOP_MID_X, DATE_LABEL_IN_TOP_MID_Y);
////    lv_obj_align(stClock.week_label, date_obj, LV_ALIGN_IN_BOTTOM_MID, WEEK_LABEL_IN_BOTTOM_MID_X, WEEK_LABEL_IN_BOTTOM_MID_Y);

//      pstTask = lv_task_create(clock_task, 200, LV_TASK_PRIO_MID, NULL);		
//} 