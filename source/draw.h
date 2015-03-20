#ifndef _DRAW_H
#define _DRAW_H

#include "common.h"

#define SCREEN_TOP_W  (400)
#define SCREEN_BOT_W  (340)
#define SCREEN_TOP_H  (240)
#define SCREEN_BOT_H  (240)

#define FB_TOP_LEFT1  (0x20000000)
#define FB_TOP_LEFT2  (0x20046500)
#define FB_TOP_RIGHT1 (0x20000000)
#define FB_TOP_RIGHT2 (0x20046500)
#define FB_BOT_1      (0x2008CA00)
#define FB_BOT_2      (0x200C4E00)

#define FB_TOP_SIZE   (0x46500)
#define FB_BOT_SIZE   (0x3BC40)

#define RED    0xFF0000
#define ORANGE 0xFF8000
#define GREEN  0x00FF00
#define BLUE   0x0000FF
#define PURPLE 0x8000FF
#define BLACK  0x000000
#define WHITE  0xFFFFFF

void clear_screen();
void draw_plot(int x, int y, u32 color);
void draw_fillrect(int x, int y, int w, int h, u32 color);
int font_draw_char(int x, int y, u32 color, char c);
int font_draw_string(int x, int y, u32 color, const char *string);

#endif
