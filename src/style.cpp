#include <themes/lv_theme.h>
#include "style.h"

void initStyles()
{
#ifndef LV_FONT_MONTSERRAT_24
  LV_LOG_WARN("LV_FONT_MONTSERRAT_24 is not enabled for the widgets demo. Using LV_FONT_DEFAULT instead.");
#endif

#if LV_USE_THEME_DEFAULT
  lv_theme_default_init(NULL, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
#endif

  lv_obj_set_style_text_font(lv_screen_active(), LV_FONT_DEFAULT, 0);
}

void clearStyles()
{
}
