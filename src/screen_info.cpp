#include <core/lv_obj.h>
#include <widgets/label/lv_label.h>
#include <widgets/image/lv_image.h>
#include "screen_info.h"

InfoScreen::InfoScreen() :
  Screen()
{
  lv_obj_set_flex_flow(m_root, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_style_pad_row(m_root, 0, LV_PART_MAIN);
  lv_obj_set_style_bg_color(m_root, LV_COLOR_MAKE(0x29, 0x28, 0x31), LV_PART_MAIN);

  makeLine(0, "Firmware version:");
  makeLine(1, "IP address:");

  lv_obj_t *footer = lv_obj_create(m_root);
  lv_obj_add_style(footer, &lineStyle, LV_PART_MAIN);
  lv_obj_set_flex_flow(footer, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(footer, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_set_flex_grow(footer, 1);

  makeKeypad(NULL, NULL, NULL, "Close");
}

void InfoScreen::keyPressed(uint8_t key)
{
  hide();
}

void InfoScreen::update(const Data &data)
{
}

void InfoScreen::makeLine(uint8_t index, const char *title)
{
  lv_obj_t *line;
  line = lv_obj_create(m_root);
  lv_obj_add_style(line, &lineStyle, LV_PART_MAIN);
  lv_obj_set_flex_flow(line, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(line, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  m_lines[index].value = lv_label_create(line);
  lv_label_set_text(m_lines[index].value, title);
  lv_obj_set_flex_grow(m_lines[index].value, 1);
  m_lines[index].value = lv_label_create(line);
}

void InfoScreen::doShow()
{
  lv_screen_load_anim(m_root, LV_SCR_LOAD_ANIM_OVER_TOP, 500, 0, false);
}