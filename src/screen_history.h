#ifndef SCREENHISTORY_H
#define SCREENHISTORY_H

#include <widgets/chart/lv_chart.h>
#include <draw/lv_draw.h>
#include <draw/lv_draw_vector.h>
#include <widgets/canvas/lv_canvas.h>
#include "screen.h"

class HistoryScreen : public Screen
{
public:
  HistoryScreen(Client *client);
  void keyPressed(uint8_t key);
private:
  lv_obj_t *m_chart;
  lv_obj_t *m_canvas;
  float m_canvasHeight;
  lv_chart_series_t *m_tempLow;
  lv_chart_series_t *m_tempHigh;
  lv_chart_series_t *m_tempPanel;
  void update();
  void drawGrid(lv_layer_t *layer);
  void drawHeat(lv_layer_t *layer);
  void drawPump(lv_layer_t *layer);
  void drawCurve(lv_layer_t *layer, lv_fpoint_t *pts, int pointCount, lv_color_t color, const char *label, int offset);
  void doShow() override;
};

#endif