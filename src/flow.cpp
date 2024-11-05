#include <cstdio>
#include <widgets/image/lv_image.h>
#include <widgets/label/lv_label.h>
#include <widgets/table/lv_table.h>
#include <widgets/win/lv_win.h>
#include <misc/lv_types.h>
#include <draw/lv_draw.h>
#include "data.h"
#include "style.h"
#include "globals.h"
#include "flow.h"

#if LV_FONT_MONTSERRAT_24 == 0
#error "LV_FONT_MONTSERRAT_24 is required. Enable it in lv_conf.h."
#endif

LV_IMAGE_DECLARE(battery);
LV_IMAGE_DECLARE(battery_flow);
LV_IMAGE_DECLARE(grid);
LV_IMAGE_DECLARE(grid_flow);
LV_IMAGE_DECLARE(inverter);
LV_IMAGE_DECLARE(pv);
LV_IMAGE_DECLARE(pv_flow);
LV_IMAGE_DECLARE(load);
LV_IMAGE_DECLARE(load_flow);

void onPvClicked(lv_event_t *event)
{
  Flow* flow = (Flow*)lv_event_get_user_data(event);
  flow->showPvDetails();
}

void onGridClicked(lv_event_t *event)
{
  Flow *flow = (Flow *)lv_event_get_user_data(event);
  flow->showGridDetails();
}

void onInverterClicked(lv_event_t *event)
{
  Flow *flow = (Flow *)lv_event_get_user_data(event);
  flow->showInverterDetails();
}

void onBatteryClicked(lv_event_t *event)
{
  Flow *flow = (Flow *)lv_event_get_user_data(event);
  flow->showBatteryDetails();
}

void onLoadClicked(lv_event_t *event)
{
  Flow *flow = (Flow *)lv_event_get_user_data(event);
  flow->showLoadDetails();
}

void onTableDraw(lv_event_t *e)
{
  lv_draw_task_t *draw_task = lv_event_get_draw_task(e);
  lv_draw_dsc_base_t *base_dsc = (lv_draw_dsc_base_t*)draw_task->draw_dsc;
  /*If the cells are drawn...*/
  if (base_dsc->part == LV_PART_ITEMS)
  {
    uint32_t row = base_dsc->id1;
    uint32_t col = base_dsc->id2;

    /*Make every 2nd row grayish*/
    if ((row != 0 && row % 2) == 0)
    {
      lv_draw_fill_dsc_t *fill_draw_dsc = lv_draw_task_get_fill_dsc(draw_task);
      if (fill_draw_dsc)
      {
        fill_draw_dsc->color = lv_color_mix(lv_palette_main(LV_PALETTE_GREY), fill_draw_dsc->color, LV_OPA_10);
        fill_draw_dsc->opa = LV_OPA_COVER;
      }
    }
  }
}

Flow::Flow(lv_obj_t *parent, Data *data)
{
  m_parent = parent;
  m_data = data;

      lv_obj_set_style_margin_all(parent, 0, LV_PART_MAIN);
  lv_obj_set_style_pad_all(parent, 0, LV_PART_MAIN);

  lv_obj_t *pv_img = lv_image_create(parent);
  lv_image_set_src(pv_img, &pv);
  lv_obj_set_pos(pv_img, 10, 5);
  lv_obj_add_flag(pv_img, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_event_cb(pv_img, onPvClicked, LV_EVENT_CLICKED, this);

  lv_obj_t *pv_lbl = lv_label_create(parent);
  lv_obj_set_pos(pv_lbl, 70, 92);
  lv_obj_set_width(pv_lbl, 60);
  lv_label_set_text_fmt(pv_lbl, "%.0fW", data->pv()->chargingPower());
  lv_obj_set_style_text_align(pv_lbl, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);

  lv_obj_t *grid_img = lv_image_create(parent);
  lv_image_set_src(grid_img, &grid);
  lv_obj_set_pos(grid_img, 208, 5);

  lv_obj_t *grid_lbl = lv_label_create(parent);
  lv_obj_set_pos(grid_lbl, 190, 92);
  lv_obj_set_width(grid_lbl, 60);
  lv_label_set_text_fmt(grid_lbl, "%.0fA", data->grid()->current());
  lv_obj_set_style_text_align(grid_lbl, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);

  lv_obj_t *inverter_img = lv_image_create(parent);
  lv_image_set_src(inverter_img, &inverter);
  lv_obj_set_pos(inverter_img, 109, 65);

  lv_obj_t *battery_img = lv_image_create(parent);
  lv_image_set_src(battery_img, &battery);
  lv_obj_set_pos(battery_img, 10, 125);

  lv_obj_t *main_lbl = lv_label_create(parent);
  lv_obj_set_pos(main_lbl, 115, 25);
  lv_obj_set_width(main_lbl, 90);
  lv_obj_set_style_text_align(main_lbl, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
  lv_obj_set_style_text_font(main_lbl, &lv_font_montserrat_24, 0);
  lv_label_set_text_fmt(main_lbl, "%.0fV (%.0f%)", data->battery()->voltage(), data->battery()->soc());
  
  lv_obj_t *battery_lbl = lv_label_create(parent);
  lv_obj_set_pos(battery_lbl, 90, 147);
  lv_obj_set_width(battery_lbl, 60);
  lv_label_set_text_fmt(battery_lbl, "%.0fA", data->battery()->current());
  lv_obj_set_style_text_align(battery_lbl, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);

  lv_obj_t *load_img = lv_image_create(parent);
  lv_image_set_src(load_img, &load);
  lv_obj_set_pos(load_img, 208, 125);

  lv_obj_t *load_lbl = lv_label_create(parent);
  lv_obj_set_pos(load_lbl, 170, 147);
  lv_obj_set_width(load_lbl, 60);
  lv_label_set_text_fmt(load_lbl, "%.0fW", data->load()->apparentPower());
  lv_obj_set_style_text_align(load_lbl, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);

  lv_obj_t *battery_flow_img = lv_image_create(parent);
  lv_image_set_src(battery_flow_img, &battery_flow);
  lv_obj_set_pos(battery_flow_img, 71, 113);

  lv_obj_t *grid_flow_img = lv_image_create(parent);
  lv_image_set_src(grid_flow_img, &grid_flow);
  lv_obj_set_pos(grid_flow_img, 169, 48);

  lv_obj_t *pv_flow_img = lv_image_create(parent);
  lv_image_set_src(pv_flow_img, &pv_flow);
  lv_obj_set_pos(pv_flow_img, 61, 48);

  lv_obj_t *load_flow_img = lv_image_create(parent);
  lv_image_set_src(load_flow_img, &load_flow);
  lv_obj_set_pos(load_flow_img, 162, 113);

}

static void CloseEventHandler(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);

  if (code == LV_EVENT_CLICKED) {
    lv_obj_t *win = (lv_obj_t *)e->user_data;
    lv_obj_delete(win);
  }
}

void Flow::showPvDetails()
{
  lv_obj_t *win = lv_win_create(lv_screen_active());
  lv_obj_set_pos(win, 0, 0);
  lv_obj_set_size(win, 320, 240);

  lv_win_add_title(win, "PV details");

  lv_obj_t *btn = lv_win_add_button(win, LV_SYMBOL_CLOSE, 60);
  lv_obj_add_event_cb(btn, CloseEventHandler, LV_EVENT_CLICKED, win);

  lv_obj_set_height(lv_win_get_header(win), HEADER_HEIGHT);

  lv_obj_t *cont = lv_win_get_content(win); 
  lv_obj_set_style_pad_all(cont, 0, LV_PART_MAIN);

  lv_obj_t *table = lv_table_create(cont);
  lv_obj_set_style_border_side(table, LV_BORDER_SIDE_NONE, LV_PART_MAIN);
  lv_table_set_column_width(table, 0, 220);
  lv_table_set_column_width(table, 1, 100);

  lv_table_set_cell_value(table, 0, 0, "PV voltage (V)");
  lv_table_set_cell_value(table, 0, 1, "Value");
  lv_table_set_cell_value(table, 1, 0, "PV charging current (A)");
  lv_table_set_cell_value(table, 1, 1, "Value");
  lv_table_set_cell_value(table, 2, 0, "PV charging power (W)");
  lv_table_set_cell_value(table, 2, 1, "Value");

  lv_obj_add_event_cb(table, onTableDraw, LV_EVENT_DRAW_TASK_ADDED, NULL);
  lv_obj_add_flag(table, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);
}

void Flow::showGridDetails()
{
}

void Flow::showInverterDetails()
{
}

void Flow::showBatteryDetails()
{
}

void Flow::showLoadDetails()
{
}

