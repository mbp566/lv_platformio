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
#include "screen_flow.h"

Data data;

int main(void)
{
	lv_init();

	hal_setup();

  initStyles();

  FlowScreen *flow = new FlowScreen();
  flow->update(data);

  hal_loop();
}
