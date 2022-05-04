/*******************************************************************************
 * Size: 20 px
 * Bpp: 4
 * Opts: --no-compress --format lvgl --font C:\Users\asus\Desktop\digit.ttf -o C:\Users\asus\Desktop\my_font_icon_date.c --bpp 4 --size 20 --symbols SUN
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef MY_FONT_ICON_DATE
#define MY_FONT_ICON_DATE 1
#endif

#if MY_FONT_ICON_DATE

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+004E "N" */
    0x59, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x4b, 0xd6,
    0xcc, 0xcc, 0xcc, 0xb6, 0xe9, 0xbf, 0xd0, 0x0,
    0x0, 0x0, 0xff, 0x9b, 0xfe, 0x0, 0x0, 0x0,
    0xf, 0xf9, 0xbf, 0xe0, 0x0, 0x0, 0x0, 0xff,
    0x9b, 0xfe, 0x0, 0x0, 0x0, 0xf, 0xf9, 0xbc,
    0x50, 0x0, 0x0, 0x0, 0x6d, 0x93, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xbd, 0x70, 0x0, 0x0,
    0x0, 0x8e, 0x9b, 0xfe, 0x0, 0x0, 0x0, 0xf,
    0xf9, 0xbf, 0xe0, 0x0, 0x0, 0x0, 0xff, 0x9b,
    0xfe, 0x0, 0x0, 0x0, 0xf, 0xf9, 0xbf, 0xe0,
    0x0, 0x0, 0x0, 0xff, 0x9b, 0xf7, 0x0, 0x0,
    0x0, 0x8, 0xf9, 0x82, 0x0, 0x0, 0x0, 0x0,
    0x3, 0x70,

    /* U+0053 "S" */
    0x0, 0x6f, 0xff, 0xff, 0xff, 0xfb, 0x11, 0x97,
    0xcc, 0xcc, 0xcc, 0xc5, 0x0, 0xbf, 0xd0, 0x0,
    0x0, 0x0, 0x0, 0xb, 0xfe, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xbf, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0xb, 0xfd, 0x0, 0x0, 0x0, 0x0, 0x0, 0x98,
    0x9c, 0xdd, 0xdd, 0xdc, 0x71, 0x0, 0x5b, 0xff,
    0xff, 0xff, 0xfb, 0x84, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xdf, 0x90, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xf9, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x90,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xf9, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0x90, 0x6, 0xcc, 0xcc,
    0xcc, 0xb7, 0x90, 0x2c, 0xff, 0xff, 0xff, 0xff,
    0x50, 0x0,

    /* U+0055 "U" */
    0x83, 0x0, 0x0, 0x0, 0x0, 0x4, 0x7b, 0xf7,
    0x0, 0x0, 0x0, 0x9, 0xf9, 0xbf, 0xe0, 0x0,
    0x0, 0x0, 0xff, 0x9b, 0xfe, 0x0, 0x0, 0x0,
    0xf, 0xf9, 0xbf, 0xe0, 0x0, 0x0, 0x0, 0xff,
    0x9b, 0xfe, 0x0, 0x0, 0x0, 0xf, 0xf9, 0xbc,
    0x50, 0x0, 0x0, 0x0, 0x6d, 0x93, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xbd, 0x70, 0x0, 0x0,
    0x0, 0x8e, 0x9b, 0xfe, 0x0, 0x0, 0x0, 0xf,
    0xf9, 0xbf, 0xe0, 0x0, 0x0, 0x0, 0xff, 0x9b,
    0xfe, 0x0, 0x0, 0x0, 0xf, 0xf9, 0xbf, 0xd0,
    0x0, 0x0, 0x0, 0xff, 0x91, 0x96, 0xcc, 0xcc,
    0xcc, 0xb7, 0x91, 0x0, 0x6f, 0xff, 0xff, 0xff,
    0x50, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 238, .box_w = 13, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 98, .adv_w = 238, .box_w = 13, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 238, .box_w = 13, .box_h = 15, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x5, 0x7
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 78, .range_length = 8, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 3, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t my_font_icon_date = {
#else
lv_font_t my_font_icon_date = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0)
    .underline_position = 0,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if MY_FONT_ICON_DATE*/

