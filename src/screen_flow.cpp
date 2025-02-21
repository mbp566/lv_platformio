#include <cstdio>
#include <ctime>
#include <widgets/image/lv_image.h>
#include <widgets/button/lv_button.h>
#include <widgets/buttonmatrix/lv_buttonmatrix.h>
#include <widgets/animimage/lv_animimage.h>
#include <widgets/label/lv_label.h>
#include "screen_flow.h"

LV_IMAGE_DECLARE(background);
LV_IMAGE_DECLARE(flow_background);
LV_IMAGE_DECLARE(flow_cold);
LV_IMAGE_DECLARE(flow_hot);
LV_IMAGE_DECLARE(heat_on);
LV_IMAGE_DECLARE(moon);
LV_IMAGE_DECLARE(sun);
LV_IMAGE_DECLARE(toolbar_battery);
LV_IMAGE_DECLARE(toolbar_wifi);

void updateFlowTimerCallback(lv_timer_t *timer)
{
  FlowScreen *flow = (FlowScreen*)lv_timer_get_user_data(timer);
  flow->updateFlow();
}

FlowScreen::FlowScreen(Client *client) :
  Screen(client)
{
  makeHeader("");
  lv_obj_set_height(m_header, 32);
  lv_obj_set_flex_flow(m_header, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(m_header, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
  lv_obj_set_flex_grow(m_title, 1);
  lv_obj_t *batteryImage = lv_image_create(m_header);
  lv_image_set_src(batteryImage, &toolbar_battery);
  m_batteryStatus = lv_label_create(m_header);
  lv_label_set_text(m_batteryStatus, "N/A");
  lv_obj_t *wifiImage = lv_image_create(m_header);
  lv_image_set_src(wifiImage, &toolbar_wifi);
  m_wifiStatus = lv_label_create(m_header);
  lv_label_set_text(m_wifiStatus, "N/A");

  m_flowBackground = lv_image_create(m_root);
  lv_image_set_src(m_flowBackground, &flow_background);
  lv_obj_set_pos(m_flowBackground, 133, 176);

  m_flowHot = lv_image_create(m_root);
  lv_image_set_src(m_flowHot, &flow_hot);

  m_flowCold = lv_image_create(m_root);
  lv_image_set_src(m_flowCold, &flow_cold);

  m_background = lv_image_create(m_root);
  lv_image_set_src(m_background, &background);
  lv_obj_set_pos(m_background, 0, 34);

  m_sun = lv_image_create(m_root);
  lv_image_set_src(m_sun, &sun);
  lv_obj_set_pos(m_sun, 39, 48);

  m_moon = lv_image_create(m_root);
  lv_image_set_src(m_moon, &moon);
  lv_obj_set_pos(m_moon, 56, 65);

  m_heatHigh = lv_image_create(m_root);
  lv_image_set_src(m_heatHigh, &heat_on);
  lv_obj_set_pos(m_heatHigh, 368, 67);

  m_heatLow = lv_image_create(m_root);
  lv_image_set_src(m_heatLow, &heat_on);
  lv_obj_set_pos(m_heatLow, 368, 180);

  m_tempLow = lv_label_create(m_root);
  lv_obj_set_pos(m_tempLow, 200, 217);
  lv_obj_set_width(m_tempLow, 115);
  lv_obj_set_height(m_tempLow, 40);
  lv_obj_set_style_text_color(m_tempLow, lv_color_hex(0x000000), LV_PART_MAIN);
  lv_obj_set_style_text_font(m_tempLow, &lv_font_montserrat_32, LV_PART_MAIN);

  m_tempHigh = lv_label_create(m_root);
  lv_obj_set_pos(m_tempHigh, 200, 48);
  lv_obj_set_width(m_tempHigh, 115);
  lv_obj_set_height(m_tempHigh, 40);
  lv_obj_set_style_text_color(m_tempHigh, lv_color_hex(0x000000), LV_PART_MAIN);
  lv_obj_set_style_text_font(m_tempHigh, &lv_font_montserrat_32, LV_PART_MAIN);

  m_tempPanel = lv_label_create(m_root);
  lv_obj_set_pos(m_tempPanel, 200, 127);
  lv_obj_set_width(m_tempPanel, 115);
  lv_obj_set_height(m_tempPanel, 40);
  lv_obj_set_style_text_color(m_tempPanel, lv_color_hex(0x000000), LV_PART_MAIN);
  lv_obj_set_style_text_font(m_tempPanel, &lv_font_montserrat_32, LV_PART_MAIN);

  makeKeypad("Turbo", "Settings", "History", "Information");

  lv_timer_create(updateFlowTimerCallback, 15, this);

  update();

  m_home = this;
  m_settingsScreen = new SettingsScreen(client); // important: do not create it in initializer
  m_historyScreen = new HistoryScreen(client); // important: do not create it in initializer
}

void FlowScreen::updateFlow()
{
  if (m_client->status()->pump)
  {
    int32_t hotleft = lv_obj_get_style_x(m_flowHot, LV_PART_MAIN);
    hotleft = (hotleft < FLOW_LEFT_STOP) ? hotleft + 1 : FLOW_LEFT_START;
    lv_obj_set_pos(m_flowHot, hotleft, FLOWHOT_TOP);
    int32_t coldleft = lv_obj_get_style_x(m_flowCold, LV_PART_MAIN);
    coldleft = (coldleft > FLOW_LEFT_START) ? coldleft - 1 : FLOW_LEFT_STOP;
    lv_obj_set_pos(m_flowCold, coldleft, FLOWCOLD_TOP);
  }
}

void FlowScreen::update()
{
  time_t rawTime(m_client->status()->time);
  struct tm *timeInfo = localtime(&rawTime);
  char timeString[128];
  strftime(timeString, 128, "%Y/%m/%d %H:%M", timeInfo);
  lv_label_set_text(m_title, timeString);

  unsigned int hour = (m_client->status()->time % 86400) / 3600;
  bool night = (hour > 18) || (hour < 6);
  if (night) {
    lv_obj_add_flag(m_sun, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(m_moon, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_bg_color(m_root, lv_color_hex(0x00327c), LV_PART_MAIN);
  } else {
    lv_obj_remove_flag(m_sun, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(m_moon, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_bg_color(m_root, lv_color_hex(0xffffff), LV_PART_MAIN);
  }
  lv_label_set_text_fmt(m_tempLow, "%.1f°C", m_client->status()->tempLow);
  lv_label_set_text_fmt(m_tempHigh, "%.1f°C", m_client->status()->tempHigh);
  lv_label_set_text_fmt(m_tempPanel, "%.1f°C", m_client->status()->tempPanel);
  if (m_client->status()->heat == HEAT_ON) {
    lv_obj_add_flag(m_heatHigh, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(m_heatLow, LV_OBJ_FLAG_HIDDEN);
  } else if (m_client->status()->heat == HEAT_TURBO) {
    lv_obj_add_flag(m_heatLow, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(m_heatHigh, LV_OBJ_FLAG_HIDDEN);
  } else { // HEAT_OFF
    lv_obj_add_flag(m_heatHigh, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(m_heatLow, LV_OBJ_FLAG_HIDDEN);
  }
  if (m_client->status()->pump) {
    lv_obj_set_pos(m_flowHot, FLOW_LEFT_STOP, FLOWHOT_TOP);
    lv_obj_set_pos(m_flowCold, FLOW_LEFT_START, FLOWCOLD_TOP);
    lv_obj_remove_flag(m_flowHot, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(m_flowCold, LV_OBJ_FLAG_HIDDEN);
  } else {
    lv_obj_add_flag(m_flowHot, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(m_flowCold, LV_OBJ_FLAG_HIDDEN);
  }
}

void FlowScreen::keyPressed(uint8_t key)
{
  if (key == KEY_1) {
    //m_client->startTurbo();
  } else if (key == KEY_2) {
    m_settingsScreen->show();
  } else if (key == KEY_3) {
    m_historyScreen->show();
  } else if (key == KEY_4) {
    //m_infoScreen->show();
  }
}

void FlowScreen::doShow()
{
  lv_screen_load_anim(m_root, LV_SCR_LOAD_ANIM_OUT_BOTTOM, 500, 0, false);
}
