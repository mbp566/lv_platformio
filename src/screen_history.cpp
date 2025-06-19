#include <math.h>
#include <misc/lv_types.h>
#include "screen_history.h"

#define CHART_LEFT 10
#define CHART_WIDTH 432
#define GRID_X 18
#define CHART_TOP 10
#define CHART_HEIGHT 200
#define GRID_Y 20
#define CHART_TEXT_SIZE 14

typedef char Label[16];
static Label tempLabels[] = {"0°", "20°", "40°", "60°", "80°", "100°"};
static Label timeLabels[] = {"0h", "4h", "8h", "12h", "16h", "20h", "24h"};

uint8_t *buffer;

HistoryScreen::HistoryScreen() : 
  Screen()/*,
  m_nextHistoryIndex(0)*/
{
  /*
  for (int i = 0; i < 144; i++) {
    m_history[i].time = 0;
    m_history[i].tempLow = 0.0f;
    m_history[i].tempHigh = 0.0f;
    m_history[i].tempPanel = 0.0f;
    m_history[i].heat = 0;
    m_history[i].pump = false;
  }
    */
  lv_obj_set_flex_flow(m_root, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_style_pad_row(m_root, 0, LV_PART_MAIN);
  lv_obj_set_style_bg_color(m_root, LV_COLOR_MAKE(0x29, 0x28, 0x31), LV_PART_MAIN);

  buffer = (uint8_t*)malloc(SCREEN_WIDTH * (SCREEN_HEIGHT - LINE_HEIGHT - LINE_HEIGHT) * 4);
  m_canvas = lv_canvas_create(m_root);
  lv_canvas_set_buffer(m_canvas, buffer, SCREEN_WIDTH, SCREEN_HEIGHT - LINE_HEIGHT - LINE_HEIGHT, LV_COLOR_FORMAT_ARGB8888);
  m_canvasHeight = SCREEN_HEIGHT - LINE_HEIGHT - LINE_HEIGHT;

  makeKeypad(NULL, NULL, NULL, "Close");
}

HistoryScreen::~HistoryScreen()
{
  free(buffer);
}

void HistoryScreen::keyPressed(uint8_t key)
{
  hide();
}

void HistoryScreen::update(const Data &data)
{
  /*
  Status status;
  status.time = rawTime;
  status.tempLow = tempLow;
  status.tempHigh = tempHigh;
  status.tempPanel = tempPanel;
  status.heat = heat;
  status.pump = pump;
  if (m_nextHistoryIndex == 0) {
    int minutesOfTheDay = (rawTime / 60) % 1440;
    m_nextHistoryIndex = minutesOfTheDay / 10;
  }
  //lv_canvas_fill_bg(m_canvas, LV_COLOR_MAKE(0x29, 0x28, 0x31), LV_OPA_COVER);

  lv_fpoint_t pointsLow[144];
  lv_fpoint_t pointsHigh[144];
  lv_fpoint_t pointsPanel[144];

  for (int i = 0; i < m_nextHistoryIndex; i++)
  {
    float x = ((float) i / 144.0f) * CHART_WIDTH + CHART_LEFT;
    pointsLow[i] = {x, CHART_TOP + CHART_HEIGHT * (100 - m_history[i].tempLow) / 100 };
    pointsHigh[i] = {x, CHART_TOP + CHART_HEIGHT * (100 - m_history[i].tempHigh) / 100};
    pointsPanel[i] = {x, CHART_TOP + CHART_HEIGHT * (100 - m_history[i].tempPanel) / 100};
  }

  lv_layer_t layer;
  lv_canvas_init_layer(m_canvas, &layer);

  drawGrid(&layer);

  drawHeat(&layer);
  drawPump(&layer);

  drawCurve(&layer, pointsLow, m_nextHistoryIndex, LV_COLOR_MAKE(0xE9, 0xC4, 0x6A), "Tank", 0);
  drawCurve(&layer, pointsHigh, m_nextHistoryIndex, LV_COLOR_MAKE(0xE7, 0x6F, 0x51), "Water", 1);
  drawCurve(&layer, pointsPanel, m_nextHistoryIndex, LV_COLOR_MAKE(0x36, 0xBA, 0x98), "Panel", 2);

  lv_canvas_finish_layer(m_canvas, &layer);
  */
}

/*
void HistoryScreen::drawGrid(lv_layer_t *layer)
{
  lv_draw_line_dsc_t line_dsc;
  lv_draw_line_dsc_init(&line_dsc);
  // sub lines
  line_dsc.color = LV_COLOR_MAKE(0x49, 0x48, 0x51);
  line_dsc.width = 1;
  line_dsc.round_end = 1;
  line_dsc.round_start = 1;
  for (int j = CHART_TOP; j < CHART_TOP + CHART_HEIGHT; j += GRID_Y) {
    line_dsc.p1.x = CHART_LEFT;
    line_dsc.p1.y = j;
    line_dsc.p2.x = CHART_LEFT + CHART_WIDTH;
    line_dsc.p2.y = j;
    lv_draw_line(layer, &line_dsc);
  }
  // right labels
  lv_draw_label_dsc_t label_dsc;
  lv_draw_label_dsc_init(&label_dsc);
  label_dsc.color = LV_COLOR_MAKE(0xA9, 0xA8, 0xB1);
  label_dsc.font = &lv_font_montserrat_14;
  for (int i = 0, j = CHART_TOP + CHART_HEIGHT - CHART_TEXT_SIZE / 2; i <= 6; i++, j -= GRID_Y * 2)
  {
    label_dsc.text = tempLabels[i];
    lv_area_t coords = {CHART_LEFT + CHART_WIDTH + CHART_TEXT_SIZE / 2, j, SCREEN_WIDTH, j + CHART_TEXT_SIZE};
    lv_draw_label(layer, &label_dsc, &coords);
  }
  // main line
  line_dsc.color = LV_COLOR_MAKE(0xA9, 0xA8, 0xB1);
  line_dsc.p1.x = CHART_LEFT;
  line_dsc.p1.y = CHART_TOP + CHART_HEIGHT;
  line_dsc.p2.x = CHART_LEFT + CHART_WIDTH;
  line_dsc.p2.y = CHART_TOP + CHART_HEIGHT;
  lv_draw_line(layer, &line_dsc);
  // time labels
  lv_draw_label_dsc_init(&label_dsc);
  label_dsc.color = LV_COLOR_MAKE(0xA9, 0xA8, 0xB1);
  label_dsc.font = &lv_font_montserrat_14;
  for (int i = 0, j = CHART_LEFT - CHART_TEXT_SIZE / 2; i <= 7; i++, j += GRID_X * 4) {
    label_dsc.text = timeLabels[i];
    lv_area_t coords = {j, CHART_TOP + CHART_HEIGHT + CHART_TEXT_SIZE / 2, SCREEN_WIDTH, CHART_TOP + CHART_HEIGHT + CHART_TEXT_SIZE};
    lv_draw_label(layer, &label_dsc, &coords);
  }
}

void HistoryScreen::drawHeat(lv_layer_t *layer)
{
  int start = 0;
  int i = 1;
  uint8_t heatStatus = m_history[0].heat;
  while (i < 144)
  {
    while ((i < 144) && (m_history[i].heat == heatStatus)) {
      i++;
    }
    if (heatStatus != HEAT_OFF) {
      lv_draw_rect_dsc_t rect_dsc;
      lv_draw_rect_dsc_init(&rect_dsc);
      if (heatStatus == HEAT_TURBO) {
        rect_dsc.bg_color = LV_COLOR_MAKE(0xA8, 0x88, 0xB5);
      } else {
        rect_dsc.bg_color = LV_COLOR_MAKE(0x81, 0x74, 0xA0);
      }
      lv_area_t coords = {
          CHART_LEFT + CHART_WIDTH * start / 144,
          CHART_TOP + CHART_HEIGHT - CHART_TEXT_SIZE * 3,
          CHART_LEFT + CHART_WIDTH * i / 144,
          CHART_TOP + CHART_HEIGHT - CHART_TEXT_SIZE * 2};
      lv_draw_rect(layer, &rect_dsc, &coords);
      // label
      lv_draw_label_dsc_t label_dsc;
      lv_draw_label_dsc_init(&label_dsc);
      label_dsc.color = LV_COLOR_MAKE(0x09, 0x08, 0x11);
      label_dsc.font = &lv_font_montserrat_14;
      if (heatStatus == HEAT_TURBO) {
        label_dsc.text = "Turbo";
      } else {
        label_dsc.text = "Heat";
      }
      lv_draw_label(layer, &label_dsc, &coords);
    }
    start = i;
    heatStatus = m_history[i].heat;
  }
}

void HistoryScreen::drawPump(lv_layer_t *layer)
{
  int start = 0;
  int i = 1;
  bool pump = m_history[0].pump;
  while (i < 144)
  {
    while ((i < 144) && (m_history[i].pump == pump)) {
      i++;
    }
    if (pump) {
      lv_draw_rect_dsc_t rect_dsc;
      lv_draw_rect_dsc_init(&rect_dsc);
      rect_dsc.bg_color = LV_COLOR_MAKE(0xEF, 0xB6, 0xC6);
      lv_area_t coords = {
          CHART_LEFT + CHART_WIDTH * start / 144,
          CHART_TOP + CHART_HEIGHT - (int)(CHART_TEXT_SIZE * 1.5),
          CHART_LEFT + CHART_WIDTH * i / 144,
          CHART_TOP + CHART_HEIGHT - (int)(CHART_TEXT_SIZE * 0.5)};
      lv_draw_rect(layer, &rect_dsc, &coords);
      // label
      lv_draw_label_dsc_t label_dsc;
      lv_draw_label_dsc_init(&label_dsc);
      label_dsc.color = LV_COLOR_MAKE(0x09, 0x08, 0x11);
      label_dsc.font = &lv_font_montserrat_14;
      label_dsc.text = "Pump";
      lv_draw_label(layer, &label_dsc, &coords);
    }
    start = i;
    pump = m_history[i].pump;
  }
}

void HistoryScreen::drawCurve(lv_layer_t *layer, lv_fpoint_t *pts, int pointCount, lv_color_t color, const char *label, int offset)
{
  lv_vector_dsc_t *vector_dsc = lv_vector_dsc_create(layer);
  lv_vector_path_t *path = lv_vector_path_create(LV_VECTOR_PATH_QUALITY_MEDIUM);

  lv_vector_path_move_to(path, &pts[0]);
  for (int i = 1; i < pointCount; i++) {
    lv_vector_path_line_to(path, &pts[i]);
  }

  lv_vector_dsc_set_fill_opa(vector_dsc, LV_OPA_0);
  lv_vector_dsc_set_stroke_color(vector_dsc, color);
  lv_vector_dsc_set_stroke_width(vector_dsc, 3.0f);
  lv_vector_dsc_set_stroke_opa(vector_dsc, LV_OPA_COVER);
  lv_vector_dsc_add_path(vector_dsc, path);

  lv_draw_vector(vector_dsc);
  lv_vector_path_delete(path);

  lv_vector_dsc_delete(vector_dsc);
  // legend
  lv_draw_rect_dsc_t rect_dsc;
  lv_draw_rect_dsc_init(&rect_dsc);
  rect_dsc.bg_color = color;
  int x = CHART_LEFT + CHART_TEXT_SIZE + offset * (CHART_WIDTH - 2 * CHART_TEXT_SIZE) / 3;
  lv_area_t coords = {
    x, 
    CHART_TOP + (int)(CHART_TEXT_SIZE * 0.5), 
    x + CHART_TEXT_SIZE * 2, 
    CHART_TOP + (int)(CHART_TEXT_SIZE * 1.5)
  };
  lv_draw_rect(layer, &rect_dsc, &coords);
  //legend text
  lv_draw_label_dsc_t label_dsc;
  lv_draw_label_dsc_init(&label_dsc);
  label_dsc.color = LV_COLOR_MAKE(0xA9, 0xA8, 0xB1);
  label_dsc.font = &lv_font_montserrat_14;
  label_dsc.text = label;
  coords.x1 = coords.x2 + CHART_TEXT_SIZE / 2;
  coords.x2 = CHART_WIDTH;
  lv_draw_label(layer, &label_dsc, &coords);
}
*/

void HistoryScreen::doShow()
{
  lv_screen_load_anim(m_root, LV_SCR_LOAD_ANIM_OVER_TOP, 500, 0, false);
}
