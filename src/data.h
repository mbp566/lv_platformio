#ifndef DATA_H
#define DATA_H

#include <stdint.h>

#define HEAT_OFF 0
#define HEAT_LOW 1
#define HEAT_TURBO 2

class Data
{
  public:
    Data();
    float tempLow();
    float tempHigh();
    float tempPanel();
    uint8_t heat();
    bool pump();
    void update();
  private : float m_tempLow;
    float m_tempHigh;
    float m_tempPanel;
    uint8_t m_heat;
    bool m_pump;
};

#endif