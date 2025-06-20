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

int main(void)
{
	lv_init();

	hal_setup();

  initStyles();

  data.pv.current = 28.4;
  data.pv.voltage = 52.1;
  data.pv.power = 1400;

  data.grid.current = 21;
  data.grid.voltage = 320.2;
  data.grid.chargeCurrent = 0;
  data.grid.frequency = 59.95;

  data.inverter.current = 28.4;
  data.inverter.outputFrequency = 59.95;
  data.inverter.temperatureAC = 32.1;
  data.inverter.temperatureDC = 32.1;
  data.inverter.temperatureTR = 32.1;

  data.battery.current = -28.4;
  data.battery.voltage = 52.1;
  data.battery.soc = 54;

  data.load.current = 28.4;
  data.load.voltage = 52.1;
  data.load.activePower = 1400;
  data.load.apparentPower = 1400;
  data.load.loadRate = 41;

  data.statistics.pvDailyPowerGeneration = 2.2;
  data.statistics.loadDailyPowerConsumption = 1.8;
  data.statistics.batteryDailyCharge = 150;
  data.statistics.batteryDailyDischarge = 130;
  data.statistics.pvWeeklyPowerGeneration = 12.5;
  data.statistics.loadWeeklyPowerConsumption = 10.5;
  data.statistics.batteryWeeklyCharge = 1500;
  data.statistics.batteryWeeklyDischarge = 1300;
  data.statistics.pvTotalPowerGeneration = 2354.5;
  data.statistics.loadTotalPowerConsumption = 2350.5;
  data.statistics.batteryTotalCharge = 25680;
  data.statistics.batteryTotalDischarge = 26850;
  data.statistics.inverterTotalWorkTime = 21500;

  FlowScreen *flow = new FlowScreen();
  flow->update();

  hal_loop();
}
