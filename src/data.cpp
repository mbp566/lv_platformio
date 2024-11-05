#include "data.h"

PvData::PvData()
{
  m_voltage = 0.0;
  m_chargingCurrent = 0.0;
  m_chargingPower = 0.0;
}

float PvData::voltage()
{
  return m_voltage;
}

float PvData::chargingCurrent()
{
  return m_chargingCurrent;
}

float PvData::chargingPower()
{
  return m_chargingPower;
}

GridData::GridData()
{
  m_voltage = 0.0;
  m_current = 0.0;
  m_frequency = 0.0;
}

float GridData::voltage()
{
  return m_voltage;
}

float GridData::current()
{
  return m_current;
}

float GridData::frequency()
{
  return m_frequency;
}

InverterData::InverterData()
{
  m_busVoltage = 0.0;
  m_pvChargingCurrent = 0.0;
  m_mainsChargingCurrent = 0.0;
  m_inverterCurrent = 0.0;
  m_outputVoltage = 0.0;
  m_outputFrequency = 0.0;
}

BatteryData::BatteryData()
{
  m_voltage = 0.0;
  m_current = 0.0;
  m_soc = 0.0;
}

float BatteryData::voltage()
{
  return m_voltage;
}

float BatteryData::current()
{
  return m_current;
}

float BatteryData::soc()
{
  return m_soc;
}

LoadData::LoadData()
{
  m_current = 0.0;
  m_apparentPower = 0.0;
  m_loadRate = 0.0;
}

float LoadData::current()
{
  return m_current;
}

float LoadData::apparentPower()
{
  return m_apparentPower;
}

float LoadData::loadRate()
{
  return m_loadRate;
}

Data::Data()
{
  m_pv = new PvData();
  m_grid = new GridData();
  m_inverter = new InverterData();
  m_battery = new BatteryData();
  m_load = new LoadData();
}

PvData *Data::pv()
{
  return m_pv;
}

GridData *Data::grid()
{
  return m_grid;
}

InverterData *Data::inverter()
{
  return m_inverter;
}
BatteryData *Data::battery()
{
  return m_battery;
}

LoadData *Data::load()
{
  return m_load;
}

