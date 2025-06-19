#include <cstdio>
#include <widgets/image/lv_image.h>
#include <widgets/animimage/lv_animimage.h>
#include <widgets/label/lv_label.h>
#include <widgets/win/lv_win.h>
#include <misc/lv_types.h>
#include <draw/lv_draw.h>
#include "data.h"
#include "style.h"
#include "animations.h"
#include "screen_flow.h"

LV_IMAGE_DECLARE(battery);
LV_IMAGE_DECLARE(battery_flow);
LV_IMAGE_DECLARE(grid);
LV_IMAGE_DECLARE(grid_flow);
LV_IMAGE_DECLARE(inverter);
LV_IMAGE_DECLARE(pv);
LV_IMAGE_DECLARE(pv_flow);
LV_IMAGE_DECLARE(load);
LV_IMAGE_DECLARE(load_flow);
LV_IMAGE_DECLARE(spark0);
LV_IMAGE_DECLARE(spark1);
LV_IMAGE_DECLARE(spark2);
LV_IMAGE_DECLARE(spark3);
LV_IMAGE_DECLARE(spark4);

const lv_image_dsc_t *electronImages[5] = {
  &spark0,
  &spark1,
  &spark2,
  &spark3,
  &spark4
};

void timerCallback(lv_timer_t *timer)
{
  FlowScreen *flow = (FlowScreen*)lv_timer_get_user_data(timer);
  flow->redrawElectrons();
}

FlowScreen::FlowScreen() :
  Screen()
{
  lv_obj_set_style_margin_all(m_root, 0, LV_PART_MAIN);
  lv_obj_set_style_pad_all(m_root, 0, LV_PART_MAIN);

  // PV

  m_pvImage = lv_image_create(m_root);
  lv_image_set_src(m_pvImage, &pv);
  lv_obj_set_pos(m_pvImage, 0, 0);

  m_pvLabel = lv_label_create(m_root);
  lv_obj_set_pos(m_pvLabel, 77, 130);
  lv_obj_set_width(m_pvLabel, 128);
  lv_obj_set_style_text_align(m_pvLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);

  m_pvFlowImage = lv_image_create(m_root);
  lv_image_set_src(m_pvFlowImage, &pv_flow);
  lv_obj_set_pos(m_pvFlowImage, 74, 94);

  m_pvElectronImage = lv_animimg_create(m_root);
  lv_animimg_set_src(m_pvElectronImage, (const void **)electronImages, 5);
  lv_animimg_set_duration(m_pvElectronImage, 500);
  lv_animimg_set_repeat_count(m_pvElectronImage, LV_ANIM_REPEAT_INFINITE);
  lv_animimg_start(m_pvElectronImage);
  lv_obj_add_flag(m_pvElectronImage, LV_OBJ_FLAG_HIDDEN);

  // Grid

  m_gridImage = lv_image_create(m_root);
  lv_image_set_src(m_gridImage, &grid);
  lv_obj_set_pos(m_gridImage, 320, 0);

  m_gridLabel = lv_label_create(m_root);
  lv_obj_set_pos(m_gridLabel, 266, 130);
  lv_obj_set_width(m_gridLabel, 128);
  lv_obj_set_style_text_align(m_gridLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);

  m_gridFlowImage = lv_image_create(m_root);
  lv_image_set_src(m_gridFlowImage, &grid_flow);
  lv_obj_set_pos(m_gridFlowImage, 266, 94);

  m_gridElectronImage = lv_animimg_create(m_root);
  lv_animimg_set_src(m_gridElectronImage, (const void **)electronImages, 5);
  lv_animimg_set_duration(m_gridElectronImage, 500);
  lv_animimg_set_repeat_count(m_gridElectronImage, LV_ANIM_REPEAT_INFINITE);
  lv_animimg_start(m_gridElectronImage);
  lv_obj_add_flag(m_gridElectronImage, LV_OBJ_FLAG_HIDDEN);

  // Inverter

  m_inverterImage = lv_image_create(m_root);
  lv_image_set_src(m_inverterImage, &inverter);
  lv_obj_set_pos(m_inverterImage, 160, 81);

  m_mainLabel = lv_label_create(m_root);
  lv_obj_set_pos(m_mainLabel, 133, 60);
  lv_obj_set_width(m_mainLabel, 214);
  lv_obj_set_style_text_align(m_mainLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
  lv_obj_set_style_text_font(m_mainLabel, &lv_font_montserrat_32, 0);

  m_todayLabel = lv_label_create(m_root);
  lv_obj_set_pos(m_todayLabel, 133, 30);
  lv_obj_set_width(m_todayLabel, 214);
  lv_obj_set_style_text_align(m_todayLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);

  m_totalLabel = lv_label_create(m_root);
  lv_obj_set_pos(m_totalLabel, 133, 5);
  lv_obj_set_width(m_totalLabel, 214);
  lv_obj_set_style_text_align(m_totalLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);

  // Battery

  m_batteryImage = lv_image_create(m_root);
  lv_image_set_src(m_batteryImage, &battery);
  lv_obj_set_pos(m_batteryImage, 0, 162);

  m_batteryLabel = lv_label_create(m_root);
  lv_obj_set_pos(m_batteryLabel, 106, 212);
  lv_obj_set_width(m_batteryLabel, 123);
  lv_obj_set_style_text_align(m_batteryLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);

  m_batteryFlowImage = lv_image_create(m_root);
  lv_image_set_src(m_batteryFlowImage, &battery_flow);
  lv_obj_set_pos(m_batteryFlowImage, 106, 173);

  m_batteryElectronImage = lv_animimg_create(m_root);
  lv_animimg_set_src(m_batteryElectronImage, (const void **)electronImages, 5);
  lv_animimg_set_duration(m_batteryElectronImage, 500);
  lv_animimg_set_repeat_count(m_batteryElectronImage, LV_ANIM_REPEAT_INFINITE);
  lv_animimg_start(m_batteryElectronImage);
  lv_obj_add_flag(m_batteryElectronImage, LV_OBJ_FLAG_HIDDEN);

  // Load
  
  m_loadImage = lv_image_create(m_root);
  lv_image_set_src(m_loadImage, &load);
  lv_obj_set_pos(m_loadImage, 320, 162);

  m_loadLabel = lv_label_create(m_root);
  lv_obj_set_pos(m_loadLabel, 242, 212);
  lv_obj_set_width(m_loadLabel, 123);
  lv_obj_set_style_text_align(m_loadLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);

  m_loadFlowImage = lv_image_create(m_root);
  lv_image_set_src(m_loadFlowImage, &load_flow);
  lv_obj_set_pos(m_loadFlowImage, 240, 173);

  m_loadElectronImage = lv_animimg_create(m_root);
  lv_animimg_set_src(m_loadElectronImage, (const void **)electronImages, 5);
  lv_animimg_set_duration(m_loadElectronImage, 500);
  lv_animimg_set_repeat_count(m_loadElectronImage, LV_ANIM_REPEAT_INFINITE);
  lv_animimg_start(m_loadElectronImage);
  lv_obj_add_flag(m_loadElectronImage, LV_OBJ_FLAG_HIDDEN);

  makeKeypad("History", NULL, NULL, "Details");

  setPvStatus(1);
  setGridStatus(0);
  setInverterStatus(1);
  setBatteryStatus(-1);
  setLoadStatus(-1);

  m_home = this;

  m_drawStep = 0;

  lv_timer_create(timerCallback, 15, this);

  lv_screen_load(m_root);
}

void FlowScreen::update(const Data &data)
{
  lv_label_set_text_fmt(m_pvLabel, "%dW", data.pv.power);
  lv_label_set_text_fmt(m_gridLabel, "%.1fA", data.grid.current);
  lv_label_set_text_fmt(m_mainLabel, "%.1fV (%d%)", data.battery.voltage, data.battery.soc);
  lv_label_set_text_fmt(m_todayLabel, "Today: %.1fkWh", data.statistics.pvDailyPowerGeneration);
  lv_label_set_text_fmt(m_totalLabel, "Total: %.1fkWh", data.statistics.pvTotalPowerGeneration);
  lv_label_set_text_fmt(m_batteryLabel, "%.1fA", data.battery.current);
  lv_label_set_text_fmt(m_loadLabel, "%dW", data.load.activePower);
}

void FlowScreen::setPvStatus(int32_t status)
{
  updateOpacity(m_pvImage, status != 0);
  updateOpacity(m_pvFlowImage, status != 0);
}

void FlowScreen::setGridStatus(int32_t status)
{
  updateOpacity(m_gridImage, status != 0);
  updateOpacity(m_gridFlowImage, status != 0);
}

void FlowScreen::setInverterStatus(int32_t status)
{
  updateOpacity(m_inverterImage, status != 0);
}

void FlowScreen::setBatteryStatus(int32_t status)
{
  updateOpacity(m_batteryImage, status != 0);
  updateOpacity(m_batteryFlowImage, status != 0);
}

void FlowScreen::setLoadStatus(int32_t status)
{
  updateOpacity(m_loadImage, status != 0);
  updateOpacity(m_loadFlowImage, status != 0);
}

void FlowScreen::updateOpacity(lv_obj_t *obj, bool opaque)
{
  lv_obj_set_style_image_recolor(obj, lv_color_black(), LV_PART_MAIN);
  lv_obj_set_style_image_recolor_opa(obj, opaque ? LV_OPA_TRANSP : LV_OPA_50, LV_PART_MAIN);
}

void FlowScreen::redrawElectrons()
{
  if (!lv_obj_has_flag(m_pvElectronImage, LV_OBJ_FLAG_HIDDEN)) {
    uint32_t step = m_drawStep % pvElectronAnim.steps;
    lv_obj_set_pos(m_pvElectronImage, pvElectronAnim.positions[step].x, pvElectronAnim.positions[step].y);
  }
  if (!lv_obj_has_flag(m_gridElectronImage, LV_OBJ_FLAG_HIDDEN)) {
    uint32_t step = m_drawStep % gridElectronAnim.steps;
    lv_obj_set_pos(m_gridElectronImage, gridElectronAnim.positions[step].x, gridElectronAnim.positions[step].y);
  }
  if (!lv_obj_has_flag(m_batteryElectronImage, LV_OBJ_FLAG_HIDDEN)) {
    uint32_t step = m_drawStep % batteryElectronAnim.steps;
    lv_obj_set_pos(m_batteryElectronImage, batteryElectronAnim.positions[step].x, batteryElectronAnim.positions[step].y);
  }
  if (!lv_obj_has_flag(m_loadElectronImage, LV_OBJ_FLAG_HIDDEN)) {
    uint32_t step = m_drawStep % loadElectronAnim.steps;
    lv_obj_set_pos(m_loadElectronImage, loadElectronAnim.positions[step].x, loadElectronAnim.positions[step].y);
  }

  m_drawStep++;
}

void FlowScreen::keyPressed(uint8_t key)
{
  if (key == KEY_1) {
    // we are already on this screen
  } else if (key == KEY_2) {
    m_historyScreen->show();
  } else if (key == KEY_3) {
    m_detailsScreen->show();
  } else if (key == KEY_4) {
    m_infoScreen->show();
  }
}

void FlowScreen::doShow()
{
  lv_screen_load_anim(m_root, LV_SCR_LOAD_ANIM_OUT_BOTTOM, 500, 0, false);
}