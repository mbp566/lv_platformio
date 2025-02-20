#include "client.h"

Status::Status()
{
}

bool Status::night()
{
  return m_night;
}

float Status::tempLow()
{
  return m_tempLow;
}

float Status::tempHigh()
{
  return m_tempHigh;
}

float Status::tempPanel()
{
  return m_tempPanel;
}

uint8_t Status::heat()
{
  return m_heat;
}

bool Status::pump()
{
  return m_pump;
}

Settings::Settings()
{
}

uint8_t Settings::turboDuration()
{
  return m_turboDuration;
}

bool Settings::useElectricHeater()
{
  return m_useElectricHeater;
}

float Settings::electricHeaterMinTankTemperature()
{
  return m_electricHeaterMinTankTemperature;
}

float Settings::electricHeaterMinBattery()
{
  return m_electricHeaterMinBattery;
}

Client::Client(uint8_t slaveId) :
  m_slaveId(slaveId),
  m_status(new Status()),
  m_settings(new Settings())
{
  m_settings->m_turboDuration = 20;
  m_settings->m_useElectricHeater = true;
  m_settings->m_electricHeaterMinTankTemperature = 40;
  m_settings->m_electricHeaterMinBattery = 50;
  updateStatus();
}

Status* Client::status()
{
  return m_status;
}

void Client::updateStatus()
{
  m_status->m_night = false;
  m_status->m_tempLow = 15;
  m_status->m_tempHigh = 25;
  m_status->m_tempPanel = 40;
  m_status->m_heat = HEAT_OFF;
  m_status->m_pump = false; 
}

Settings *Client::settings()
{
  return m_settings;
}
