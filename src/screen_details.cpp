#include <widgets/label/lv_label.h>
#include "screen_details.h"

DetailsScreen::DetailsScreen() :
  ListScreen(LINE_COUNT)
{
  makeLine(PV_VOLTAGE, "PV voltage");
  makeLine(PV_CURRENT, "PV charging current");
  makeLine(PV_POWER, "PV charging power");

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

  lv_obj_t *footer = lv_obj_create(m_root);
  lv_obj_add_style(footer, &lineStyle, LV_PART_MAIN);
  lv_obj_set_flex_flow(footer, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(footer, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_set_flex_grow(footer, 1);

  makeKeypad(NULL, NULL, NULL, "Close");
}

void DetailsScreen::update(const Data &data)
{
  updateLine(PV_VOLTAGE, 0.0, "%.1f V");
  updateLine(PV_CURRENT, 0.0, "%.1f A");
  updateLine(PV_POWER, 0.0, "%.0f W");

  updateLine(GRID_VOLTAGE, 0.0, "%.1f V");
  updateLine(GRID_CURRENT, 0.0, "%.1f A");
  updateLine(GRID_FREQUENCY, 0.0, "%.2f Hz");

  updateLine(GRID_CHARGE_CURRENT, 0.0, "%.1f A");
  updateLine(INVERTER_CURRENT, 0.0, "%.1f A");
  updateLine(OUTPUT_FREQUENCY, 0.0, "%.2f Hz");
  updateLine(TEMP_AC, 0.0, "%.1f °C");
  updateLine(TEMP_DC, 0.0, "%.1f °C");
  updateLine(TEMP_TR, 0.0, "%.1f °C");

  updateLine(BATTERY_VOLTAGE, 0.0, "%.1f V");
  updateLine(BATTERY_CURRENT, 0.0, "%.1f A");
  updateLine(BATTERY_SOC, 0.0, "%.0f %");

  updateLine(LOAD_VOLTAGE, 0.0, "%.1f V");
  updateLine(LOAD_CURRENT, 0.0, "%.1f A");
  updateLine(LOAD_ACTIVE_POWER, 0.0, "%.1f A");
  updateLine(LOAD_APPARENT_POWER, 0.0, "%.0f VA");
  updateLine(LOAD_RATE, 0.0, "%.0f %");

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
}

