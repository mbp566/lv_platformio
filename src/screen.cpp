#include "screen.h"

Screen::Screen() : 
  m_root(lv_obj_create(NULL))
{

}

void Screen::show()
{
  lv_screen_load(m_root);
}

void Screen::showAnimated(lv_screen_load_anim_t animation)
{
  lv_screen_load_anim(m_root, animation, 1, 0, false);
}

