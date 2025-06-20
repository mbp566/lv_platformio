#include <widgets/label/lv_label.h>
#include "screen_details.h"

#include "data.h"

DetailsScreen::DetailsScreen() :
  ListScreen(LINE_COUNT)
{
  makeLine(PV_VOLTAGE, "PV voltage");
  makeLine(PV_CURRENT, "PV current");
  makeLine(PV_POWER, "PV power");

  makeLine(GRID_VOLTAGE, "Grid voltage");
  makeLine(GRID_CURRENT, "Grid current");
  makeLine(GRID_FREQUENCY, "Grid frequency");
  makeLine(GRID_CHARGE_CURRENT, "Grid charging current");

  makeLine(INVERTER_CURRENT, "Inverter current");
  makeLine(OUTPUT_FREQUENCY, "Output frequency");
  makeLine(TEMP_AC, "Temperature AC");
  makeLine(TEMP_DC, "Temperature DC");
  makeLine(TEMP_TR, "Temperature transformer");

  makeLine(BATTERY_VOLTAGE, "Battery voltage");
  makeLine(BATTERY_CURRENT, "Battery current");
  makeLine(BATTERY_SOC, "Battery level SOC");

  makeLine(LOAD_VOLTAGE, "Load voltage");
  makeLine(LOAD_CURRENT, "Load current");
  makeLine(LOAD_ACTIVE_POWER, "Load active power");
  makeLine(LOAD_APPARENT_POWER, "Load apparent power");
  makeLine(LOAD_RATE, "Load rate");
/*
  makeLine(PV_DAILY_POWER_GENERATION, "PV daily power generation");
  makeLine(LOAD_DAILY_POWER_CONSUMPTION, "Load daily power consumption");
  makeLine(BATTERY_DAILY_CHARGE, "Battery daily charge");
  makeLine(BATTERY_DAILY_DISCHARGE, "Battery daily discharge");

  makeLine(PV_WEEKLY_POWER_GENERATION, "PV weekly power generation");
  makeLine(LOAD_WEEKLY_POWER_CONSUMPTION, "Load weekly power consumption");
  makeLine(BATTERY_WEEKLY_CHARGE, "Battery weekly charge");
  makeLine(BATTERY_WEEKLY_DISCHARGE, "Battery weekly discharge");

  makeLine(PV_TOTAL_POWER_GENERATION, "PV total power generation");
  makeLine(LOAD_TOTAL_POWER_CONSUMPTION, "Load total power consumption");
  makeLine(BATTERY_TOTAL_CHARGE, "Battery total charge");
  makeLine(BATTERY_TOTAL_DISCHARGE, "Battery total discharge");
  makeLine(INVERTER_TOTAL_WORK_TIME, "Inverter total work time");
*/
}

void DetailsScreen::update()
{
  updateLine(PV_VOLTAGE, data.pv.voltage, "%.1f V");
  updateLine(PV_CURRENT, data.pv.current, "%.1f A");
  updateLine(PV_POWER, data.pv.power, "%d W");

  updateLine(GRID_VOLTAGE, data.grid.voltage, "%.1f V");
  updateLine(GRID_CURRENT, data.grid.current, "%.1f A");
  updateLine(GRID_FREQUENCY, data.grid.frequency, "%.2f Hz");
  updateLine(GRID_CHARGE_CURRENT, data.grid.chargeCurrent, "%.1f A");

  updateLine(INVERTER_CURRENT, data.inverter.current, "%.1f A");
  updateLine(OUTPUT_FREQUENCY, data.inverter.outputFrequency, "%.2f Hz");
  updateLine(TEMP_AC, data.inverter.temperatureAC, "%.1f °C");
  updateLine(TEMP_DC, data.inverter.temperatureDC, "%.1f °C");
  updateLine(TEMP_TR, data.inverter.temperatureTR, "%.1f °C");

  updateLine(BATTERY_VOLTAGE, data.battery.voltage, "%.1f V");
  updateLine(BATTERY_CURRENT, data.battery.current, "%.1f A");
  updateLine(BATTERY_SOC, data.battery.soc, "%d %%");

  updateLine(LOAD_VOLTAGE, data.load.voltage, "%.1f V");
  updateLine(LOAD_CURRENT, data.load.current, "%.1f A");
  updateLine(LOAD_ACTIVE_POWER, data.load.activePower, "%d A");
  updateLine(LOAD_APPARENT_POWER, data.load.apparentPower, "%d VA");
  updateLine(LOAD_RATE, data.load.loadRate, "%.0f %%");
/*
  updateLine(PV_DAILY_POWER_GENERATION, 0.0, "%.1f kWh");
  updateLine(LOAD_DAILY_POWER_CONSUMPTION, 0.0, "%.1f kWh");
  updateLine(BATTERY_DAILY_CHARGE, 0.0, "%.1f Ah");
  updateLine(BATTERY_DAILY_DISCHARGE, 0.0, "%.1f Ah");

  updateLine(PV_WEEKLY_POWER_GENERATION, 0.0, "%.1f kWh");
  updateLine(LOAD_WEEKLY_POWER_CONSUMPTION, 0.0, "%.1f kWh");
  updateLine(BATTERY_WEEKLY_CHARGE, 0.0, "%.1f Ah");
  updateLine(BATTERY_WEEKLY_DISCHARGE, 0.0, "%.1f Ah");

  updateLine(PV_TOTAL_POWER_GENERATION, 0.0, "%.1f kWh");
  updateLine(LOAD_TOTAL_POWER_CONSUMPTION, 0.0, "%.1f kWh");
  updateLine(BATTERY_TOTAL_CHARGE, 0.0, "%.1f Ah");
  updateLine(BATTERY_TOTAL_DISCHARGE, 0.0, "%.1f Ah");
  updateLine(INVERTER_TOTAL_WORK_TIME, 0.0, "%d hours");
  */
}

void DetailsScreen::doShow()
{
  lv_screen_load_anim(m_root, LV_SCR_LOAD_ANIM_OVER_TOP, 500, 0, false);
}