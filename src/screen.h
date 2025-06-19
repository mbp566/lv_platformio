#ifndef SCREEN_H
#define SCREEN_H

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320
#define LINE_HEIGHT 40
#define PADDING 4
#define KEY_NONE 0
#define KEY_1 1
#define KEY_2 2
#define KEY_3 3 
#define KEY_4 4

#include <core/lv_obj.h>
#include <display/lv_display.h>

static lv_style_const_prop_t lineStyleProps[] = {
    LV_STYLE_CONST_WIDTH(SCREEN_WIDTH),
    LV_STYLE_CONST_HEIGHT(LINE_HEIGHT),
    LV_STYLE_CONST_PAD_LEFT(PADDING),
    LV_STYLE_CONST_PAD_TOP(0),
    LV_STYLE_CONST_PAD_RIGHT(PADDING),
    LV_STYLE_CONST_PAD_BOTTOM(0),
    LV_STYLE_CONST_RADIUS(0),
    LV_STYLE_CONST_BORDER_SIDE(LV_BORDER_SIDE_NONE),
    LV_STYLE_CONST_PROPS_END};
static LV_STYLE_CONST_INIT(lineStyle, lineStyleProps);

static lv_style_const_prop_t headerStyleProps[] = {
    LV_STYLE_CONST_BG_COLOR(lv_palette_main(LV_PALETTE_BLUE)),
    LV_STYLE_CONST_PROPS_END};
static LV_STYLE_CONST_INIT(headerStyle, headerStyleProps);

static lv_style_const_prop_t transparentStyleProps[] = {
    LV_STYLE_CONST_BG_OPA(0),
    LV_STYLE_CONST_RADIUS(0),
    LV_STYLE_CONST_BORDER_SIDE(LV_BORDER_SIDE_NONE),
    LV_STYLE_CONST_PAD_LEFT(0),
    LV_STYLE_CONST_PAD_TOP(0),
    LV_STYLE_CONST_PAD_RIGHT(0),
    LV_STYLE_CONST_PAD_BOTTOM(0),
    LV_STYLE_CONST_PROPS_END};
static LV_STYLE_CONST_INIT(transparentStyle, transparentStyleProps);

class Screen
{
public:
  Screen();
  virtual void show();
  static void hide();
  virtual void keyPressed(uint8_t key);
  void debug(const char *msg);
protected:
  lv_obj_t *m_root;
  lv_obj_t *m_header;
  lv_obj_t *m_keypad;
  lv_obj_t *m_title;
  static Screen *m_home;
  void makeKeypad(const char *key1, const char *key2, const char *key3, const char *key4);
  virtual void doShow() = 0;
};

class ListScreen : public Screen
{
public:
  ListScreen(size_t itemCount);
  ~ListScreen();
  virtual void show() override;
  virtual void keyPressed(uint8_t key);
protected:
  lv_obj_t *m_list;
  lv_obj_t **m_labels;
  void makeLine(uint8_t index, const char *title);
  void updateLine(uint8_t index, float value, char const *format);
};

#endif