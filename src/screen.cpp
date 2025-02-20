#include <core/lv_obj.h>
#include <widgets/label/lv_label.h>
#include <widgets/button/lv_button.h>
#include "screen.h"

Screen* Screen::m_home = NULL;

void debugB1Clicked(lv_event_t *event)
{
  Screen *screen = (Screen *)lv_event_get_user_data(event);
  screen->keyPressed(KEY_1);
}

void debugB2Clicked(lv_event_t *event)
{
  Screen *screen = (Screen *)lv_event_get_user_data(event);
  screen->keyPressed(KEY_2);
}

void debugB3Clicked(lv_event_t *event)
{
  Screen *screen = (Screen *)lv_event_get_user_data(event);
  screen->keyPressed(KEY_3);
}

void debugB4Clicked(lv_event_t *event)
{
  Screen *screen = (Screen *)lv_event_get_user_data(event);
  screen->keyPressed(KEY_4);
}

Screen::Screen(Client *client) : m_client(client),
                                 m_root(lv_obj_create(NULL)),
                                 m_keypad(NULL)
{
  lv_obj_set_size(m_root, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void Screen::show()
{
  doShow();
}

void Screen::hide()
{
  m_home->show();
}

void Screen::keyPressed(uint8_t key)
{
  // do nothing here but can be overriden
}

void Screen::debug(const char *msg)
{
  lv_label_set_text(m_title, msg);
}

void Screen::makeHeader(const char *title)
{
  m_header = lv_obj_create(m_root);
  lv_obj_add_style(m_header, &lineStyle, LV_PART_MAIN);
  lv_obj_add_style(m_header, &headerStyle, LV_PART_MAIN);
  m_title = lv_label_create(m_header);
  lv_label_set_text(m_title, title);
  lv_obj_align(m_title, LV_ALIGN_LEFT_MID, 0, 0);
}

void Screen::makeKeypad(const char *key1, const char *key2, const char *key3, const char *key4)
{
  if (m_keypad) {
    lv_obj_delete(m_keypad);
  }
  m_keypad = lv_obj_create(m_root);
  lv_obj_add_style(m_keypad, &lineStyle, LV_PART_MAIN);
  lv_obj_add_style(m_keypad, &headerStyle, LV_PART_MAIN);
  lv_obj_set_style_pad_all(m_keypad, 0, LV_PART_MAIN);
  lv_obj_set_pos(m_keypad, 0, SCREEN_HEIGHT - LINE_HEIGHT);
  uint8_t controlWidth = SCREEN_WIDTH / 4;
  if (key1) {
    lv_obj_t *key = lv_obj_create(m_keypad);
    lv_obj_set_size(key, controlWidth, LINE_HEIGHT);
    lv_obj_set_pos(key, 0, 0);
    lv_obj_add_style(key, &transparentStyle, LV_PART_MAIN);
    lv_obj_add_event_cb(key, debugB1Clicked, LV_EVENT_CLICKED, this);
    lv_obj_t *label = lv_label_create(key);
    lv_obj_add_style(label, &transparentStyle, LV_PART_MAIN);
    lv_label_set_text(label, key1);
    lv_obj_center(label);
  }
  if (key2) {
    lv_obj_t *key = lv_obj_create(m_keypad);
    lv_obj_set_size(key, controlWidth, LINE_HEIGHT);
    lv_obj_set_pos(key, controlWidth, 0);
    lv_obj_add_style(key, &transparentStyle, LV_PART_MAIN);
    lv_obj_add_event_cb(key, debugB2Clicked, LV_EVENT_CLICKED, this);
    lv_obj_t *label = lv_label_create(key);
    lv_obj_add_style(label, &transparentStyle, LV_PART_MAIN);
    lv_label_set_text(label, key2);
    lv_obj_center(label);
  }
  if (key3) {
    lv_obj_t *key = lv_obj_create(m_keypad);
    lv_obj_set_size(key, controlWidth, LINE_HEIGHT);
    lv_obj_set_pos(key, controlWidth * 2, 0);
    lv_obj_add_style(key, &transparentStyle, LV_PART_MAIN);
    lv_obj_add_event_cb(key, debugB3Clicked, LV_EVENT_CLICKED, this);
    lv_obj_t *label = lv_label_create(key);
    lv_obj_add_style(label, &transparentStyle, LV_PART_MAIN);
    lv_label_set_text(label, key3);
    lv_obj_center(label);
  }
  if (key4)
  {
    lv_obj_t *key = lv_obj_create(m_keypad);
    lv_obj_set_size(key, controlWidth, LINE_HEIGHT);
    lv_obj_set_pos(key, controlWidth * 3, 0);
    lv_obj_add_style(key, &transparentStyle, LV_PART_MAIN);
    lv_obj_add_event_cb(key, debugB4Clicked, LV_EVENT_CLICKED, this);
    lv_obj_t *label = lv_label_create(key);
    lv_obj_add_style(label, &transparentStyle, LV_PART_MAIN);
    lv_label_set_text(label, key4);
    lv_obj_center(label);
  }
}

