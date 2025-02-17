#include "lvgl.h"

class Screen
{
public:
  Screen();
  virtual void show();
  void showAnimated(lv_screen_load_anim_t anim_type) ;
protected:
  lv_obj_t *m_root;
};