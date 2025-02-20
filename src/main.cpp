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
#include "client.h"
#include "screen_flow.h"

int main(void)
{
	lv_init();

	hal_setup();

  //initStyles();

  Client *client = new Client(1);
  FlowScreen *flow = new FlowScreen(client);
  flow->show();

  hal_loop();


}
