#ifndef FLOW_H
#define FLOW_H

#include "data.h"

#if LV_FONT_MONTSERRAT_24 == 0
#error "LV_FONT_MONTSERRAT_24 is required. Enable it in lv_conf.h."
#endif

class DetailsWindow
{
public:
  DetailsWindow(char const *title);
  ~DetailsWindow();
  void addParameter(char const *name, float value, char const *format);
private:
  lv_obj_t *m_win;
  lv_obj_t *m_table;
  uint32_t m_nextLineIndex;
};

class Flow
{
public:
  Flow(lv_obj_t *parent, Data *data);
  void setPvStatus(int32_t status);
  void setGridStatus(int32_t status);
  void setInverterStatus(int32_t status);
  void setBatteryStatus(int32_t status);
  void setLoadStatus(int32_t status);
  void showPvDetails();
  void showGridDetails();
  void showInverterDetails();
  void showBatteryDetails();
  void showLoadDetails();
  void redrawElectrons();
private:
  Data *m_data;
  lv_obj_t *m_parent;
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
  void updateOpacity(lv_obj_t *obj, bool opaque);
};

#endif