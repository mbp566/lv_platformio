#include <cstdio>
#include <widgets/image/lv_image.h>
#include <widgets/animimage/lv_animimage.h>
#include <widgets/label/lv_label.h>
#include <widgets/table/lv_table.h>
#include <widgets/win/lv_win.h>
#include <misc/lv_types.h>
#include <draw/lv_draw.h>
#include "data.h"
#include "style.h"
#include "globals.h"
#include "flow.h"

LV_IMAGE_DECLARE(battery);
LV_IMAGE_DECLARE(battery_flow);
LV_IMAGE_DECLARE(grid);
LV_IMAGE_DECLARE(grid_flow);
LV_IMAGE_DECLARE(inverter);
LV_IMAGE_DECLARE(pv);
LV_IMAGE_DECLARE(pv_flow);
LV_IMAGE_DECLARE(load);
LV_IMAGE_DECLARE(load_flow);
LV_IMAGE_DECLARE(spark0);
LV_IMAGE_DECLARE(spark1);
LV_IMAGE_DECLARE(spark2);
LV_IMAGE_DECLARE(spark3);
LV_IMAGE_DECLARE(spark4);

typedef struct
{
  int32_t x, y;
} electronPosition;

typedef struct
{
  uint32_t steps;
  electronPosition positions[];
} electronAnimation;

static electronAnimation pvElectronAnim = {
  140,
  {{49, 39}, {49, 40}, {49, 41}, {49, 42}, {49, 43}, {49, 44}, {49, 45}, {49, 46}, {49, 47}, {49, 48}, {49, 49}, {49, 50}, {49, 51}, {49, 52}, {49, 53}, {49, 54}, {49, 55}, {49, 56}, {49, 57}, {49, 58}, {49, 59}, {49, 60}, {49, 61}, {49, 62}, {49, 63}, {49, 64}, {49, 65}, {49, 66}, {49, 67}, {49, 68}, {49, 69}, {49, 70}, {49, 71}, {49, 72}, {49, 73}, {49, 74}, {49, 75}, {49, 76}, {49, 77}, {49, 78}, {49, 79}, {49, 80}, {49, 81}, {49, 82}, {49, 83}, {49, 84}, {49, 85}, {49, 86}, {49, 87}, {49, 88}, {49, 89}, {49, 90}, {49, 91}, {49, 92}, {49, 93}, {50, 94}, {51, 95}, {52, 96}, {53, 96}, {54, 96}, {55, 96}, {56, 96}, {57, 96}, {58, 96}, {59, 96}, {60, 96}, {61, 96}, {62, 96}, {63, 96}, {64, 96}, {65, 96}, {66, 96}, {67, 96}, {68, 96}, {69, 96}, {70, 96}, {71, 96}, {72, 96}, {73, 96}, {74, 96}, {75, 96}, {76, 96}, {77, 96}, {78, 96}, {79, 96}, {80, 96}, {81, 96}, {82, 96}, {83, 96}, {84, 96}, {85, 96}, {86, 96}, {87, 96}, {88, 96}, {89, 96}, {90, 96}, {91, 96}, {92, 96}, {93, 96}, {94, 96}, {95, 96}, {96, 96}, {97, 96}, {98, 96}, {99, 96}, {100, 96}, {101, 96}, {102, 96}, {103, 96}, {104, 96}, {105, 96}, {106, 96}, {107, 96}, {108, 96}, {109, 96}, {110, 96}, {111, 96}, {112, 96}, {113, 96}, {114, 96}, {115, 96}, {116, 96}, {117, 96}, {118, 96}, {119, 96}, {120, 96}, {121, 96}, {122, 96}, {123, 96}, {124, 96}, {125, 96}, {126, 96}, {127, 96}, {128, 96}, {129, 96}, {130, 96}, {131, 96}, {132, 96}, {133, 96}, {134, 96}}
};

static electronAnimation gridElectronAnim = {
  140,
  {{244, 39}, {244, 40}, {244, 41}, {244, 42}, {244, 43}, {244, 44}, {244, 45}, {244, 46}, {244, 47}, {244, 48}, {244, 49}, {244, 50}, {244, 51}, {244, 52}, {244, 53}, {244, 54}, {244, 55}, {244, 56}, {244, 57}, {244, 58}, {244, 59}, {244, 60}, {244, 61}, {244, 62}, {244, 63}, {244, 64}, {244, 65}, {244, 66}, {244, 67}, {244, 68}, {244, 69}, {244, 70}, {244, 71}, {244, 72}, {244, 73}, {244, 74}, {244, 75}, {244, 76}, {244, 77}, {244, 78}, {244, 79}, {244, 80}, {244, 81}, {244, 82}, {244, 83}, {244, 84}, {244, 85}, {244, 86}, {244, 87}, {244, 88}, {244, 89}, {244, 90}, {244, 91}, {244, 92}, {244, 93}, {243, 94}, {242, 95}, {241, 96}, {240, 96}, {239, 96}, {238, 96}, {237, 96}, {236, 96}, {235, 96}, {234, 96}, {233, 96}, {232, 96}, {231, 96}, {230, 96}, {229, 96}, {228, 96}, {227, 96}, {226, 96}, {225, 96}, {224, 96}, {223, 96}, {222, 96}, {221, 96}, {220, 96}, {219, 96}, {218, 96}, {217, 96}, {216, 96}, {215, 96}, {214, 96}, {213, 96}, {212, 96}, {211, 96}, {210, 96}, {209, 96}, {208, 96}, {207, 96}, {206, 96}, {205, 96}, {204, 96}, {203, 96}, {202, 96}, {201, 96}, {200, 96}, {199, 96}, {198, 96}, {197, 96}, {196, 96}, {195, 96}, {194, 96}, {193, 96}, {192, 96}, {191, 96}, {190, 96}, {189, 96}, {188, 96}, {187, 96}, {186, 96}, {185, 96}, {184, 96}, {183, 96}, {182, 96}, {181, 96}, {180, 96}, {179, 96}, {178, 96}, {177, 96}, {176, 96}, {175, 96}, {174, 96}, {173, 96}, {172, 96}, {171, 96}, {170, 96}, {169, 96}, {168, 96}, {167, 96}, {166, 96}, {165, 96}, {164, 96}, {163, 96}, {162, 96}, {161, 96}, {160, 96}, {159, 96}}
};

static electronAnimation batteryElectronAnim = {
  126,
  {{63, 150}, {64, 150}, {65, 150}, {66, 150}, {67, 150}, {68, 150}, {69, 150}, {70, 150}, {71, 150}, {72, 150}, {73, 150}, {74, 150}, {75, 150}, {76, 150}, {77, 150}, {78, 150}, {79, 150}, {80, 150}, {81, 150}, {82, 150}, {83, 150}, {84, 150}, {85, 150}, {86, 150}, {87, 150}, {88, 150}, {89, 150}, {90, 150}, {91, 150}, {92, 150}, {93, 150}, {94, 150}, {95, 150}, {96, 150}, {97, 150}, {98, 150}, {99, 150}, {100, 150}, {101, 150}, {102, 150}, {103, 150}, {104, 150}, {105, 150}, {106, 150}, {107, 150}, {108, 150}, {109, 150}, {110, 150}, {111, 150}, {112, 150}, {113, 150}, {114, 150}, {115, 150}, {116, 150}, {117, 150}, {118, 150}, {119, 150}, {120, 150}, {121, 150}, {122, 150}, {123, 150}, {124, 150}, {125, 150}, {126, 150}, {127, 150}, {128, 150}, {129, 150}, {130, 150}, {131, 150}, {132, 150}, {133, 150}, {134, 150}, {135, 150}, {136, 150}, {137, 150}, {138, 150}, {139, 150}, {140, 150}, {141, 149}, {142, 148}, {143, 147}, {143, 146}, {143, 145}, {143, 144}, {143, 143}, {143, 142}, {143, 141}, {143, 140}, {143, 139}, {143, 138}, {143, 137}, {143, 136}, {143, 135}, {143, 134}, {143, 133}, {143, 132}, {143, 131}, {143, 130}, {143, 129}, {143, 128}, {143, 127}, {143, 126}, {143, 125}, {143, 124}, {143, 123}, {143, 122}, {143, 121}, {143, 120}, {143, 119}, {143, 118}, {143, 117}, {143, 116}, {143, 115}, {143, 114}, {143, 113}, {143, 112}, {143, 111}, {143, 110}, {143, 109}, {143, 108}, {143, 107}, {143, 106}, {143, 105}, {143, 104}, {143, 103}, {143, 102}}
};

static electronAnimation loadElectronAnim = {
  126,
  {{230, 150}, {229, 150}, {228, 150}, {227, 150}, {226, 150}, {225, 150}, {224, 150}, {223, 150}, {222, 150}, {221, 150}, {220, 150}, {219, 150}, {218, 150}, {217, 150}, {216, 150}, {215, 150}, {214, 150}, {213, 150}, {212, 150}, {211, 150}, {210, 150}, {209, 150}, {208, 150}, {207, 150}, {206, 150}, {205, 150}, {204, 150}, {203, 150}, {202, 150}, {201, 150}, {200, 150}, {199, 150}, {198, 150}, {197, 150}, {196, 150}, {195, 150}, {194, 150}, {193, 150}, {192, 150}, {191, 150}, {190, 150}, {189, 150}, {188, 150}, {187, 150}, {186, 150}, {185, 150}, {184, 150}, {183, 150}, {182, 150}, {181, 150}, {180, 150}, {179, 150}, {178, 150}, {177, 150}, {176, 150}, {175, 150}, {174, 150}, {173, 150}, {172, 150}, {171, 150}, {170, 150}, {169, 150}, {168, 150}, {167, 150}, {166, 150}, {165, 150}, {164, 150}, {163, 150}, {162, 150}, {161, 150}, {160, 150}, {159, 150}, {158, 150}, {157, 150}, {156, 150}, {155, 150}, {154, 150}, {153, 150}, {152, 149}, {151, 148}, {150, 147}, {150, 146}, {150, 145}, {150, 144}, {150, 143}, {150, 142}, {150, 141}, {150, 140}, {150, 139}, {150, 138}, {150, 137}, {150, 136}, {150, 135}, {150, 134}, {150, 133}, {150, 132}, {150, 131}, {150, 130}, {150, 129}, {150, 128}, {150, 127}, {150, 126}, {150, 125}, {150, 124}, {150, 123}, {150, 122}, {150, 121}, {150, 120}, {150, 119}, {150, 118}, {150, 117}, {150, 116}, {150, 115}, {150, 114}, {150, 113}, {150, 112}, {150, 111}, {150, 110}, {150, 109}, {150, 108}, {150, 107}, {150, 106}, {150, 105}, {150, 104}, {150, 103}, {150, 102}}
};

const lv_image_dsc_t *electronImages[5] = {
  &spark0,
  &spark1,
  &spark2,
  &spark3,
  &spark4
};

void timerCallback(lv_timer_t *timer)
{
  Flow *flow = (Flow *)lv_timer_get_user_data(timer);
  flow->redrawElectrons();
}


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

void CloseEventHandler(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);

  if (code == LV_EVENT_CLICKED)
  {
    DetailsWindow *win = (DetailsWindow *)e->user_data;
    delete win;
  }
}

DetailsWindow::DetailsWindow(char const *title)
{
  m_win = lv_win_create(lv_screen_active());
  lv_obj_set_pos(m_win, 0, 0);
  lv_obj_set_size(m_win, 320, 240);

  lv_win_add_title(m_win, title);

  lv_obj_t *btn = lv_win_add_button(m_win, LV_SYMBOL_CLOSE, 60);
  lv_obj_add_event_cb(btn, CloseEventHandler, LV_EVENT_CLICKED, this);

  lv_obj_set_height(lv_win_get_header(m_win), HEADER_HEIGHT);

  lv_obj_t *cont = lv_win_get_content(m_win);
  lv_obj_set_style_pad_all(cont, 0, LV_PART_MAIN);

  m_table = lv_table_create(cont);
  lv_obj_set_style_border_side(m_table, LV_BORDER_SIDE_NONE, LV_PART_MAIN);
  lv_table_set_column_width(m_table, 0, 220);
  lv_table_set_column_width(m_table, 1, 100);
  lv_obj_add_event_cb(m_table, onTableDraw, LV_EVENT_DRAW_TASK_ADDED, NULL);
  lv_obj_add_flag(m_table, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);

  m_nextLineIndex = 0;
}

DetailsWindow ::~DetailsWindow()
{
  lv_obj_delete(m_win);
}

void DetailsWindow::addParameter(char const *name, float value, char const *format)
{
  char val[16];
  sprintf(val, format, value);
  lv_table_set_cell_value(m_table, m_nextLineIndex, 0, name);
  lv_table_set_cell_value(m_table, m_nextLineIndex, 1, val);
  m_nextLineIndex++;
}

Flow::Flow(lv_obj_t *parent, Data *data)
{
  m_parent = parent;
  m_data = data;

  lv_obj_set_style_margin_all(parent, 0, LV_PART_MAIN);
  lv_obj_set_style_pad_all(parent, 0, LV_PART_MAIN);

  m_pvImage = lv_image_create(parent);
  lv_image_set_src(m_pvImage, &pv);
  lv_obj_set_pos(m_pvImage, 10, 5);
  lv_obj_add_flag(m_pvImage, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_event_cb(m_pvImage, onPvClicked, LV_EVENT_CLICKED, this);

  m_pvLabel = lv_label_create(parent);
  lv_obj_set_pos(m_pvLabel, 70, 92);
  lv_obj_set_width(m_pvLabel, 60);
  lv_label_set_text_fmt(m_pvLabel, "%.0fW", data->pv()->chargingPower());
  lv_obj_set_style_text_align(m_pvLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);

  m_gridImage = lv_image_create(parent);
  lv_image_set_src(m_gridImage, &grid);
  lv_obj_set_pos(m_gridImage, 208, 5);
  lv_obj_add_flag(m_gridImage, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_event_cb(m_gridImage, onGridClicked, LV_EVENT_CLICKED, this);

  m_gridLabel = lv_label_create(parent);
  lv_obj_set_pos(m_gridLabel, 190, 92);
  lv_obj_set_width(m_gridLabel, 60);
  lv_label_set_text_fmt(m_gridLabel, "%.0fA", data->grid()->current());
  lv_obj_set_style_text_align(m_gridLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);

  m_inverterImage = lv_image_create(parent);
  lv_image_set_src(m_inverterImage, &inverter);
  lv_obj_set_pos(m_inverterImage, 109, 65);
  lv_obj_add_flag(m_inverterImage, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_event_cb(m_inverterImage, onInverterClicked, LV_EVENT_CLICKED, this);

  m_mainLabel = lv_label_create(parent);
  lv_obj_set_pos(m_mainLabel, 115, 25);
  lv_obj_set_width(m_mainLabel, 90);
  lv_obj_set_style_text_align(m_mainLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
  lv_obj_set_style_text_font(m_mainLabel, &lv_font_montserrat_24, 0);
  lv_label_set_text_fmt(m_mainLabel, "%.0fV (%.0f%)", data->battery()->voltage(), data->battery()->soc());

  m_batteryImage = lv_image_create(parent);
  lv_image_set_src(m_batteryImage, &battery);
  lv_obj_set_pos(m_batteryImage, 10, 125);
  lv_obj_add_flag(m_batteryImage, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_event_cb(m_batteryImage, onBatteryClicked, LV_EVENT_CLICKED, this);

  m_batteryLabel = lv_label_create(parent);
  lv_obj_set_pos(m_batteryLabel, 90, 147);
  lv_obj_set_width(m_batteryLabel, 60);
  lv_label_set_text_fmt(m_batteryLabel, "%.0fA", data->battery()->current());
  lv_obj_set_style_text_align(m_batteryLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);

  m_loadImage = lv_image_create(parent);
  lv_image_set_src(m_loadImage, &load);
  lv_obj_set_pos(m_loadImage, 208, 125);
  lv_obj_add_flag(m_loadImage, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_event_cb(m_loadImage, onLoadClicked, LV_EVENT_CLICKED, this);

  m_loadLabel = lv_label_create(parent);
  lv_obj_set_pos(m_loadLabel, 170, 147);
  lv_obj_set_width(m_loadLabel, 60);
  lv_label_set_text_fmt(m_loadLabel, "%.0fW", data->load()->apparentPower());
  lv_obj_set_style_text_align(m_loadLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);

  m_pvFlowImage = lv_image_create(parent);
  lv_image_set_src(m_pvFlowImage, &pv_flow);
  lv_obj_set_pos(m_pvFlowImage, 61, 48);

  m_pvElectronImage = lv_animimg_create(parent);
  lv_animimg_set_src(m_pvElectronImage, (const void **)electronImages, 5);
  lv_animimg_set_duration(m_pvElectronImage, 500);
  lv_animimg_set_repeat_count(m_pvElectronImage, LV_ANIM_REPEAT_INFINITE);
  lv_animimg_start(m_pvElectronImage);
  //lv_obj_add_flag(m_pvElectronImage, LV_OBJ_FLAG_HIDDEN);

  m_gridFlowImage = lv_image_create(parent);
  lv_image_set_src(m_gridFlowImage, &grid_flow);
  lv_obj_set_pos(m_gridFlowImage, 169, 48);

  m_gridElectronImage = lv_animimg_create(parent);
  lv_animimg_set_src(m_gridElectronImage, (const void **)electronImages, 5);
  lv_animimg_set_duration(m_gridElectronImage, 500);
  lv_animimg_set_repeat_count(m_gridElectronImage, LV_ANIM_REPEAT_INFINITE);
  lv_animimg_start(m_gridElectronImage);
  lv_obj_add_flag(m_gridElectronImage, LV_OBJ_FLAG_HIDDEN);

  m_batteryFlowImage = lv_image_create(parent);
  lv_image_set_src(m_batteryFlowImage, &battery_flow);
  lv_obj_set_pos(m_batteryFlowImage, 71, 113);

  m_batteryElectronImage = lv_animimg_create(parent);
  lv_animimg_set_src(m_batteryElectronImage, (const void **)electronImages, 5);
  lv_animimg_set_duration(m_batteryElectronImage, 500);
  lv_animimg_set_repeat_count(m_batteryElectronImage, LV_ANIM_REPEAT_INFINITE);
  lv_animimg_start(m_batteryElectronImage);
  //lv_obj_add_flag(m_batteryElectronImage, LV_OBJ_FLAG_HIDDEN);

  m_loadFlowImage = lv_image_create(parent);
  lv_image_set_src(m_loadFlowImage, &load_flow);
  lv_obj_set_pos(m_loadFlowImage, 162, 113);

  m_loadElectronImage = lv_animimg_create(parent);
  lv_animimg_set_src(m_loadElectronImage, (const void **)electronImages, 5);
  lv_animimg_set_duration(m_loadElectronImage, 500);
  lv_animimg_set_repeat_count(m_loadElectronImage, LV_ANIM_REPEAT_INFINITE);
  lv_animimg_start(m_loadElectronImage);
  //lv_obj_add_flag(m_loadElectronImage, LV_OBJ_FLAG_HIDDEN);

  setPvStatus(1);
  setGridStatus(0);
  setInverterStatus(1);
  setBatteryStatus(-1);
  setLoadStatus(-1);

  m_drawStep = 0;

  lv_timer_create(timerCallback, 15, this);
}

void Flow::setPvStatus(int32_t status)
{
  updateOpacity(m_pvImage, status != 0);
  updateOpacity(m_pvFlowImage, status != 0);
}

void Flow::setGridStatus(int32_t status)
{
  updateOpacity(m_gridImage, status != 0);
  updateOpacity(m_gridFlowImage, status != 0);
}

void Flow::setInverterStatus(int32_t status)
{
  updateOpacity(m_inverterImage, status != 0);
}

void Flow::setBatteryStatus(int32_t status)
{
  updateOpacity(m_batteryImage, status != 0);
  updateOpacity(m_batteryFlowImage, status != 0);
}

void Flow::setLoadStatus(int32_t status)
{
  updateOpacity(m_loadImage, status != 0);
  updateOpacity(m_loadFlowImage, status != 0);
}

void Flow::updateOpacity(lv_obj_t *obj, bool opaque)
{
  lv_obj_set_style_image_recolor(obj, lv_color_black(), LV_PART_MAIN);
  lv_obj_set_style_image_recolor_opa(obj, opaque ? LV_OPA_TRANSP : LV_OPA_50, LV_PART_MAIN);
}

void Flow::showPvDetails()
{
  DetailsWindow *details = new DetailsWindow("PV details");
  details->addParameter("PV voltage (V)", 0.0, "%.1f V");
  details->addParameter("PV charging current (A)", 0.0, "%.1f A");
  details->addParameter("PV charging power (W)", 0.0, "%.0f W");
}

void Flow::showGridDetails()
{
  DetailsWindow *details = new DetailsWindow("Grid details");
  details->addParameter("Mains voltage (V)", 0.0, "%.1f V");
  details->addParameter("Grid current (A)", 0.0, "%.1f A");
  details->addParameter("Mains frequency (Hz)", 0.0, "%.2f Hz");
}

void Flow::showInverterDetails()
{
  DetailsWindow *details = new DetailsWindow("Inverter details");
  details->addParameter("Bus voltage (V)", 0.0, "%.1f V");
  details->addParameter("Mains charging current (A)", 0.0, "%.1f A");
  details->addParameter("PV charging current (A)", 0.0, "%.1f A");
  details->addParameter("Output voltage (V)", 0.0, "%.1f V");
  details->addParameter("Inverter current (A)", 0.0, "%.1f A");
  details->addParameter("Output frequency (Hz)", 0.0, "%.2f Hz");
}

void Flow::showBatteryDetails()
{
  DetailsWindow *details = new DetailsWindow("Battery details");
  details->addParameter("Battery voltage (V)", 0.0, "%.1f V");
  details->addParameter("Battery current (A)", 0.0, "%.1f A");
  details->addParameter("Battery level SOC (%)", 0.0, "%.0f %");
}

void Flow::showLoadDetails()
{
  DetailsWindow *details = new DetailsWindow("Load details");
  details->addParameter("Load current (A)", 0.0, "%.1f A");
  details->addParameter("Apparent power of load (VA)", 0.0, "%.0f VA");
  details->addParameter("Load rate (%)", 0.0, "%.0f %");
}

void Flow::redrawElectrons()
{
  if (!lv_obj_has_flag(m_pvElectronImage, LV_OBJ_FLAG_HIDDEN)) {
    uint32_t step = m_drawStep % pvElectronAnim.steps;
    lv_obj_set_pos(m_pvElectronImage, pvElectronAnim.positions[step].x, pvElectronAnim.positions[step].y);
  }
  if (!lv_obj_has_flag(m_gridElectronImage, LV_OBJ_FLAG_HIDDEN)) {
    uint32_t step = m_drawStep % gridElectronAnim.steps;
    lv_obj_set_pos(m_gridElectronImage, gridElectronAnim.positions[step].x, gridElectronAnim.positions[step].y);
  }
  if (!lv_obj_has_flag(m_batteryElectronImage, LV_OBJ_FLAG_HIDDEN)) {
    uint32_t step = m_drawStep % batteryElectronAnim.steps;
    lv_obj_set_pos(m_batteryElectronImage, batteryElectronAnim.positions[step].x, batteryElectronAnim.positions[step].y);
  }
  if (!lv_obj_has_flag(m_loadElectronImage, LV_OBJ_FLAG_HIDDEN)) {
    uint32_t step = m_drawStep % loadElectronAnim.steps;
    lv_obj_set_pos(m_loadElectronImage, loadElectronAnim.positions[step].x, loadElectronAnim.positions[step].y);
  }

  m_drawStep++;
}