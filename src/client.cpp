#include <math.h>
#include <string.h>
#include <stdio.h>
#include "client.h"

Client::Client(uint8_t slaveId) :
  m_slaveId(slaveId),
  m_nextHistoryIndex(0)
{
  updateStatus();
  loadSettings();
  updateInfo();

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
  }
  m_nextHistoryIndex = 120;
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
  return &m_settings;
}

void Client::loadSettings()
{
  m_settings.turboDuration = 20;
  m_settings.useElectricHeater = true;
  m_settings.electricHeaterMinTankTemperature = 40.0f;
  m_settings.electricHeaterMinBattery = 50.0f;
}

void Client::saveSettings(uint8_t turboDuration, bool useElectricHeater, float electricHeaterMinTankTemperature, float electricHeaterMinBattery)
{
  m_settings.turboDuration = turboDuration;
  m_settings.useElectricHeater = useElectricHeater;
  m_settings.electricHeaterMinTankTemperature = electricHeaterMinTankTemperature;
  m_settings.electricHeaterMinBattery = electricHeaterMinBattery;
}

    Info *Client::info()
{
  return &m_info;
}

void Client::updateInfo()
{
  sprintf_s(m_info.version, 32, "%d.%d build %d", 1, 0, 586);
  strcpy_s(m_info.waterHeaterIP, "192.168.0.2");
  m_info.waterHeaterRSSI = -67;
  strcpy_s(m_info.remoteIP, "192.168.0.3");
  m_info.remoteRSSI = -55;
  m_info.batteryVoltage = 49.8f;
}

Status* Client::history()
{
  return &m_history[0];
}

unsigned int Client::nextHistoryIndex()
{
  return m_nextHistoryIndex;
}
