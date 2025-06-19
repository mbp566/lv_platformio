#ifndef DATA_H
#define DATA_H

typedef struct
{
  float voltage;
  float current;
  float power;
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
  float soc;
} BatteryData;

typedef struct
{
  float voltage;
  float current;
  float activePower;
  float apparentPower;
  float loadRate;
} LoadData;

typedef struct
{
  float pvDailyPowerGeneration;
  float loadDailyPowerConsumption;
  float batteryDailyCharge;
  float batteryDailyDischarge;
  float pvWeeklyPowerGeneration;
  float loadWeeklyPowerConsumption;
  float batteryWeeklyCharge;
  float batteryWeeklyDischarge;
  float pvTotalPowerGeneration;
  float loadTotalPowerConsumption;
  float batteryTotalCharge;
  float batteryTotalDischarge;
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

#endif