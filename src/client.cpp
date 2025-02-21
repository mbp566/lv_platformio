#include <math.h>
#include "client.h"

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
  m_settings(new Settings()),
  m_nextHistoryIndex(0)
{
  m_settings->m_turboDuration = 20;
  m_settings->m_useElectricHeater = true;
  m_settings->m_electricHeaterMinTankTemperature = 40.0f;
  m_settings->m_electricHeaterMinBattery = 50.0f;
  updateStatus();

  for (unsigned int i = 0; i < 144; i++) {
    float k = (float)i / 144.0f;
    m_history[i] = {
      1740160802 + (600 * i),
      k * 100.0f,
      20 + 20 * sin(2 * k),
      20 + 40 * sin(3 * k),
      (uint8_t)(i / 50),
      (i < 100)
    };
    m_nextHistoryIndex = 120;
  }
}

Status* Client::status()
{
  return &m_status;
}

void Client::updateStatus()
{
  m_status.time = 1740160802;
  m_status.tempLow = 15;
  m_status.tempHigh = 25;
  m_status.tempPanel = 40;
  m_status.heat = HEAT_OFF;
  m_status.pump = false;

  m_history[m_nextHistoryIndex] = m_status;
  m_nextHistoryIndex = (m_status.time % 1440) / 3 + 1;
}

Settings* Client::settings()
{
  return m_settings;
}

void Client::updateSettings()
{

}

Status* Client::history()
{
  return &m_history[0];
}

unsigned int Client::nextHistoryIndex()
{
  return m_nextHistoryIndex;
}
