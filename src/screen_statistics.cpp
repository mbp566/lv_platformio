#include <cstdio>
#include <widgets/label/lv_label.h>
#include <widgets/image/lv_image.h>
#include "screen_statistics.h"

#include "data.h"

LV_IMAGE_DECLARE(pv);
LV_IMAGE_DECLARE(load);
LV_IMAGE_DECLARE(battery);

#define ALLTIME 0
#define THISWEEK 1
#define TODAY 2

StatisticsScreen::StatisticsScreen() :
  Screen(),
  m_timePeriod(0)
{
  m_titleLabel = lv_label_create(m_root);
  lv_obj_set_pos(m_titleLabel, 20, 20);
  lv_obj_set_style_text_font(m_titleLabel, &lv_font_montserrat_32, 0);

  lv_obj_t *panelImage = lv_image_create(m_root);
  lv_image_set_src(panelImage, &pv);
  lv_obj_set_pos(panelImage, 20, 60);
  lv_obj_set_size(panelImage, 80, 58);
  lv_image_set_scale(panelImage, 128);

  m_generatedLabel = lv_label_create(m_root);
  lv_obj_set_pos(m_generatedLabel, 100, 86);

  lv_obj_t *loadImage = lv_image_create(m_root);
  lv_image_set_src(loadImage, &load);
  lv_obj_set_pos(loadImage, 20, 130);
  lv_obj_set_size(loadImage, 80, 58);
  lv_image_set_scale(loadImage, 128);

  m_consumedLabel = lv_label_create(m_root);
  lv_obj_set_pos(m_consumedLabel, 100, 156);

  lv_obj_t *batteryImage = lv_image_create(m_root);
  lv_image_set_src(batteryImage, &battery);
  lv_obj_set_pos(batteryImage, 20, 200);
  lv_obj_set_size(batteryImage, 80, 58);
  lv_image_set_scale(batteryImage, 128);

  m_batteryLabel = lv_label_create(m_root);
  lv_obj_set_pos(m_batteryLabel, 100, 226);

  makeKeypad("All time", "This week", "Today", "Close");
}

void StatisticsScreen::update()
{
  char val[64];

  if (m_timePeriod == 0) {
    lv_label_set_text(m_titleLabel, "All time");

    sprintf(val, "%.1f kWh generated", data.statistics.pvTotalPowerGeneration);
    lv_label_set_text(m_generatedLabel, val);

    sprintf(val, "%.1f kWh consumed", data.statistics.loadTotalPowerConsumption);
    lv_label_set_text(m_consumedLabel, val);

    sprintf(val, "%d Ah charged, %d Ah discharged", data.statistics.batteryTotalCharge, data.statistics.batteryTotalDischarge);
    lv_label_set_text(m_batteryLabel, val);
  } else if (m_timePeriod == 1) {
    lv_label_set_text(m_titleLabel, "This week");

    sprintf(val, "%.1f kWh generated", data.statistics.pvWeeklyPowerGeneration);
    lv_label_set_text(m_generatedLabel, val);

    sprintf(val, "%.1f kWh consumed", data.statistics.loadWeeklyPowerConsumption);
    lv_label_set_text(m_consumedLabel, val);

    sprintf(val, "%d Ah charged, %d Ah discharged", data.statistics.batteryWeeklyCharge, data.statistics.batteryWeeklyDischarge);
    lv_label_set_text(m_batteryLabel, val);
  } else if (m_timePeriod == 2) {
    lv_label_set_text(m_titleLabel, "Today");

    sprintf(val, "%.1f kWh generated", data.statistics.pvDailyPowerGeneration);
    lv_label_set_text(m_generatedLabel, val);

    sprintf(val, "%.1f kWh consumed", data.statistics.loadDailyPowerConsumption);
    lv_label_set_text(m_consumedLabel, val);

    sprintf(val, "%d Ah charged, %d Ah discharged", data.statistics.batteryDailyCharge, data.statistics.batteryDailyDischarge);
    lv_label_set_text(m_batteryLabel, val);
  }
}

void StatisticsScreen::keyPressed(uint8_t key)
{
  if (key == KEY_1) {
    m_timePeriod = 0;
    update();
  } else if (key == KEY_2) {
    m_timePeriod = 1;
    update();
  } else if (key == KEY_3) {
    m_timePeriod = 2;
    update();
  } else if (key == KEY_4) {
    hide();
  }
}

void StatisticsScreen::doShow()
{
  lv_screen_load_anim(m_root, LV_SCR_LOAD_ANIM_OVER_TOP, 500, 0, false);
}