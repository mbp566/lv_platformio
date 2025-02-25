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

struct Settings
{
  uint8_t turboDuration;
  bool useElectricHeater;
  float electricHeaterMinTankTemperature;
  float electricHeaterMinBattery;
};

struct Info
{
  char version[32];
  char waterHeaterIP[16];
  int8_t waterHeaterRSSI;
  char remoteIP[16];
  uint8_t remoteRSSI;
  float batteryVoltage;
};

class Client
{
public:
  Client(uint8_t slaveId);
  Status *status();
  void updateStatus();
  Settings *settings();
  void loadSettings();
  void saveSettings(uint8_t turboDuration, bool useElectricHeater, float electricHeaterMinTankTemperature, float electricHeaterMinBattery);
  Info *info();
  void updateInfo();
  Status *history();
  unsigned int nextHistoryIndex();

private:
  uint8_t m_slaveId;
  Status m_status;
  Settings m_settings;
  Info m_info;
  Status m_history[144];
  unsigned int m_nextHistoryIndex;
};

#endif