#ifndef DETAILS_SCREEN_H
#define DETAILS_SCREEN_H

#include <stdint.h>
#include <misc/lv_types.h>
#include "screen.h"
#include "data.h"

#define PV_VOLTAGE 0
#define PV_CURRENT 1
#define PV_POWER 2
#define GRID_VOLTAGE 3
#define GRID_CURRENT 4
#define GRID_FREQUENCY 5
#define GRID_CHARGE_CURRENT 6
#define INVERTER_CURRENT 7
#define OUTPUT_FREQUENCY 8
#define TEMP_AC 9
#define TEMP_DC 10
#define TEMP_TR 11
#define BATTERY_VOLTAGE 12
#define BATTERY_CURRENT 13
#define BATTERY_SOC 14
#define LOAD_VOLTAGE 15
#define LOAD_CURRENT 16
#define LOAD_ACTIVE_POWER 17
#define LOAD_APPARENT_POWER 18
#define LOAD_RATE 19
#define PV_DAILY_POWER_GENERATION 20
#define LOAD_DAILY_POWER_CONSUMPTION 21
#define BATTERY_DAILY_CHARGE 22
#define BATTERY_DAILY_DISCHARGE 23
#define PV_WEEKLY_POWER_GENERATION 24
#define LOAD_WEEKLY_POWER_CONSUMPTION 25
#define BATTERY_WEEKLY_CHARGE 26
#define BATTERY_WEEKLY_DISCHARGE 27
#define PV_TOTAL_POWER_GENERATION 28
#define LOAD_TOTAL_POWER_CONSUMPTION 29
#define BATTERY_TOTAL_CHARGE 30
#define BATTERY_TOTAL_DISCHARGE 31
#define INVERTER_TOTAL_WORK_TIME 32

#define LINE_COUNT 33

class DetailsScreen : public ListScreen
{
public:
  DetailsScreen();
  void update(const Data &data);
};

#endif