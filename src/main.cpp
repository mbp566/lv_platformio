/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include <stdlib.h> 
#include "SDL2/SDL_timer.h"

#include "lvgl.h"
#include "app_hal.h"

#include "style.h"
#include "data.h"
#include "screen_flow.h"

    void
    randomizeData()
{
  data.pv.current *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.pv.voltage *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.pv.power *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);

  data.grid.current *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.grid.voltage *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.grid.chargeCurrent *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.grid.frequency *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);

  data.inverter.current *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.inverter.outputFrequency *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.inverter.temperatureAC *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.inverter.temperatureDC *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.inverter.temperatureTR *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);

  data.battery.current *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.battery.voltage *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.battery.soc *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);

  data.load.current *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.load.voltage *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.load.activePower *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.load.apparentPower *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.load.loadRate *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);

  data.statistics.pvDailyPowerGeneration *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.statistics.loadDailyPowerConsumption *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.statistics.batteryDailyCharge *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.statistics.batteryDailyDischarge *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.statistics.pvWeeklyPowerGeneration *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.statistics.loadWeeklyPowerConsumption *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.statistics.batteryWeeklyCharge *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.statistics.batteryWeeklyDischarge *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.statistics.pvTotalPowerGeneration *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.statistics.loadTotalPowerConsumption *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.statistics.batteryTotalCharge *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.statistics.batteryTotalDischarge *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
  data.statistics.inverterTotalWorkTime *= (1 + (float)rand() / (float)RAND_MAX * 0.1f - 0.05f);
}

int main(void)
{
	lv_init();

	hal_setup();

  initStyles();

  printf("Starting");

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

  Uint32 lastTick = SDL_GetTicks();
  Uint32 lastUpdate = SDL_GetTicks();
  while (1)
  {
    SDL_Delay(5);
    Uint32 current = SDL_GetTicks();

    if (current - lastUpdate > 2000) {
      randomizeData();
      flow->update();
      lastUpdate = current;
    }

    lv_tick_inc(current - lastTick); // Update the tick timer. Tick is new for LVGL 9
    lastTick = current;
    flow->redrawElectrons();
    lv_timer_handler(); // Update the UI-
  }
}
