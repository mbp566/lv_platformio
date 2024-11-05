#include <widgets/tabview/lv_tabview.h>
#include "globals.h"
#include "tabs.h"


Tabs::Tabs(lv_obj_t *parent)
{

  m_tv = lv_tabview_create(parent);
  lv_tabview_set_tab_bar_size(m_tv, HEADER_HEIGHT);

  m_tabFlow = lv_tabview_add_tab(m_tv, "Flow");
  m_tabChart = lv_tabview_add_tab(m_tv, "Charts");
  m_tabDetails = lv_tabview_add_tab(m_tv, "Details");
}

lv_obj_t* Tabs::tabFlow()
{
  return m_tabFlow;
}

lv_obj_t *Tabs::tabChart()
{
  return m_tabChart;
}

lv_obj_t *Tabs::tabDetails()
{
  return m_tabDetails;
}
