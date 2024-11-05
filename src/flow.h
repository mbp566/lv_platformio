#ifndef FLOW_H
#define FLOW_H

#include "data.h"

class Flow
{
public:
  Flow(lv_obj_t *parent, Data *data);
  void showPvDetails();
  void showGridDetails();
  void showInverterDetails();
  void showBatteryDetails();
  void showLoadDetails();
private:
  lv_obj_t *m_parent;
  Data *m_data;
};

#endif