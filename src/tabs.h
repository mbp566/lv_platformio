#ifndef TABS_H
#define TABS_H

#include <misc/lv_types.h>
#include "data.h"

class Tabs
{
public:
  Tabs(lv_obj_t *parent);
  lv_obj_t *tabFlow();
  lv_obj_t *tabChart();
  lv_obj_t *tabDetails();
private:
  lv_obj_t *m_tv;
  lv_obj_t *m_tabFlow;
  lv_obj_t *m_tabChart;
  lv_obj_t *m_tabDetails;
};

#endif