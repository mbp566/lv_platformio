#ifndef SCREENINFO_H
#define SCREENINFO_H

#include "screen.h"
#include "data.h"

class InfoScreen : public Screen
{
public:
  InfoScreen();
  void keyPressed(uint8_t key);
  void update() override;
private:
  using Line = struct {
    lv_obj_t *title;
    lv_obj_t *value;
  };
  Line m_lines[3];
  void makeLine(uint8_t index, const char *title);
  void doShow() override;
  
};

#endif