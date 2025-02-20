#include <core/lv_obj.h>
#include <widgets/label/lv_label.h>
#include <widgets/button/lv_button.h>
#include <widgets/image/lv_image.h>
#include "screen_settings.h"

LV_IMAGE_DECLARE(left);
LV_IMAGE_DECLARE(right);

SettingsScreen::SettingsScreen(Client *client) :
  Screen(client),
  m_currentControl(0)
{
  lv_obj_set_flex_flow(m_root, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_style_pad_row(m_root, 0, LV_PART_MAIN);
  lv_obj_set_style_bg_color(m_root, LV_COLOR_MAKE(0x29, 0x28, 0x31), LV_PART_MAIN);

  makeHeader("Settings");

  makeLine(0, "Turbo duration:", "");
  makeLine(1, "Electric heater:", "");
  makeLine(2, "Minimum water temperature:", "");
  makeLine(3, "Minimum battery voltage:", "");

  lv_obj_t *footer = lv_obj_create(m_root);
  lv_obj_add_style(footer, &lineStyle, LV_PART_MAIN);
  lv_obj_set_flex_flow(footer, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(footer, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_set_flex_grow(footer, 1);

  m_saveButton = lv_button_create(footer);
  lv_obj_set_style_height(m_saveButton, LINE_HEIGHT, LV_PART_MAIN);
  lv_obj_set_style_opa(m_saveButton, LV_OPA_30, LV_PART_MAIN);
  lv_obj_t *saveLabel = lv_label_create(m_saveButton);
  lv_label_set_text(saveLabel, "Save");
  lv_obj_center(saveLabel);

  m_cancelButton = lv_button_create(footer);
  lv_obj_set_style_height(m_cancelButton, LINE_HEIGHT, LV_PART_MAIN);
  lv_obj_set_style_opa(m_cancelButton, LV_OPA_30, LV_PART_MAIN);
  lv_obj_t *cancelLabel = lv_label_create(m_cancelButton);
  lv_label_set_text(cancelLabel, "Cancel");
  lv_obj_center(cancelLabel);

  makeKeypad(NULL, "Next", "<", ">");
}

void SettingsScreen::keyPressed(uint8_t key)
{
  disableCurrentControl();
  if ((key == KEY_2) && (m_currentControl < 5)) {
    enableControl(m_currentControl + 1);
  } else if ((key == KEY_1) && (m_currentControl > 0)) {
    enableControl(m_currentControl - 1);
  } else if (key == KEY_3) {
    if ((m_currentControl == 0) && (m_turboDuration > 0)) {
      m_turboDuration--; update();
    } else if (m_currentControl == 1) {
      m_useElectricHeater = ~m_useElectricHeater; update();
    } else if ((m_currentControl == 2) && (m_electricHeaterMinTankTemperature > 0)) {
      m_electricHeaterMinTankTemperature = m_electricHeaterMinTankTemperature - 0.5f; update();
    } else if ((m_currentControl == 3) && (m_electricHeaterMinBattery > 48) && (m_electricHeaterMinBattery < 52)) {
      m_electricHeaterMinBattery = m_electricHeaterMinBattery - 0.2f; update();
    }
  } else if (key == KEY_4) {
    if ((m_currentControl == 0) && (m_turboDuration < 60)) {
      m_turboDuration++; update();
    } else if (m_currentControl == 1) {
      m_useElectricHeater = ~m_useElectricHeater; update();
    } else if ((m_currentControl == 2) && (m_electricHeaterMinTankTemperature < 60)) {
      m_electricHeaterMinTankTemperature = m_electricHeaterMinTankTemperature + 0.5f; update();
    } else if ((m_currentControl == 3) && (m_electricHeaterMinBattery < 52)) {
      m_electricHeaterMinBattery = m_electricHeaterMinBattery + 0.2f; update();
    } else if (m_currentControl < 4) {
    
    } else if (m_currentControl == 4) {
      //m_client->saveSettings(m_turboDuration, m_useElectricHeater, m_electricHeaterMinTankTemperature, m_electricHeaterMinBattery);
      hide();
    } else if (m_currentControl == 5) {
      hide();
    }
    }
}

void SettingsScreen::makeLine(uint8_t index, const char *title, const char *value)
{
  lv_obj_t *line;
  line = lv_obj_create(m_root);
  lv_obj_add_style(line, &lineStyle, LV_PART_MAIN);
  lv_obj_set_flex_flow(line, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(line, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  m_lines[index].value = lv_label_create(line);
  lv_label_set_text(m_lines[index].value, title);
  lv_obj_set_flex_grow(m_lines[index].value, 1);
  lv_obj_t *label;
  m_lines[index].leftButton = lv_image_create(line);
  lv_image_set_src(m_lines[index].leftButton, &left);
  lv_obj_set_style_opa(m_lines[index].leftButton, LV_OPA_30, LV_PART_MAIN);
  m_lines[index].value = lv_label_create(line);
  lv_label_set_text(m_lines[index].value, value);
  m_lines[index].rightButton = lv_image_create(line);
  lv_image_set_src(m_lines[index].rightButton, &right);
  lv_obj_set_style_opa(m_lines[index].rightButton, LV_OPA_30, LV_PART_MAIN);
}

void SettingsScreen::disableCurrentControl()
{
  if (m_currentControl < 4) {
    lv_obj_set_style_opa(m_lines[m_currentControl].leftButton, LV_OPA_30, LV_PART_MAIN);
    lv_obj_set_style_opa(m_lines[m_currentControl].rightButton, LV_OPA_30, LV_PART_MAIN);
  } else if (m_currentControl == 4) {
    lv_obj_set_style_opa(m_saveButton, LV_OPA_30, LV_PART_MAIN);
  } else if (m_currentControl == 5) {
    lv_obj_set_style_opa(m_cancelButton, LV_OPA_30, LV_PART_MAIN);
  }
}

void SettingsScreen::enableControl(uint8_t index)
{
  if (index < 4) {
    lv_obj_set_style_opa(m_lines[index].leftButton, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_opa(m_lines[index].rightButton, LV_OPA_COVER, LV_PART_MAIN);
    makeKeypad((index > 0) ? "Previous" : NULL, "Next", "<", ">");
  }
  else if (index == 4) {
    lv_obj_set_style_opa(m_saveButton, LV_OPA_COVER, LV_PART_MAIN);
    makeKeypad("Previous", "Next", NULL, "Save");
  }
  else if (index == 5) {
    lv_obj_set_style_opa(m_cancelButton, LV_OPA_COVER, LV_PART_MAIN);
    makeKeypad("Previous", NULL, NULL, "Cancel");
  }
  m_currentControl = index;
}

void SettingsScreen::update()
{
  char val[32];
  lv_label_set_text_fmt(m_lines[0].value, "%d minutes", m_turboDuration);
  lv_label_set_text_fmt(m_lines[1].value, m_useElectricHeater ? "Enabled" : "Disabled");
  lv_label_set_text_fmt(m_lines[2].value, "%.0f°C", m_electricHeaterMinTankTemperature);
  lv_label_set_text_fmt(m_lines[3].value, "%.1fV", m_electricHeaterMinBattery);
}

void SettingsScreen::doShow()
{
  m_turboDuration = m_client->settings()->turboDuration();
  m_useElectricHeater = m_client->settings()->useElectricHeater();
  m_electricHeaterMinTankTemperature = m_client->settings()->electricHeaterMinTankTemperature();
  m_electricHeaterMinBattery = m_client->settings()->electricHeaterMinBattery();
  update();
  enableControl(0);
  lv_screen_load_anim(m_root, LV_SCR_LOAD_ANIM_OVER_TOP, 500, 0, false);
}
