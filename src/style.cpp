#include <themes/lv_theme.h>
#include "style.h"

void initStyles()
{
#ifndef LV_FONT_MONTSERRAT_28
  LV_LOG_WARN("LV_FONT_MONTSERRAT_28 is required.");
#endif

#if LV_USE_THEME_DEFAULT
  lv_theme_default_init(NULL, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, &lv_font_montserrat_18);
#endif

  lv_obj_set_style_text_font(lv_screen_active(), &lv_font_montserrat_18, 0);
}

void clearStyles()
{
}
