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

#ifndef LV_ATTRIBUTE_IMAGE_SPARK0
#define LV_ATTRIBUTE_IMAGE_SPARK0
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMAGE_SPARK0 uint8_t spark0_map[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0xff, 0x07, 0x7f, 0x05, 0x7f, 0x05, 0x1f, 0x06, 0x7f, 0x06, 0xbf, 0x06, 0xff, 0x06, 0xff, 0x06, 0x7d, 0x1e, 0x9d, 0x1e, 0x1f, 0x07, 0x7f, 0x06, 0x1f, 0x06, 0x7f, 0x05, 0xff, 0x07, 0xff, 0x07, 0xff, 0x07, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0x18, 0x46, 0x7a, 0x36, 0x7f, 0x06, 0xbf, 0x06, 0x1f, 0x06, 0x7f, 0x06, 0xbf, 0x1e, 0xdf, 0x1e, 0x7f, 0x16, 0x9e, 0x26, 0xde, 0x1e, 0xbf, 0x1e, 0x7f, 0x06, 0x1f, 0x06, 0xff, 0x06, 0x1f, 0x06, 0x7f, 0x05, 0xff, 0x07, 0xff, 0x87, 0xff, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0xff, 0x07, 0xff, 0x07, 0xbb, 0x5e, 0x3c, 0x3f, 0x1f, 0x27, 0x9f, 0x06, 0x5f, 0x16, 0xbf, 0x16, 0x7f, 0x16, 0x9f, 0x16, 0x9f, 0x16, 0x7f, 0x26, 0xbf, 0x16, 0x7f, 0x16, 0xbf, 0x16, 0x5f, 0x16, 0x9f, 0x1e, 0xff, 0x06, 0x7f, 0x06, 0x7f, 0x36, 0x7a, 0x6e, 0x75, 0x5d, 0xff, 0x07, 
  0xff, 0x07, 0xff, 0x07, 0x1f, 0x06, 0x7d, 0x36, 0xfe, 0x36, 0xdf, 0x1e, 0xbf, 0x16, 0xbf, 0x0e, 0x9f, 0x0e, 0x9f, 0x16, 0x7f, 0x16, 0x9f, 0x16, 0x7f, 0x1e, 0x9f, 0x16, 0x9f, 0x16, 0x9f, 0x0e, 0x9f, 0x16, 0xbf, 0x16, 0xbf, 0x1e, 0x1f, 0x27, 0x3c, 0x3f, 0xfb, 0x4e, 0xff, 0x5f, 0xff, 0x07, 
  0xff, 0x07, 0x7f, 0x05, 0x7f, 0x06, 0x9f, 0x1e, 0x1f, 0x6f, 0xff, 0x2e, 0x7f, 0x06, 0x9f, 0x0e, 0x9f, 0x16, 0x9f, 0x0e, 0x9f, 0x16, 0x7f, 0x16, 0x7f, 0x16, 0x9f, 0x16, 0x9f, 0x0e, 0x7f, 0x16, 0x7f, 0x16, 0x9f, 0x0e, 0x5f, 0x16, 0xde, 0x2e, 0x7e, 0x4e, 0x1c, 0x47, 0x7f, 0x05, 0xff, 0x07, 
  0x7f, 0x05, 0x7f, 0x06, 0x1f, 0x06, 0x9f, 0x1e, 0xbf, 0x36, 0x3f, 0x7f, 0xdf, 0x4e, 0x9f, 0x16, 0x9f, 0x0e, 0x7f, 0x0e, 0x9f, 0x16, 0x9f, 0x16, 0x7f, 0x16, 0x9f, 0x16, 0x7f, 0x0e, 0x7f, 0x16, 0x9f, 0x0e, 0x5f, 0x0e, 0xbf, 0x2e, 0xff, 0x5e, 0xbe, 0x2e, 0x3f, 0x27, 0x7f, 0x06, 0xff, 0x07, 
  0x7f, 0x05, 0xff, 0x06, 0x9f, 0x1e, 0xbf, 0x16, 0x9f, 0x0e, 0xbf, 0x2e, 0x3f, 0x77, 0x7f, 0x9f, 0xdf, 0x36, 0x7f, 0x06, 0x7f, 0x16, 0x7f, 0x16, 0x9f, 0x16, 0x9f, 0x16, 0x7f, 0x16, 0x9f, 0x16, 0x7f, 0x0e, 0xdf, 0x3e, 0x1f, 0x67, 0x9e, 0x2e, 0x9e, 0x1e, 0x7f, 0x1e, 0xbf, 0x06, 0x7f, 0x05, 
  0x7f, 0x06, 0x5f, 0x06, 0x5f, 0x16, 0x9f, 0x16, 0xff, 0x4e, 0x1f, 0x67, 0xff, 0x56, 0x1f, 0x6f, 0x1f, 0x67, 0xbf, 0x36, 0x7f, 0x0e, 0x9f, 0x1e, 0x9f, 0x1e, 0x9f, 0x16, 0x9f, 0x0e, 0x7f, 0x0e, 0xdf, 0x46, 0xff, 0x4e, 0x9f, 0x16, 0xbf, 0x1e, 0xbf, 0x0e, 0xdf, 0x1e, 0x1f, 0x06, 0x1f, 0x06, 
  0xbf, 0x06, 0x9f, 0x1e, 0xbf, 0x16, 0x7f, 0x16, 0xbf, 0x2e, 0x9f, 0x16, 0xdf, 0x4e, 0x3f, 0x77, 0x3f, 0x7f, 0xff, 0x5e, 0xbf, 0x2e, 0xbf, 0x2e, 0xdf, 0x36, 0x9f, 0x1e, 0x7f, 0x0e, 0xbf, 0x36, 0xff, 0x66, 0x9f, 0x16, 0x9f, 0x16, 0xbf, 0x16, 0x9f, 0x0e, 0xbf, 0x16, 0x7f, 0x06, 0x7f, 0x06, 
  0xff, 0x06, 0xdf, 0x1e, 0x9f, 0x16, 0x9f, 0x0e, 0x7f, 0x16, 0xff, 0x56, 0xff, 0x5e, 0xff, 0x56, 0x5f, 0x8f, 0x7f, 0x9f, 0x7f, 0x9f, 0x3f, 0x77, 0x1f, 0x67, 0xbf, 0x2e, 0xff, 0x56, 0xff, 0x5e, 0x9f, 0x16, 0x9f, 0x16, 0x9f, 0x16, 0x9f, 0x0e, 0x9f, 0x16, 0x7f, 0x16, 0xbf, 0x1e, 0xbf, 0x06, 
  0xff, 0x06, 0x5f, 0x16, 0xbf, 0x0e, 0x9f, 0x16, 0x7f, 0x0e, 0xbf, 0x26, 0xbf, 0x2e, 0x7f, 0x0e, 0xdf, 0x3e, 0x7f, 0x9f, 0xbf, 0xcf, 0xbf, 0xd7, 0x7f, 0xaf, 0x3f, 0x87, 0x3f, 0x7f, 0xbf, 0x2e, 0x9f, 0x0e, 0x9f, 0x16, 0x9f, 0x16, 0x9f, 0x16, 0x7f, 0x16, 0x9f, 0x16, 0xdf, 0x1e, 0xff, 0x06, 
  0x1f, 0x06, 0x7f, 0x16, 0x7f, 0x0e, 0x9f, 0x16, 0x7f, 0x16, 0x9f, 0x0e, 0x9f, 0x16, 0xff, 0x56, 0xff, 0x56, 0x3f, 0x87, 0xbf, 0xd7, 0xff, 0xef, 0xdf, 0xe7, 0x7f, 0xaf, 0xdf, 0x46, 0x9f, 0x1e, 0x9f, 0x0e, 0x7f, 0x0e, 0x7f, 0x16, 0x9f, 0x16, 0x9f, 0x16, 0x7f, 0x0e, 0x5f, 0x16, 0xff, 0x06, 
  0x1f, 0x06, 0x7f, 0x16, 0x7f, 0x0e, 0x7f, 0x16, 0x7f, 0x16, 0x7f, 0x16, 0x7f, 0x0e, 0xbf, 0x26, 0xbf, 0x2e, 0xff, 0x56, 0xbf, 0xcf, 0xff, 0xf7, 0xff, 0xef, 0x9f, 0xb7, 0x3f, 0x87, 0xdf, 0x46, 0x9f, 0x16, 0x7f, 0x0e, 0x7f, 0x0e, 0x9f, 0x16, 0x9f, 0x16, 0x7f, 0x0e, 0x5f, 0x16, 0xff, 0x06, 
  0xff, 0x06, 0x5f, 0x16, 0x7f, 0x0e, 0x9f, 0x16, 0x9f, 0x16, 0x7f, 0x0e, 0x9f, 0x26, 0xff, 0x4e, 0x1f, 0x67, 0x5f, 0x97, 0xbf, 0xd7, 0x9f, 0xbf, 0x9f, 0xbf, 0x7f, 0xa7, 0xff, 0x5e, 0x3f, 0x7f, 0xbf, 0x36, 0x9f, 0x1e, 0x9f, 0x16, 0x9f, 0x0e, 0x7f, 0x16, 0x9f, 0x16, 0x5f, 0x16, 0xff, 0x06, 
  0xff, 0x06, 0xdf, 0x1e, 0x9f, 0x16, 0x7f, 0x16, 0x7f, 0x0e, 0x9f, 0x26, 0xff, 0x5e, 0xdf, 0x36, 0x5f, 0x8f, 0x7f, 0xaf, 0x5f, 0x8f, 0xdf, 0x46, 0xff, 0x5e, 0x1f, 0x5f, 0xff, 0x56, 0x5f, 0x8f, 0x3f, 0x7f, 0x3f, 0x77, 0x3f, 0x77, 0x9f, 0x0e, 0x9f, 0x0e, 0x7f, 0x16, 0xbf, 0x1e, 0xbf, 0x06, 
  0xbf, 0x06, 0x9f, 0x1e, 0xbf, 0x16, 0x9f, 0x0e, 0x9f, 0x1e, 0xff, 0x56, 0xdf, 0x46, 0x5f, 0x97, 0x5f, 0x97, 0x1f, 0x67, 0xff, 0x56, 0x9f, 0x0e, 0xff, 0x4e, 0x9f, 0x1e, 0xbf, 0x36, 0xff, 0x4e, 0x3f, 0x87, 0xff, 0x56, 0x3f, 0x7f, 0xdf, 0x46, 0x9f, 0x06, 0xbf, 0x16, 0x7f, 0x06, 0x7f, 0x06, 
  0x7f, 0x06, 0x5f, 0x06, 0x7f, 0x16, 0xbf, 0x0e, 0x9f, 0x0e, 0xff, 0x66, 0x3f, 0x77, 0x1f, 0x6f, 0xff, 0x4e, 0xdf, 0x46, 0x3f, 0x7f, 0x9f, 0x1e, 0xff, 0x56, 0x9f, 0x1e, 0x7f, 0x0e, 0x9f, 0x16, 0xbf, 0x3e, 0xff, 0x56, 0x7f, 0x9f, 0x7f, 0xaf, 0xbf, 0x26, 0xbf, 0x06, 0x5f, 0x06, 0x1f, 0x06, 
  0x1f, 0x06, 0xff, 0x06, 0xbf, 0x1e, 0x9f, 0x16, 0xbf, 0x1e, 0x3f, 0x87, 0x3f, 0x7f, 0x5f, 0x87, 0x7f, 0x06, 0xdf, 0x46, 0x1f, 0x6f, 0xdf, 0x3e, 0xff, 0x4e, 0x5f, 0x8f, 0x9f, 0x26, 0x7f, 0x16, 0x9f, 0x0e, 0x7f, 0x0e, 0xbf, 0x26, 0xbf, 0x2e, 0x9f, 0x1e, 0x7f, 0x06, 0xbf, 0x06, 0x7f, 0x05, 
  0x7f, 0x05, 0x7f, 0x06, 0x5f, 0x26, 0x7e, 0x26, 0x3f, 0x7f, 0x5f, 0x8f, 0x1f, 0x67, 0x1f, 0x67, 0x7f, 0x06, 0xff, 0x5e, 0x1f, 0x5f, 0xbf, 0x3e, 0x9f, 0x1e, 0x3f, 0x77, 0xff, 0x5e, 0x7f, 0x0e, 0x9f, 0x16, 0xbf, 0x1e, 0x9f, 0x16, 0xbf, 0x16, 0xbf, 0x1e, 0x1f, 0x06, 0x7f, 0x06, 0xff, 0x07, 
  0xff, 0x07, 0x7f, 0x36, 0xfb, 0x4e, 0x3f, 0x87, 0x3f, 0x6f, 0xdf, 0x16, 0xbf, 0x16, 0xff, 0x5e, 0xbf, 0x2e, 0xbf, 0x1e, 0x9f, 0x16, 0x7f, 0x0e, 0xdf, 0x3e, 0xbf, 0x36, 0x1f, 0x67, 0xbf, 0x3e, 0x7f, 0x16, 0x9f, 0x1e, 0x9f, 0x26, 0xbe, 0x26, 0x5f, 0x26, 0x7f, 0x06, 0x7f, 0x05, 0xff, 0x07, 
  0xff, 0x87, 0x7a, 0x6e, 0x1c, 0x47, 0x3e, 0x3f, 0xff, 0x06, 0xbf, 0x1e, 0xbf, 0x16, 0x7f, 0x0e, 0xbf, 0x1e, 0x9f, 0x0e, 0x9f, 0x0e, 0x5f, 0x06, 0xff, 0x56, 0xff, 0x46, 0xbf, 0x36, 0x1f, 0x6f, 0xbf, 0x2e, 0x5f, 0x16, 0x7e, 0x2e, 0xfe, 0x36, 0xfb, 0x2e, 0x1f, 0x06, 0xff, 0x07, 0xff, 0x07, 
  0xff, 0x07, 0xff, 0x07, 0x7f, 0x05, 0xff, 0x07, 0x7f, 0x06, 0x1f, 0x06, 0x9f, 0x1e, 0x5f, 0x16, 0xbf, 0x16, 0x9f, 0x16, 0xbf, 0x0e, 0x9f, 0x16, 0xbf, 0x2e, 0xdf, 0x2e, 0xbf, 0x06, 0xbf, 0x36, 0x9f, 0x16, 0x9f, 0x1e, 0x5f, 0x26, 0x1c, 0x47, 0x7f, 0x36, 0xff, 0x07, 0xff, 0x07, 0xff, 0x07, 
  0x00, 0x00, 0xff, 0x07, 0xff, 0x07, 0xff, 0x07, 0x7f, 0x05, 0x7f, 0x06, 0xff, 0x06, 0x5f, 0x06, 0x9f, 0x1e, 0xdf, 0x1e, 0x5f, 0x16, 0x7f, 0x16, 0xbf, 0x06, 0xbf, 0x06, 0xdf, 0x1e, 0x5f, 0x06, 0x1f, 0x06, 0xff, 0x06, 0x7f, 0x06, 0x7f, 0x05, 0xff, 0x07, 0xff, 0x07, 0xff, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0xff, 0x07, 0xff, 0x07, 0x7f, 0x05, 0x1f, 0x06, 0x7f, 0x06, 0xbf, 0x06, 0xff, 0x06, 0xff, 0x06, 0x1f, 0x06, 0x1f, 0x06, 0xff, 0x06, 0xbf, 0x06, 0xbf, 0x06, 0x7f, 0x06, 0x7f, 0x05, 0x7f, 0x05, 0xff, 0x07, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

  0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x03, 0x04, 0x05, 0x06, 0x07, 0x07, 0x0a, 0x0b, 0x08, 0x05, 0x04, 0x03, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0x02, 0x04, 0x05, 0x05, 0x06, 0x08, 0x0a, 0x0c, 0x0d, 0x0f, 0x16, 0x14, 0x0c, 0x0a, 0x08, 0x07, 0x04, 0x03, 0x02, 0x02, 0x01, 0x00, 
  0x00, 0x01, 0x02, 0x06, 0x09, 0x08, 0x0b, 0x0e, 0x11, 0x14, 0x16, 0x1b, 0x24, 0x1d, 0x14, 0x11, 0x0e, 0x0b, 0x07, 0x05, 0x05, 0x05, 0x03, 0x01, 
  0x01, 0x02, 0x04, 0x0a, 0x0f, 0x0d, 0x11, 0x17, 0x1c, 0x20, 0x23, 0x2b, 0x38, 0x2b, 0x20, 0x1b, 0x16, 0x11, 0x0c, 0x08, 0x09, 0x07, 0x03, 0x01, 
  0x02, 0x03, 0x05, 0x0b, 0x39, 0x23, 0x14, 0x21, 0x2b, 0x31, 0x36, 0x41, 0x52, 0x41, 0x31, 0x29, 0x22, 0x1a, 0x12, 0x14, 0x0f, 0x08, 0x03, 0x02, 
  0x03, 0x05, 0x08, 0x0b, 0x28, 0x69, 0x51, 0x34, 0x3a, 0x48, 0x4e, 0x5d, 0x70, 0x5b, 0x47, 0x3c, 0x31, 0x21, 0x29, 0x37, 0x12, 0x09, 0x05, 0x02, 
  0x03, 0x07, 0x0b, 0x11, 0x1a, 0x45, 0x83, 0xa8, 0x69, 0x5d, 0x6c, 0x7f, 0x93, 0x7a, 0x61, 0x53, 0x3d, 0x50, 0x5e, 0x2c, 0x16, 0x0a, 0x06, 0x03, 
  0x05, 0x09, 0x0e, 0x16, 0x3f, 0x74, 0x7d, 0x92, 0x9e, 0x8d, 0x8d, 0xa8, 0xb9, 0x99, 0x7d, 0x69, 0x72, 0x70, 0x43, 0x2f, 0x17, 0x0d, 0x08, 0x04, 
  0x06, 0x0b, 0x12, 0x1e, 0x36, 0x44, 0x8b, 0xb8, 0xbf, 0xba, 0xb9, 0xd2, 0xdb, 0xb7, 0x9c, 0x99, 0xa7, 0x6f, 0x51, 0x2e, 0x1b, 0x11, 0x0a, 0x05, 
  0x07, 0x0d, 0x15, 0x21, 0x32, 0x68, 0x95, 0xba, 0xe3, 0xe8, 0xef, 0xf5, 0xf2, 0xd7, 0xd4, 0xce, 0xa1, 0x78, 0x4c, 0x30, 0x20, 0x14, 0x0c, 0x06, 
  0x07, 0x0e, 0x17, 0x25, 0x37, 0x5b, 0x7c, 0x95, 0xd4, 0xfa, 0xff, 0xff, 0xfe, 0xf9, 0xf4, 0xd1, 0x9d, 0x6e, 0x4e, 0x36, 0x24, 0x16, 0x0d, 0x07, 
  0x08, 0x0f, 0x19, 0x27, 0x3c, 0x54, 0x75, 0xb1, 0xd3, 0xf4, 0xff, 0xff, 0xff, 0xff, 0xec, 0xc0, 0x94, 0x71, 0x52, 0x3a, 0x26, 0x18, 0x0e, 0x07, 
  0x08, 0x0f, 0x19, 0x28, 0x3c, 0x56, 0x74, 0x9f, 0xc3, 0xe9, 0xff, 0xff, 0xff, 0xfe, 0xee, 0xc4, 0x96, 0x71, 0x52, 0x3a, 0x26, 0x18, 0x0e, 0x07, 
  0x07, 0x0e, 0x18, 0x25, 0x39, 0x51, 0x7a, 0xab, 0xcc, 0xf0, 0xff, 0xff, 0xfe, 0xfd, 0xe6, 0xd4, 0x9b, 0x71, 0x51, 0x35, 0x24, 0x16, 0x0e, 0x07, 
  0x07, 0x0d, 0x15, 0x22, 0x31, 0x54, 0x89, 0x94, 0xd6, 0xf3, 0xf4, 0xe7, 0xea, 0xec, 0xe0, 0xd8, 0xb3, 0x9b, 0x88, 0x30, 0x20, 0x14, 0x0c, 0x06, 
  0x06, 0x0b, 0x12, 0x1c, 0x30, 0x5e, 0x73, 0xbf, 0xd8, 0xd7, 0xcf, 0xbb, 0xcb, 0xbd, 0xc7, 0xb5, 0xae, 0x75, 0x85, 0x50, 0x16, 0x11, 0x0a, 0x05, 
  0x05, 0x09, 0x0f, 0x17, 0x20, 0x61, 0x8e, 0xa2, 0xae, 0xa3, 0xbe, 0x9c, 0xb7, 0x95, 0x8f, 0x91, 0x80, 0x6b, 0x8a, 0x89, 0x1e, 0x0c, 0x09, 0x04, 
  0x04, 0x07, 0x0c, 0x10, 0x22, 0x7e, 0x88, 0xa0, 0x5a, 0x81, 0x9d, 0x89, 0x90, 0xb4, 0x70, 0x68, 0x5e, 0x3c, 0x2f, 0x28, 0x15, 0x0a, 0x06, 0x03, 
  0x03, 0x05, 0x09, 0x0f, 0x59, 0x75, 0x57, 0x63, 0x37, 0x6f, 0x7a, 0x68, 0x5c, 0x91, 0x76, 0x3d, 0x45, 0x3a, 0x21, 0x11, 0x0c, 0x08, 0x05, 0x02, 
  0x02, 0x05, 0x07, 0x39, 0x3f, 0x14, 0x1d, 0x47, 0x39, 0x3a, 0x3c, 0x36, 0x58, 0x4e, 0x66, 0x42, 0x24, 0x27, 0x20, 0x12, 0x09, 0x05, 0x03, 0x02, 
  0x02, 0x05, 0x08, 0x12, 0x07, 0x0c, 0x11, 0x18, 0x22, 0x20, 0x25, 0x21, 0x55, 0x44, 0x2f, 0x51, 0x22, 0x12, 0x14, 0x0f, 0x07, 0x04, 0x02, 0x01, 
  0x01, 0x02, 0x03, 0x02, 0x05, 0x08, 0x0b, 0x0e, 0x12, 0x16, 0x17, 0x16, 0x2b, 0x25, 0x11, 0x23, 0x10, 0x0b, 0x09, 0x08, 0x05, 0x02, 0x01, 0x01, 
  0x00, 0x01, 0x01, 0x02, 0x03, 0x05, 0x07, 0x09, 0x0b, 0x0d, 0x0e, 0x0f, 0x0c, 0x0c, 0x0d, 0x09, 0x08, 0x07, 0x05, 0x03, 0x02, 0x01, 0x01, 0x00, 
  0x00, 0x00, 0x01, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x07, 0x08, 0x08, 0x07, 0x06, 0x06, 0x05, 0x03, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 
};

const lv_image_dsc_t spark0 = {
  .header.cf = LV_COLOR_FORMAT_RGB565A8,
  .header.magic = LV_IMAGE_HEADER_MAGIC,
  .header.w = 24,
  .header.h = 24,
  .data_size = 576 * 3,
  .data = spark0_map,
};