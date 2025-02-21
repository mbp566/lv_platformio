#include <math.h>
#include "screen_history.h"

#define CHART_LEFT 20
#define CHART_RIGHT 460
#define CHART_WIDTH 440

HistoryScreen::HistoryScreen(Client *client) :
  Screen(client)
{
  lv_obj_set_flex_flow(m_root, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_style_pad_row(m_root, 0, LV_PART_MAIN);
  lv_obj_set_style_bg_color(m_root, LV_COLOR_MAKE(0x29, 0x28, 0x31), LV_PART_MAIN);

  makeHeader("History");
/*
  m_chart = lv_chart_create(m_root);
  lv_obj_set_width(m_chart, SCREEN_WIDTH);
  lv_obj_set_flex_grow(m_chart, 1);
  lv_chart_set_type(m_chart, LV_CHART_TYPE_LINE);
  lv_chart_set_div_line_count(m_chart, 11, 25);
  lv_chart_set_point_count(m_chart, 144);
  lv_obj_set_style_opa(m_chart, LV_OPA_0, LV_PART_INDICATOR);
  m_tempLow = lv_chart_add_series(m_chart, lv_palette_main(LV_PALETTE_BLUE), LV_CHART_AXIS_PRIMARY_Y);
  m_tempHigh = lv_chart_add_series(m_chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
  m_tempPanel = lv_chart_add_series(m_chart, lv_palette_main(LV_PALETTE_YELLOW), LV_CHART_AXIS_PRIMARY_Y);
*/

  LV_DRAW_BUF_DEFINE(draw_buf, SCREEN_WIDTH, SCREEN_HEIGHT - LINE_HEIGHT - LINE_HEIGHT, LV_COLOR_FORMAT_ARGB8888);
  m_canvas = lv_canvas_create(m_root);
  lv_canvas_set_draw_buf(m_canvas, &draw_buf);
  m_canvasHeight = SCREEN_HEIGHT - LINE_HEIGHT - LINE_HEIGHT;

  makeKeypad(NULL, NULL, NULL, "Close");
}

void HistoryScreen::keyPressed(uint8_t key)
{
  hide();
}

void HistoryScreen::update()
{
  /*
  for (int i = 0; i < 144; i++) {
    if (i <= m_client->lastHistoryIndex()) {
      lv_chart_set_value_by_id(m_chart, m_tempLow, i, round(m_client->history()[i].tempLow));
      lv_chart_set_value_by_id(m_chart, m_tempHigh, i, round(m_client->history()[i].tempHigh));
      lv_chart_set_value_by_id(m_chart, m_tempPanel, i, round(m_client->history()[i].tempPanel));
    } else {
      lv_chart_set_value_by_id(m_chart, m_tempLow, i, 0);
      lv_chart_set_value_by_id(m_chart, m_tempHigh, i, 0);
      lv_chart_set_value_by_id(m_chart, m_tempPanel, i, 0);
    }
  }
    */

  if (m_client->nextHistoryIndex() < 2) {
    return;
  }
  //lv_canvas_fill_bg(m_canvas, LV_COLOR_MAKE(0x29, 0x28, 0x31), LV_OPA_COVER);

  lv_fpoint_t pointsLow[144];
  lv_fpoint_t pointsHigh[144];
  lv_fpoint_t pointsPanel[144];

  for (int i = 0; i < m_client->nextHistoryIndex(); i++)
  {
    float x = ((float) i / 144.0f) * CHART_WIDTH + CHART_LEFT;
    pointsLow[i] = { x, m_canvasHeight * (100 - m_client->history()[i].tempLow) / 100 };
    pointsHigh[i] = { x, m_canvasHeight * (100 - m_client->history()[i].tempHigh) / 100 };
    pointsPanel[i] = { x, m_canvasHeight * (100 - m_client->history()[i].tempPanel) / 100 };
  }

  lv_layer_t layer;
  lv_canvas_init_layer(m_canvas, &layer);
  
  drawCurve(&layer, pointsLow, m_client->nextHistoryIndex(), LV_COLOR_MAKE(0x00, 0x00, 0xff));
  drawCurve(&layer, pointsHigh, m_client->nextHistoryIndex(), LV_COLOR_MAKE(0xff, 0x00, 0x00));
  drawCurve(&layer, pointsPanel, m_client->nextHistoryIndex(), LV_COLOR_MAKE(0xff, 0xff, 0x00));

  drawGrid(&layer);

  lv_canvas_finish_layer(m_canvas, &layer);
}

void HistoryScreen::drawGrid(lv_layer_t *layer)
{
  lv_vector_dsc_t *dsc = lv_vector_dsc_create(layer);
  lv_vector_dsc_set_blend_mode(dsc, LV_VECTOR_BLEND_ADDITIVE);
  lv_vector_path_t *path = lv_vector_path_create(LV_VECTOR_PATH_QUALITY_MEDIUM);

  lv_color_t color = LV_COLOR_MAKE(0x77, 0x77, 0x77);
  
  for (int i = 0; i < 26; i++)
  {
    float l = CHART_LEFT + (float)i * (CHART_WIDTH / 24.0f);
    lv_fpoint_t line[2];
    line[0] = {l, 0.0f};
    line[1] = {l, m_canvasHeight};
    lv_vector_path_move_to(path, &line[0]);
    lv_vector_path_line_to(path, &line[1]);
    lv_vector_dsc_set_fill_opa(dsc, LV_OPA_0);
    lv_vector_dsc_set_stroke_color(dsc, color);
    lv_vector_dsc_set_stroke_width(dsc, 1.0f);
    lv_vector_dsc_set_stroke_opa(dsc, LV_OPA_COVER);
    lv_vector_dsc_add_path(dsc, path);
  }

  lv_draw_vector(dsc);
  lv_vector_path_delete(path);

  lv_vector_dsc_delete(dsc);
}

void HistoryScreen::drawCurve(lv_layer_t *layer, lv_fpoint_t *pts, int pointCount, lv_color_t color)
{
  lv_vector_dsc_t *dsc = lv_vector_dsc_create(layer);
  lv_vector_dsc_set_blend_mode(dsc, LV_VECTOR_BLEND_ADDITIVE);
  lv_vector_path_t *path = lv_vector_path_create(LV_VECTOR_PATH_QUALITY_MEDIUM);

  lv_vector_path_move_to(path, &pts[0]);
  for (int i = 1; i < pointCount; i++)
  {
    lv_vector_path_line_to(path, &pts[i]);
  }

  lv_vector_dsc_set_fill_opa(dsc, LV_OPA_0);
  lv_vector_dsc_set_stroke_color(dsc, color);
  lv_vector_dsc_set_stroke_width(dsc, 3.0f);
  lv_vector_dsc_set_stroke_opa(dsc, LV_OPA_COVER);
  lv_vector_dsc_add_path(dsc, path);

  lv_draw_vector(dsc);
  //lv_vector_path_delete(path);

  //lv_vector_dsc_delete(dsc);
}

void HistoryScreen::doShow()
{
  update();
  lv_screen_load_anim(m_root, LV_SCR_LOAD_ANIM_OVER_TOP, 500, 0, false);
}
