#ifndef STATUS_H
#define STATUS_H

#include <stdint.h>

#define HEAT_OFF 0
#define HEAT_ON 1
#define HEAT_TURBO 2

struct Status
{
  unsigned int time;
  float tempLow;
  float tempHigh;
  float tempPanel;
  uint8_t heat;
  bool pump;
};

class Settings
{
public:
  Settings();
  uint8_t turboDuration();
  bool useElectricHeater();
  float electricHeaterMinTankTemperature();
  float electricHeaterMinBattery();
private:
  uint8_t m_turboDuration;
  bool m_useElectricHeater;
  uint8_t m_electricHeaterMinTankTemperature;
  float m_electricHeaterMinBattery;
  friend class Client;
};

class Client
{
public:
  Client(uint8_t slaveId);
  Status *status();
  void updateStatus();
  Settings *settings();
  void updateSettings();
  Status *history();
  unsigned int nextHistoryIndex();

private:
  uint8_t m_slaveId;
  Status m_status;
  Settings *m_settings;
  Status m_history[144];
  unsigned int m_nextHistoryIndex;
};

#endif