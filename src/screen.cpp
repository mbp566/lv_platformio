#include <cstdio>
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

Screen::Screen() : 
  m_root(lv_obj_create(NULL)),
  m_keypad(NULL)
{
  lv_obj_set_size(m_root, SCREEN_WIDTH, SCREEN_HEIGHT);
  lv_obj_set_scrollbar_mode(m_root, LV_SCROLLBAR_MODE_OFF);
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
    m_keypadLabels[0] = lv_label_create(key);
    lv_label_set_text(m_keypadLabels[0], key1);
    lv_obj_center(m_keypadLabels[0]);
  }
  if (key2) {
    lv_obj_t *key = lv_obj_create(m_keypad);
    lv_obj_set_size(key, controlWidth, LINE_HEIGHT);
    lv_obj_set_pos(key, controlWidth, 0);
    lv_obj_add_style(key, &transparentStyle, LV_PART_MAIN);
    lv_obj_add_event_cb(key, debugB2Clicked, LV_EVENT_CLICKED, this);
    m_keypadLabels[1] = lv_label_create(key);
    lv_label_set_text(m_keypadLabels[1], key2);
    lv_obj_center(m_keypadLabels[1]);
  }
  if (key3) {
    lv_obj_t *key = lv_obj_create(m_keypad);
    lv_obj_set_size(key, controlWidth, LINE_HEIGHT);
    lv_obj_set_pos(key, controlWidth * 2, 0);
    lv_obj_add_style(key, &transparentStyle, LV_PART_MAIN);
    lv_obj_add_event_cb(key, debugB3Clicked, LV_EVENT_CLICKED, this);
    m_keypadLabels[2] = lv_label_create(key);
    lv_label_set_text(m_keypadLabels[2], key3);
    lv_obj_center(m_keypadLabels[2]);
  }
  if (key4)
  {
    lv_obj_t *key = lv_obj_create(m_keypad);
    lv_obj_set_size(key, controlWidth, LINE_HEIGHT);
    lv_obj_set_pos(key, controlWidth * 3, 0);
    lv_obj_add_style(key, &transparentStyle, LV_PART_MAIN);
    lv_obj_add_event_cb(key, debugB4Clicked, LV_EVENT_CLICKED, this);
    m_keypadLabels[3] = lv_label_create(key);
    lv_label_set_text(m_keypadLabels[3], key4);
    lv_obj_center(m_keypadLabels[3]);
  }
}

ListScreen::ListScreen(size_t itemCount) :
  m_itemCount(itemCount)
{
  m_labels = (lv_obj_t **)malloc(m_itemCount * sizeof(lv_obj_t *));

  m_list = lv_obj_create(m_root);
  lv_obj_set_size(m_list, SCREEN_WIDTH, LINE_HEIGHT * itemCount);
  lv_obj_set_flex_flow(m_list, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_style_pad_all(m_list, 0, LV_PART_MAIN);
  lv_obj_set_style_pad_row(m_list, 0, LV_PART_MAIN);
  lv_obj_set_style_bg_color(m_list, LV_COLOR_MAKE(0xFF, 0x28, 0x31), LV_PART_MAIN);

  lv_obj_set_scrollbar_mode(m_list, LV_SCROLLBAR_MODE_OFF);

  makeKeypad("Up", "Down", NULL, "Close");
}

ListScreen::~ListScreen()
{
  free(m_labels);
}

void ListScreen::show()
{
  setTopItem(0);
  Screen::show();
}

void ListScreen::keyPressed(uint8_t key)
{
  if ((key == KEY_1) && (!lv_obj_has_flag(m_keypadLabels[0], LV_OBJ_FLAG_HIDDEN))) {
    setTopItem(m_topItem - 1);
  } else if ((key == KEY_2) && (!lv_obj_has_flag(m_keypadLabels[1], LV_OBJ_FLAG_HIDDEN))) {
    setTopItem(m_topItem + 1);
  } else if (key == KEY_4) {
    hide();
  }
}

void ListScreen::setTopItem(int item)
{
  m_topItem = item;
  lv_obj_set_y(m_list, -m_topItem * LINE_HEIGHT);

  if ((m_itemCount - m_topItem) * LINE_HEIGHT <= SCREEN_HEIGHT - LINE_HEIGHT) {
    lv_obj_add_flag(m_keypadLabels[1], LV_OBJ_FLAG_HIDDEN);
  } else {
    lv_obj_remove_flag(m_keypadLabels[1], LV_OBJ_FLAG_HIDDEN);
  }

  if (m_topItem > 0) {
    lv_obj_remove_flag(m_keypadLabels[0], LV_OBJ_FLAG_HIDDEN);
  } else {
    lv_obj_add_flag(m_keypadLabels[0], LV_OBJ_FLAG_HIDDEN);
  }
}

void ListScreen::makeLine(uint8_t index, const char *title)
{
  lv_obj_t *line;
  line = lv_obj_create(m_list);
  lv_obj_add_style(line, &lineStyle, LV_PART_MAIN);
  lv_obj_set_flex_flow(line, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(line, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_t *t = lv_label_create(line);
  lv_label_set_text(t, title);
  lv_obj_set_flex_grow(t, 1);
  m_labels[index] = lv_label_create(line);
}

void ListScreen::updateLine(uint8_t index, float value, char const *format)
{
  char val[32];
  sprintf(val, format, value);
  lv_label_set_text(m_labels[index], val);
}
