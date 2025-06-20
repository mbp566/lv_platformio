#ifndef DATA_H
#define DATA_H

#include <stdint.h>

typedef struct
{
  float voltage;
  float current;
  uint16_t power;
} PvData;

typedef struct
{
  float voltage;
  float current;
  float frequency;
  float chargeCurrent;
} GridData;

typedef struct
{
  float current;
  float outputFrequency;
  float temperatureAC;
  float temperatureDC;
  float temperatureTR;
} InverterData;

typedef struct
{
  float voltage;
  float current;
  uint16_t soc;
} BatteryData;

typedef struct
{
  float voltage;
  float current;
  uint16_t activePower;
  uint16_t apparentPower;
  float loadRate;
} LoadData;

typedef struct
{
  float pvDailyPowerGeneration;
  float loadDailyPowerConsumption;
  uint16_t batteryDailyCharge;
  uint16_t batteryDailyDischarge;
  float pvWeeklyPowerGeneration;
  float loadWeeklyPowerConsumption;
  uint16_t batteryWeeklyCharge;
  uint16_t batteryWeeklyDischarge;
  float pvTotalPowerGeneration;
  float loadTotalPowerConsumption;
  uint16_t batteryTotalCharge;
  uint16_t batteryTotalDischarge;
  float inverterTotalWorkTime;
} Statistics;

typedef struct
{
  PvData pv;
  GridData grid;
  InverterData inverter;
  BatteryData battery;
  LoadData load;
  Statistics statistics;
} Data;

extern Data data;

#endif