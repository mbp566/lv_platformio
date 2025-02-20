#ifndef SCREENSETTINGS_H
#define SCREENSETTINGS_H

#include "screen.h"

class SettingsScreen : public Screen
{
public:
  SettingsScreen(Client *client);
  void keyPressed(uint8_t key);
private:
  using Line = struct {
    lv_obj_t *title;
    lv_obj_t *leftButton;
    lv_obj_t *value;
    lv_obj_t *rightButton;
  };
  Line m_lines[4];
  uint8_t m_currentControl;
  lv_obj_t *m_saveButton;
  lv_obj_t *m_cancelButton;
  uint8_t m_turboDuration;
  bool m_useElectricHeater;
  uint8_t m_electricHeaterMinTankTemperature;
  float m_electricHeaterMinBattery;
  void makeLine(uint8_t index, const char *title, const char *value = NULL);
  void disableCurrentControl();
  void enableControl(uint8_t index);
  void update();
  void doShow() override;
};

#endif