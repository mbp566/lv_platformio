#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMAGE_SPARK1
#define LV_ATTRIBUTE_IMAGE_SPARK1
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMAGE_SPARK1 uint8_t spark1_map[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0xff, 0x07, 0xff, 0x07, 0x7f, 0x05, 0x1f, 0x06, 0x7f, 0x06, 0xbf, 0x06, 0xff, 0x06, 0xff, 0x06, 0x1f, 0x27, 0x1f, 0x06, 0x1f, 0x07, 0xbf, 0x06, 0x1f, 0x06, 0x7f, 0x05, 0xff, 0x07, 0xff, 0x07, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xff, 0x07, 0xff, 0x07, 0xff, 0x07, 0x7f, 0x05, 0x7f, 0x06, 0xbf, 0x06, 0x1f, 0x06, 0x7f, 0x06, 0xbf, 0x1e, 0xdf, 0x1e, 0x7f, 0x16, 0xbe, 0x26, 0xde, 0x1e, 0x7e, 0x16, 0x9f, 0x1e, 0x1f, 0x06, 0xff, 0x06, 0x1f, 0x06, 0x7f, 0x05, 0xff, 0x07, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xff, 0x07, 0xff, 0x07, 0x1f, 0x06, 0x7f, 0x06, 0x1f, 0x06, 0x9f, 0x1e, 0x5f, 0x16, 0xbf, 0x16, 0x7f, 0x16, 0xbf, 0x1e, 0xbf, 0x1e, 0x9f, 0x26, 0x9f, 0x16, 0x7f, 0x16, 0x9f, 0x16, 0x5f, 0x16, 0x9f, 0x1e, 0x7f, 0x06, 0x7f, 0x06, 0x7f, 0x05, 0xff, 0x07, 0xff, 0x07, 0x00, 0x00, 
  0xff, 0x07, 0xff, 0x07, 0x7f, 0x05, 0xbf, 0x06, 0x5f, 0x06, 0xdf, 0x1e, 0xbf, 0x16, 0xbf, 0x0e, 0x9f, 0x0e, 0xbf, 0x16, 0x9f, 0x1e, 0x7f, 0x1e, 0x9f, 0x16, 0x7f, 0x0e, 0xbf, 0x16, 0xbf, 0x26, 0x9f, 0x16, 0x3f, 0x06, 0xdf, 0x36, 0x9f, 0x1e, 0x7f, 0x06, 0x7f, 0x05, 0xff, 0x07, 0xff, 0x07, 
  0xff, 0x07, 0x7f, 0x05, 0xbf, 0x06, 0x1f, 0x06, 0x5f, 0x16, 0x5f, 0x16, 0x9f, 0x0e, 0x7f, 0x16, 0x9f, 0x16, 0x9f, 0x16, 0x7f, 0x1e, 0x9f, 0x16, 0x9f, 0x0e, 0x9f, 0x1e, 0x9f, 0x1e, 0xff, 0x56, 0x7f, 0x16, 0xdf, 0x46, 0xff, 0x66, 0xbf, 0x1e, 0x1f, 0x06, 0x7f, 0x06, 0x7f, 0x05, 0xff, 0x07, 
  0x7f, 0x05, 0x7f, 0x06, 0x1f, 0x06, 0xdf, 0x1e, 0x5f, 0x16, 0xbf, 0x26, 0x9f, 0x0e, 0x9f, 0x0e, 0x9f, 0x16, 0x7f, 0x16, 0x9f, 0x16, 0x9f, 0x0e, 0x9f, 0x1e, 0xff, 0x66, 0xbf, 0x2e, 0xff, 0x56, 0xdf, 0x46, 0x3f, 0x7f, 0x7f, 0x0e, 0xbf, 0x16, 0xdf, 0x1e, 0x1f, 0x06, 0x1f, 0x06, 0xff, 0x07, 
  0x7f, 0x05, 0xff, 0x06, 0x9f, 0x1e, 0xbf, 0x16, 0x7f, 0x0e, 0xdf, 0x36, 0xdf, 0x4e, 0x9f, 0x16, 0x9f, 0x0e, 0x7f, 0x16, 0x9f, 0x16, 0x9f, 0x26, 0x9f, 0x1e, 0xbf, 0x36, 0x1f, 0x6f, 0xff, 0x56, 0x3f, 0x7f, 0xff, 0x4e, 0x9f, 0x0e, 0xbf, 0x1e, 0xbf, 0x26, 0xfe, 0x2e, 0xff, 0x2e, 0x7f, 0x05, 
  0x7f, 0x06, 0x5f, 0x06, 0x7f, 0x16, 0x7f, 0x0e, 0x7f, 0x16, 0x7f, 0x0e, 0xdf, 0x3e, 0xdf, 0x46, 0x7f, 0x0e, 0x7f, 0x16, 0x9f, 0x1e, 0xdf, 0x4e, 0x9f, 0x26, 0xbf, 0x2e, 0x5f, 0x97, 0x1f, 0x6f, 0x5f, 0x87, 0x9f, 0x1e, 0x9f, 0x16, 0xbf, 0x1e, 0x9f, 0x26, 0xfe, 0x2e, 0x9d, 0x36, 0x7f, 0x06, 
  0xbf, 0x06, 0x9f, 0x1e, 0x5f, 0x16, 0x7f, 0x1e, 0x9f, 0x16, 0x9f, 0x16, 0x9f, 0x0e, 0xbf, 0x36, 0xff, 0x56, 0x9f, 0x1e, 0xbf, 0x36, 0xff, 0x4e, 0xdf, 0x3e, 0x3f, 0x7f, 0x5f, 0x87, 0xff, 0x5e, 0x9f, 0x16, 0x7f, 0x0e, 0x9f, 0x16, 0x9f, 0x16, 0xbf, 0x16, 0xdf, 0x16, 0x9f, 0x1e, 0xbf, 0x06, 
  0xff, 0x06, 0xdf, 0x1e, 0x9f, 0x16, 0x9f, 0x1e, 0x9f, 0x1e, 0x9f, 0x16, 0x9f, 0x16, 0x7f, 0x16, 0xdf, 0x3e, 0xff, 0x56, 0x1f, 0x67, 0x3f, 0x87, 0x5f, 0x97, 0x9f, 0xb7, 0x3f, 0x77, 0xbf, 0x2e, 0xbf, 0x26, 0xbf, 0x2e, 0x9f, 0x0e, 0x9f, 0x0e, 0x9f, 0x16, 0x7f, 0x16, 0xbf, 0x1e, 0xbf, 0x06, 
  0xff, 0x06, 0x5f, 0x16, 0xbf, 0x0e, 0x9f, 0x16, 0x9f, 0x16, 0x7f, 0x16, 0x9f, 0x16, 0x9f, 0x1e, 0xbf, 0x26, 0x1f, 0x6f, 0x9f, 0xb7, 0xdf, 0xdf, 0xbf, 0xd7, 0x5f, 0x9f, 0xbf, 0x36, 0x9f, 0x1e, 0xff, 0x5e, 0xff, 0x56, 0xbf, 0x2e, 0x9f, 0x0e, 0x7f, 0x16, 0x9f, 0x16, 0xdf, 0x1e, 0xff, 0x06, 
  0x1f, 0x06, 0x7f, 0x16, 0x7f, 0x0e, 0x9f, 0x0e, 0x7f, 0x0e, 0x9f, 0x0e, 0x7f, 0x16, 0x9f, 0x1e, 0xff, 0x4e, 0x5f, 0x97, 0xbf, 0xd7, 0xff, 0xf7, 0xdf, 0xe7, 0x3f, 0x77, 0xdf, 0x36, 0x1f, 0x67, 0x1f, 0x6f, 0xff, 0x56, 0xbf, 0x36, 0x9f, 0x16, 0x9f, 0x16, 0xbf, 0x0e, 0x5f, 0x16, 0xff, 0x06, 
  0x1f, 0x06, 0x7f, 0x16, 0x7f, 0x0e, 0xbf, 0x2e, 0xbf, 0x36, 0xbf, 0x26, 0xbf, 0x2e, 0x1f, 0x77, 0xff, 0x56, 0x5f, 0x97, 0xbf, 0xd7, 0xdf, 0xdf, 0xdf, 0xdf, 0xbf, 0xcf, 0x7f, 0xa7, 0xff, 0x5e, 0xbf, 0x36, 0x7f, 0x0e, 0x9f, 0x16, 0xff, 0x56, 0x7f, 0x16, 0xbf, 0x0e, 0x5f, 0x16, 0xff, 0x06, 
  0xff, 0x06, 0x5f, 0x16, 0x7f, 0x1e, 0xdf, 0x4e, 0xdf, 0x46, 0xdf, 0x3e, 0x5f, 0x97, 0xff, 0x4e, 0x9f, 0x0e, 0xff, 0x56, 0x7f, 0x9f, 0xbf, 0xc7, 0x3f, 0x87, 0x3f, 0x87, 0x7f, 0x9f, 0x5f, 0x97, 0x3f, 0x87, 0x1f, 0x6f, 0x3f, 0x7f, 0xdf, 0x3e, 0x5f, 0x0e, 0x9f, 0x16, 0x5f, 0x16, 0xff, 0x06, 
  0xff, 0x06, 0xdf, 0x1e, 0x9f, 0x16, 0x7f, 0x0e, 0xdf, 0x3e, 0xff, 0x5e, 0xdf, 0x4e, 0x9f, 0x16, 0x9f, 0x26, 0xff, 0x56, 0x3f, 0x87, 0x5f, 0x97, 0xdf, 0x3e, 0xbf, 0x2e, 0x1f, 0x5f, 0xff, 0x56, 0x1f, 0x67, 0x1f, 0x6f, 0x1f, 0x77, 0x1f, 0x6f, 0x7f, 0x0e, 0xbf, 0x06, 0xbf, 0x1e, 0xbf, 0x06, 
  0xbf, 0x06, 0x9f, 0x1e, 0x9f, 0x16, 0xbf, 0x2e, 0x1f, 0x5f, 0xbf, 0x36, 0x7f, 0x06, 0x7f, 0x0e, 0xbf, 0x2e, 0x5f, 0x8f, 0x5f, 0x97, 0xff, 0x46, 0x9f, 0x16, 0x9f, 0x16, 0xbf, 0x2e, 0xdf, 0x4e, 0xdf, 0x46, 0x1f, 0x6f, 0xff, 0x5e, 0x3f, 0x77, 0x3f, 0x6f, 0xdf, 0x3e, 0x1f, 0x06, 0x7f, 0x06, 
  0x7f, 0x06, 0x5f, 0x06, 0x5f, 0x16, 0xbf, 0x26, 0xff, 0x46, 0x7f, 0x0e, 0x9f, 0x0e, 0x7f, 0x0e, 0xff, 0x66, 0x3f, 0x87, 0xff, 0x4e, 0x7f, 0x16, 0x9f, 0x16, 0x7f, 0x16, 0x7f, 0x0e, 0x9f, 0x16, 0xbf, 0x26, 0xbf, 0x26, 0x7f, 0x06, 0x7f, 0x06, 0x9f, 0x26, 0xdf, 0x36, 0x1f, 0x06, 0x1f, 0x06, 
  0x1f, 0x06, 0xff, 0x06, 0xbf, 0x1e, 0xbf, 0x16, 0x7f, 0x0e, 0x9f, 0x16, 0x7f, 0x16, 0x9f, 0x16, 0xff, 0x56, 0xff, 0x56, 0x3f, 0x6f, 0x9f, 0x16, 0x9f, 0x0e, 0x9f, 0x0e, 0x9f, 0x16, 0x9f, 0x16, 0x9f, 0x0e, 0x7f, 0x0e, 0x9f, 0x16, 0x9f, 0x0e, 0x9f, 0x16, 0x1f, 0x06, 0xff, 0x06, 0x7f, 0x05, 
  0x7f, 0x05, 0x7f, 0x06, 0x1f, 0x06, 0xdf, 0x1e, 0x7f, 0x16, 0x7f, 0x16, 0x9f, 0x16, 0x9f, 0x2e, 0x5f, 0x87, 0x3f, 0x77, 0xff, 0x56, 0x7f, 0x0e, 0x9f, 0x16, 0x7f, 0x16, 0x7f, 0x16, 0x9f, 0x16, 0x9f, 0x16, 0x9f, 0x16, 0x9f, 0x0e, 0x5f, 0x16, 0xdf, 0x1e, 0x1f, 0x06, 0x7f, 0x06, 0xff, 0x07, 
  0xff, 0x07, 0x7f, 0x05, 0xbf, 0x06, 0x5f, 0x26, 0x9f, 0x16, 0x9f, 0x26, 0x7f, 0x1e, 0xbf, 0x2e, 0x9f, 0xaf, 0xdf, 0x46, 0x7f, 0x0e, 0x7f, 0x16, 0x7f, 0x16, 0x7f, 0x16, 0x9f, 0x16, 0x9f, 0x1e, 0x9f, 0x1e, 0x7f, 0x16, 0x5f, 0x16, 0x5f, 0x16, 0x5f, 0x06, 0x7f, 0x06, 0x7f, 0x05, 0xff, 0x07, 
  0xff, 0x07, 0xff, 0x07, 0x7f, 0x36, 0x3c, 0x3f, 0xfe, 0x36, 0x9e, 0x36, 0xdf, 0x26, 0x9f, 0x16, 0xbf, 0x3e, 0x7f, 0x0e, 0x9f, 0x16, 0x9f, 0x16, 0x9f, 0x16, 0x9f, 0x16, 0x7f, 0x16, 0x7f, 0x1e, 0x9f, 0x26, 0xdf, 0x26, 0x7f, 0x16, 0x5f, 0x06, 0xbf, 0x06, 0x1f, 0x06, 0xff, 0x07, 0xff, 0x07, 
  0xff, 0x07, 0xff, 0x5f, 0x7a, 0x6e, 0x1c, 0x67, 0x3c, 0x3f, 0x5f, 0x1f, 0x9f, 0x1e, 0x5f, 0x16, 0x5f, 0x06, 0x9f, 0x16, 0xbf, 0x0e, 0x7f, 0x0e, 0x7f, 0x0e, 0xbf, 0x0e, 0x9f, 0x16, 0xbf, 0x16, 0x5e, 0x1e, 0xbe, 0x2e, 0xdd, 0x3e, 0x1c, 0x27, 0x1f, 0x06, 0xff, 0x07, 0xff, 0x07, 0xff, 0x07, 
  0x00, 0x00, 0x10, 0x84, 0xf5, 0x5f, 0xff, 0x5f, 0x7f, 0x05, 0x7f, 0x06, 0xff, 0x06, 0x5f, 0x06, 0x9f, 0x1e, 0xdf, 0x1e, 0x5f, 0x16, 0x7f, 0x16, 0x7f, 0x16, 0x5f, 0x16, 0xbf, 0x1e, 0x9f, 0x1e, 0x1f, 0x06, 0x1f, 0x27, 0x1c, 0x47, 0xfb, 0x4e, 0x7a, 0x6e, 0xff, 0x87, 0xff, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0xff, 0x07, 0xff, 0x07, 0x7f, 0x05, 0x1f, 0x06, 0x7f, 0x06, 0xbf, 0x06, 0xff, 0x06, 0xff, 0x06, 0x1f, 0x06, 0x1f, 0x06, 0xff, 0x06, 0xbf, 0x06, 0xbf, 0x06, 0x7f, 0x06, 0x7f, 0x05, 0xff, 0x07, 0xff, 0x07, 0xff, 0x87, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 

  0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x07, 0x08, 0x08, 0x08, 0x06, 0x04, 0x03, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 
  0x00, 0x01, 0x01, 0x02, 0x03, 0x05, 0x06, 0x08, 0x0a, 0x0c, 0x0d, 0x0f, 0x11, 0x13, 0x0f, 0x0b, 0x08, 0x07, 0x04, 0x03, 0x02, 0x01, 0x00, 0x00, 
  0x00, 0x01, 0x02, 0x04, 0x05, 0x08, 0x0b, 0x0e, 0x11, 0x14, 0x18, 0x1d, 0x20, 0x1c, 0x14, 0x10, 0x0e, 0x0b, 0x05, 0x05, 0x03, 0x02, 0x01, 0x00, 
  0x01, 0x02, 0x03, 0x06, 0x09, 0x0d, 0x12, 0x17, 0x1b, 0x22, 0x2c, 0x33, 0x2c, 0x23, 0x22, 0x24, 0x15, 0x0d, 0x1a, 0x0b, 0x05, 0x03, 0x02, 0x01, 
  0x02, 0x03, 0x06, 0x08, 0x0e, 0x12, 0x1a, 0x23, 0x2a, 0x39, 0x4a, 0x46, 0x39, 0x3a, 0x34, 0x4d, 0x24, 0x35, 0x3b, 0x0c, 0x08, 0x05, 0x03, 0x02, 
  0x03, 0x05, 0x08, 0x0d, 0x13, 0x24, 0x25, 0x31, 0x3e, 0x57, 0x6b, 0x58, 0x55, 0x79, 0x52, 0x68, 0x51, 0x6c, 0x19, 0x12, 0x0d, 0x08, 0x04, 0x02, 
  0x03, 0x07, 0x0b, 0x12, 0x19, 0x38, 0x55, 0x45, 0x54, 0x75, 0x8c, 0x80, 0x76, 0x7f, 0x94, 0x76, 0x8b, 0x63, 0x27, 0x23, 0x17, 0x0e, 0x07, 0x03, 
  0x05, 0x09, 0x0f, 0x18, 0x23, 0x2d, 0x5d, 0x77, 0x6a, 0x90, 0xb2, 0xb7, 0x9c, 0x9b, 0xc3, 0xab, 0xb4, 0x60, 0x43, 0x30, 0x21, 0x15, 0x0b, 0x05, 
  0x06, 0x0b, 0x13, 0x23, 0x36, 0x45, 0x54, 0x80, 0xa4, 0xab, 0xd6, 0xda, 0xc9, 0xdc, 0xdc, 0xbe, 0x81, 0x5a, 0x42, 0x2c, 0x1d, 0x13, 0x0b, 0x06, 
  0x07, 0x0d, 0x15, 0x2b, 0x4a, 0x64, 0x79, 0x8b, 0xb3, 0xd1, 0xee, 0xf8, 0xf7, 0xfa, 0xe1, 0xac, 0x88, 0x6c, 0x43, 0x31, 0x20, 0x14, 0x0c, 0x06, 
  0x07, 0x0e, 0x17, 0x26, 0x3f, 0x67, 0x92, 0xb5, 0xcc, 0xe9, 0xfc, 0xff, 0xff, 0xf9, 0xd4, 0xb1, 0xaa, 0x8d, 0x5d, 0x34, 0x24, 0x16, 0x0d, 0x07, 
  0x08, 0x0f, 0x19, 0x25, 0x38, 0x54, 0x7d, 0xb2, 0xe3, 0xfb, 0xff, 0xff, 0xff, 0xf8, 0xdf, 0xd2, 0xb8, 0x93, 0x62, 0x3b, 0x27, 0x17, 0x0e, 0x07, 
  0x08, 0x0f, 0x18, 0x37, 0x54, 0x62, 0x81, 0xc1, 0xd4, 0xf4, 0xff, 0xff, 0xff, 0xff, 0xf6, 0xd2, 0xa2, 0x6e, 0x54, 0x5c, 0x28, 0x17, 0x0e, 0x07, 
  0x07, 0x0e, 0x19, 0x4a, 0x57, 0x6e, 0xb6, 0xae, 0xb1, 0xe0, 0xfb, 0xff, 0xfa, 0xf8, 0xf6, 0xe4, 0xc5, 0xa2, 0x8a, 0x4a, 0x21, 0x16, 0x0e, 0x07, 
  0x07, 0x0d, 0x15, 0x1d, 0x47, 0x79, 0x84, 0x82, 0xa6, 0xd5, 0xf3, 0xf8, 0xe3, 0xd6, 0xe0, 0xcc, 0xaa, 0x97, 0x81, 0x63, 0x1d, 0x11, 0x0c, 0x06, 
  0x06, 0x0b, 0x10, 0x2d, 0x5c, 0x55, 0x51, 0x6e, 0x97, 0xdb, 0xed, 0xd3, 0xbc, 0xb2, 0xb7, 0xb3, 0x8b, 0x80, 0x6f, 0x69, 0x4e, 0x27, 0x08, 0x05, 
  0x05, 0x09, 0x0e, 0x22, 0x3e, 0x33, 0x46, 0x5a, 0xa7, 0xcd, 0xbb, 0x9a, 0x97, 0x90, 0x8f, 0x86, 0x66, 0x4a, 0x2b, 0x1d, 0x20, 0x20, 0x08, 0x04, 
  0x04, 0x07, 0x0c, 0x11, 0x18, 0x27, 0x37, 0x53, 0x8f, 0x9e, 0xa5, 0x75, 0x74, 0x6f, 0x72, 0x6d, 0x4a, 0x33, 0x27, 0x1b, 0x10, 0x08, 0x07, 0x03, 
  0x03, 0x05, 0x08, 0x0d, 0x14, 0x1e, 0x2f, 0x4f, 0x99, 0x94, 0x7a, 0x52, 0x55, 0x51, 0x52, 0x57, 0x3c, 0x27, 0x1c, 0x13, 0x0d, 0x08, 0x05, 0x02, 
  0x02, 0x03, 0x06, 0x09, 0x10, 0x1b, 0x28, 0x3b, 0x9b, 0x58, 0x33, 0x3c, 0x3c, 0x38, 0x36, 0x3e, 0x32, 0x1e, 0x13, 0x0e, 0x09, 0x05, 0x03, 0x02, 
  0x01, 0x02, 0x05, 0x09, 0x0f, 0x16, 0x19, 0x1c, 0x31, 0x1e, 0x25, 0x27, 0x27, 0x25, 0x22, 0x23, 0x25, 0x1a, 0x0f, 0x09, 0x06, 0x04, 0x02, 0x01, 
  0x01, 0x03, 0x05, 0x08, 0x09, 0x0a, 0x0b, 0x0e, 0x0e, 0x15, 0x17, 0x18, 0x19, 0x17, 0x15, 0x12, 0x13, 0x12, 0x0d, 0x08, 0x04, 0x02, 0x01, 0x01, 
  0x01, 0x02, 0x03, 0x03, 0x03, 0x05, 0x07, 0x09, 0x0b, 0x0d, 0x0e, 0x0f, 0x0f, 0x0e, 0x0c, 0x0b, 0x08, 0x08, 0x08, 0x07, 0x05, 0x02, 0x01, 0x00, 
  0x00, 0x00, 0x01, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x07, 0x08, 0x08, 0x07, 0x06, 0x06, 0x05, 0x03, 0x02, 0x03, 0x02, 0x01, 0x00, 0x00, 
};

const lv_image_dsc_t spark1 = {
  .header.cf = LV_COLOR_FORMAT_RGB565A8,
  .header.magic = LV_IMAGE_HEADER_MAGIC,
  .header.w = 24,
  .header.h = 24,
  .data_size = 576 * 3,
  .data = spark1_map,
};
