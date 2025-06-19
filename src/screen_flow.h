#ifndef FLOW_H
#define FLOW_H

#include "screen.h"
#include "screen_history.h"
#include "screen_details.h"
#include "screen_info.h"
#include "data.h"

class FlowScreen : public Screen
{
public:
  FlowScreen();
  void update(const Data &data);
  void keyPressed(uint8_t key);
  void redrawElectrons();
private:
  lv_obj_t *m_pvImage;
  lv_obj_t *m_pvLabel;
  lv_obj_t *m_gridImage;
  lv_obj_t *m_gridLabel;
  lv_obj_t *m_inverterImage;
  lv_obj_t *m_mainLabel;
  lv_obj_t *m_todayLabel;
  lv_obj_t *m_totalLabel;
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
  HistoryScreen *m_historyScreen;
  DetailsScreen *m_detailsScreen;
  InfoScreen *m_infoScreen;
  void setPvStatus(int32_t status);
  void setGridStatus(int32_t status);
  void setInverterStatus(int32_t status);
  void setBatteryStatus(int32_t status);
  void setLoadStatus(int32_t status);
  void updateOpacity(lv_obj_t *obj, bool opaque);
  void doShow() override;
};

#endif