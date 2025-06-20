#ifndef FLOW_H
#define FLOW_H

#include "screen.h"
#include "screen_statistics.h"
#include "screen_history.h"
#include "screen_details.h"
#include "screen_info.h"
#include "data.h"

class FlowScreen : public Screen
{
public:
  FlowScreen();
  void update() override; 
  void keyPressed(uint8_t key);
  void redrawElectrons();
private:
  lv_obj_t *m_pvImage;
  lv_obj_t *m_pvLabel;
  lv_obj_t *m_gridImage;
  lv_obj_t *m_gridLabel;
  lv_obj_t *m_inverterImage;
  lv_obj_t *m_mainLabel;
  lv_obj_t *m_batteryImage;
  lv_obj_t *m_batteryLabel;
  lv_obj_t *m_loadImage;
  lv_obj_t *m_loadLabel;
  lv_obj_t *m_batteryFlowImage;
  lv_obj_t *m_batteryElectronImage;
  lv_obj_t *m_gridFlowImage;
  lv_obj_t *m_gridElectronImage;
  lv_obj_t *m_pvFlowImage;
  lv_obj_t *m_pvElectronImage;
  lv_obj_t *m_loadFlowImage;
  lv_obj_t *m_loadElectronImage;
  uint32_t m_drawStep;
  StatisticsScreen *m_statisticsScreen;
  HistoryScreen *m_historyScreen;
  DetailsScreen *m_detailsScreen;
  InfoScreen *m_infoScreen;
  void enablePv(bool enable);
  void enableGrid(bool enable);
  void enableBattery(bool enable);
  void enableLoad(bool enable);
  void updateOpacity(lv_obj_t *obj, bool opaque);
  void doShow() override;
};

#endif