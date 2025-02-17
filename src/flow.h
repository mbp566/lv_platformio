#ifndef FLOW_H
#define FLOW_H

#include "screen.h"
#include "data.h"

#if LV_FONT_MONTSERRAT_24 == 0
#error "LV_FONT_MONTSERRAT_24 is required. Enable it in lv_conf.h."
#endif

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320
#define BACKGROUND_TOP 10
#define PANEL_TOP 
#define BUTTONS_TOP 250
#define BUTTON1_LEFT 8
#define BUTTON2_LEFT 126
#define BUTTON3_LEFT 244
#define BUTTON4_LEFT 362
#define BUTTONS_WIDTH 110
#define BUTTONS_HEIGHT 60
#define FLOWCOLD_TOP 159
#define FLOWHOT_TOP 144
#define FLOW_LEFT_START 78
#define FLOW_LEFT_STOP 140

class Flow : public Screen
{
public:
  Flow(Data *data);
  virtual void show();
  void update();
  void redraw();
private:
  Data *m_data;
  lv_obj_t *m_background;
  lv_obj_t *m_heatHigh;
  lv_obj_t *m_heatLow;
  lv_obj_t *m_sun;
  lv_obj_t *m_moon;
  lv_obj_t *m_flowBackground;
  lv_obj_t *m_flowHot;
  lv_obj_t *m_flowCold;
  lv_obj_t *m_turboButton;
  lv_obj_t *m_settingsButton;
  lv_obj_t *m_historyButton;
  lv_obj_t *m_infoButton;
  bool m_pump;
  uint32_t m_drawStep;
  void setNight(bool night);
  void setHeat(uint8_t heat);
  void setPump(bool pump);
};

#endif