#include <cstdio>
#include <widgets/image/lv_image.h>
#include <widgets/button/lv_button.h>
#include <widgets/buttonmatrix/lv_buttonmatrix.h>
#include <widgets/animimage/lv_animimage.h>
#include <widgets/label/lv_label.h>
#include "data.h"
#include "style.h"
#include "flow.h"

LV_IMAGE_DECLARE(background);
LV_IMAGE_DECLARE(flow_background);
LV_IMAGE_DECLARE(flow_cold);
LV_IMAGE_DECLARE(flow_hot);
LV_IMAGE_DECLARE(heat_on);
LV_IMAGE_DECLARE(moon);
LV_IMAGE_DECLARE(sun);

void redrawTimerTick(lv_timer_t *timer)
{
  Flow *flow = (Flow*)lv_timer_get_user_data(timer);
  flow->update();
}

void updateTimerTick(lv_timer_t *timer)
{
  Flow *flow = (Flow *)lv_timer_get_user_data(timer);
  flow->redraw();
}

void turboButtonClicked(lv_event_t *event)
{
  Flow *flow = (Flow *)lv_event_get_user_data(event);
}

void settingsButtonClicked(lv_event_t *event)
{
  Flow *flow = (Flow *)lv_event_get_user_data(event);
}

void historyButtonClicked(lv_event_t *event)
{
  Flow *flow = (Flow *)lv_event_get_user_data(event);
}

void infoButtonClicked(lv_event_t *event)
{
  Flow *flow = (Flow *)lv_event_get_user_data(event);
}

Flow::Flow(Data *data) :
  Screen(),
  m_data(data),
  m_pump(false)
{
  m_flowBackground = lv_image_create(m_root);
  lv_image_set_src(m_flowBackground, &flow_background);
  lv_obj_set_pos(m_flowBackground, 133, 142);

  m_flowHot = lv_image_create(m_root);
  lv_image_set_src(m_flowHot, &flow_hot);
  lv_obj_add_flag(m_flowHot, LV_OBJ_FLAG_HIDDEN);

  m_flowCold = lv_image_create(m_root);
  lv_image_set_src(m_flowCold, &flow_cold);
  lv_obj_add_flag(m_flowCold, LV_OBJ_FLAG_HIDDEN);

  m_background = lv_image_create(m_root);
  lv_image_set_src(m_background, &background);
  lv_obj_set_pos(m_background, 0, 0);

  m_sun = lv_image_create(m_root);
  lv_image_set_src(m_sun, &sun);
  lv_obj_set_pos(m_sun, 39, 14);
  lv_obj_add_flag(m_sun, LV_OBJ_FLAG_HIDDEN);

  m_moon = lv_image_create(m_root);
  lv_image_set_src(m_moon, &moon);
  lv_obj_set_pos(m_moon, 56, 31);
  lv_obj_add_flag(m_moon, LV_OBJ_FLAG_HIDDEN);

  m_heatHigh = lv_image_create(m_root);
  lv_image_set_src(m_heatHigh, &heat_on);
  lv_obj_set_pos(m_heatHigh, 368, 33);
  lv_obj_add_flag(m_heatHigh, LV_OBJ_FLAG_HIDDEN);

  m_heatLow = lv_image_create(m_root);
  lv_image_set_src(m_heatLow, &heat_on);
  lv_obj_set_pos(m_heatLow, 368, 146);
  lv_obj_add_flag(m_heatLow, LV_OBJ_FLAG_HIDDEN);

  lv_obj_t *label;

  m_turboButton = lv_button_create(m_root);
  lv_obj_set_pos(m_turboButton, BUTTON1_LEFT, BUTTONS_TOP);
  lv_obj_set_width(m_turboButton, BUTTONS_WIDTH);
  lv_obj_set_height(m_turboButton, BUTTONS_HEIGHT);
  lv_obj_add_flag(m_turboButton, LV_OBJ_FLAG_CHECKABLE);
  lv_obj_add_event_cb(m_turboButton, turboButtonClicked, LV_EVENT_ALL, this);
  label = lv_label_create(m_turboButton);
  lv_label_set_text(label, "Turbo");
  lv_obj_center(label);

  m_settingsButton = lv_button_create(m_root);
  lv_obj_set_pos(m_settingsButton, BUTTON2_LEFT, BUTTONS_TOP);
  lv_obj_set_width(m_settingsButton, BUTTONS_WIDTH);
  lv_obj_set_height(m_settingsButton, BUTTONS_HEIGHT);
  lv_obj_add_event_cb(m_settingsButton, turboButtonClicked, LV_EVENT_ALL, this);
  label = lv_label_create(m_settingsButton);
  lv_label_set_text(label, "Settings");
  lv_obj_center(label);

  m_historyButton = lv_button_create(m_root);
  lv_obj_set_pos(m_historyButton, BUTTON3_LEFT, BUTTONS_TOP);
  lv_obj_set_width(m_historyButton, BUTTONS_WIDTH);
  lv_obj_set_height(m_historyButton, BUTTONS_HEIGHT);
  lv_obj_add_event_cb(m_historyButton, historyButtonClicked, LV_EVENT_ALL, this);
  label = lv_label_create(m_historyButton);
  lv_label_set_text(label, "History");
  lv_obj_center(label);

  m_infoButton = lv_button_create(m_root);
  lv_obj_set_pos(m_infoButton, BUTTON4_LEFT, BUTTONS_TOP);
  lv_obj_set_width(m_infoButton, BUTTONS_WIDTH);
  lv_obj_set_height(m_infoButton, BUTTONS_HEIGHT);
  lv_obj_add_event_cb(m_infoButton, infoButtonClicked, LV_EVENT_ALL, this);
  label = lv_label_create(m_infoButton);
  lv_label_set_text(label, "Information");
  lv_obj_center(label);

  setNight(false);
  setHeat(HEAT_OFF);
  setPump(false);

      m_drawStep = 0;
  lv_timer_create(redrawTimerTick, 15, this);
  lv_timer_create(updateTimerTick, 5000, this);
}

void Flow::show()
{
  Screen::showAnimated(LV_SCR_LOAD_ANIM_OUT_BOTTOM);
}

void Flow::update()
{
  m_data->update();
  redraw();
}

void Flow::redraw()
{
  if (m_pump) {
    int32_t hotleft = lv_obj_get_style_x(m_flowHot, LV_PART_MAIN);
    hotleft = (hotleft < FLOW_LEFT_STOP) ? hotleft + 1 : FLOW_LEFT_START;
    lv_obj_set_pos(m_flowHot, hotleft, FLOWHOT_TOP);
    int32_t coldleft = lv_obj_get_style_x(m_flowCold, LV_PART_MAIN);
    coldleft = (coldleft > FLOW_LEFT_START) ? coldleft - 1 : FLOW_LEFT_STOP;
    lv_obj_set_pos(m_flowCold, coldleft, FLOWCOLD_TOP);
  }
}

void Flow::setNight(bool night)
{
  if (night) {
    lv_obj_add_flag(m_sun, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(m_moon, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_bg_color(m_root, lv_color_hex(0x00327c), LV_PART_MAIN);
  } else {
    lv_obj_remove_flag(m_sun, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(m_moon, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_bg_color(m_root, lv_color_hex(0xffffff), LV_PART_MAIN);
  }
}

void Flow::setHeat(uint8_t heat)
{
  if (heat == HEAT_LOW)
  {
    lv_obj_add_flag(m_heatHigh, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(m_heatLow, LV_OBJ_FLAG_HIDDEN);
  } else if (heat == HEAT_TURBO) {
    lv_obj_add_flag(m_heatLow, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(m_heatHigh, LV_OBJ_FLAG_HIDDEN);
  } else { //HEAT_OFF
    lv_obj_add_flag(m_heatHigh, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(m_heatLow, LV_OBJ_FLAG_HIDDEN);
  }
}

void Flow::setPump(bool pump)
{
  m_pump = pump;
  if (m_pump) {
    lv_obj_set_pos(m_flowHot, FLOW_LEFT_STOP, FLOWHOT_TOP);
    lv_obj_set_pos(m_flowCold, FLOW_LEFT_START, FLOWCOLD_TOP);
    lv_obj_remove_flag(m_flowHot, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(m_flowCold, LV_OBJ_FLAG_HIDDEN);
  } else {
    lv_obj_add_flag(m_flowHot, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(m_flowCold, LV_OBJ_FLAG_HIDDEN);
  }
}