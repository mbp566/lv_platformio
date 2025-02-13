#include "data.h"

Data::Data()
{
  update();
}

float Data::tempLow()
{
  return m_tempLow;
}

float Data::tempHigh()
{
  return m_tempHigh;
}

float Data::tempPanel()
{
  return m_tempPanel;
}

uint8_t Data::heat()
{
  return m_heat;
}

bool Data::pump()
{
  return m_pump;
}

void Data::update()
{
  m_tempLow = 15;
  m_tempHigh = 25;
  m_tempPanel = 40;
  m_heat = HEAT_LOW;
  m_pump = true;
}
