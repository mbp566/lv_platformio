#ifndef DATA_H
#define DATA_H

class PvData
{
public:
  PvData();
  float voltage();
  float chargingCurrent();
  float chargingPower();

private:
  float m_voltage;
  float m_chargingCurrent;
  float m_chargingPower;
};

class GridData
{
public:
  GridData();
  float voltage();
  float current();
  float frequency();

private:
  float m_voltage;
  float m_current;
  float m_frequency;
};

class InverterData
{
public:
  InverterData();
  void update();
  float busVoltage();
  float pvChargingCurrent();
  float mainsChargingCurrent();
  float inverterCurrent();
  float outputVoltage();
  float outputFrequency();

private:
  float m_busVoltage;
  float m_pvChargingCurrent;
  float m_mainsChargingCurrent;
  float m_inverterCurrent;
  float m_outputVoltage;
  float m_outputFrequency;
};

class BatteryData
{
public:
  BatteryData();
  float voltage();
  float current();
  float soc();

private:
  float m_voltage;
  float m_current;
  float m_soc;
};

class LoadData
{
public:
  LoadData();
  float current();
  float apparentPower();
  float loadRate();

private:
  float m_current;
  float m_apparentPower;
  float m_loadRate;
};

class Data
{
  public:
    Data();
    PvData *pv();
    GridData *grid();
    InverterData *inverter();
    BatteryData *battery();
    LoadData *load();
  private:
    PvData *m_pv;
    GridData *m_grid;
    InverterData *m_inverter;
    BatteryData *m_battery;
    LoadData *m_load;
};

#endif