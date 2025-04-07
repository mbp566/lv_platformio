#ifndef SCREENFLOW_H
#define SCREENFLOW_H

#include "screen.h"
#include "screen_settings.h"
#include "screen_history.h"
#include "screen_info.h"

#if LV_FONT_MONTSERRAT_24 == 0
#error "LV_FONT_MONTSERRAT_24 is required. Enable it in lv_conf.h."
#endif

#define BACKGROUND_TOP 10
#define PANEL_TOP 
#define FLOWCOLD_TOP 193
#define FLOWHOT_TOP 178
#define FLOW_LEFT_START 78
#define FLOW_LEFT_STOP 140

class FlowScreen : public Screen
{
public:
  FlowScreen(Client *client);
  void updateFlow();
  void update();
  void keyPressed(uint8_t key);
protected:
  void doShow() override;
private:
  lv_obj_t *m_batteryStatus;
  lv_obj_t *m_wifiStatus;
  lv_obj_t *m_panel;
  lv_obj_t *m_tank;
  lv_obj_t *m_highTemp;
  lv_obj_t *m_panelTemp;
  lv_obj_t *m_lowTemp;
  lv_obj_t *m_heatHigh;
  lv_obj_t *m_heatLow;
  lv_obj_t *m_sun;
  lv_obj_t *m_moon;
  lv_obj_t *m_flowBackground;
  lv_obj_t *m_flowHot;
  lv_obj_t *m_flowCold;
  lv_obj_t *m_tempLow;
  lv_obj_t *m_tempHigh;
  lv_obj_t *m_tempPanel;
  lv_obj_t *m_turboButton;
  lv_obj_t *m_settingsButton;
  lv_obj_t *m_historyButton;
  lv_obj_t *m_infoButton;
  SettingsScreen *m_settingsScreen;
  HistoryScreen *m_historyScreen;
  InfoScreen *m_infoScreen;
};

#endif