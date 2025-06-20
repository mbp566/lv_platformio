#ifndef STATISTICS_SCREEN_H
#define STATISTICS_SCREEN_H

#include <stdint.h>
#include <misc/lv_types.h>
#include "screen.h"

class StatisticsScreen : public Screen
{
public:
  StatisticsScreen();
  void keyPressed(uint8_t key);
  void update() override;
private:
  int m_timePeriod;
  lv_obj_t *m_titleLabel;
  lv_obj_t *m_generatedLabel;
  lv_obj_t *m_consumedLabel;
  lv_obj_t *m_batteryLabel;
  void doShow() override;
};

#endif