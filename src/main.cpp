/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "lvgl.h"
#include "app_hal.h"

#include "style.h"
#include "data.h"
#include "tabs.h"
#include "flow.h"

int main(void)
{
	lv_init();

	hal_setup();

  initStyles();

  Data *data = new Data();
  Tabs *tabs = new Tabs(lv_screen_active());
  Flow *flow = new Flow(tabs->tabFlow(), data);

  hal_loop();
}
