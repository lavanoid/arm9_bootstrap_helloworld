#include "draw.h"

extern const u8 msx_font[];

void clear_screen()
{
    memset((u32*)FB_TOP_LEFT1, 0, ((FB_TOP_SIZE*2) +(FB_BOT_SIZE)));
}

void draw_plot(int x, int y, u32 color)
{
    u8 *base = (u8*)((SCREEN_TOP_H-y-1)*3 +x*3*SCREEN_TOP_H);
    u8 *p1 = base + FB_TOP_LEFT1;
    u8 *p2 = base + FB_TOP_LEFT2;
    p1[0] = p2[0] = color & 0xFF;
    p1[1] = p2[1] = (color>>8) & 0xFF;
    p1[2] = p2[2] = (color>>16) & 0xFF;
}

void draw_fillrect(int x, int y, int w, int h, u32 color)
{
    int i, j;
    for (i = 0; i < w; ++i) {
        for (j = 0; j < h; ++j) {
            draw_plot(x+i, y+j, color);
        }
    }
}

int font_draw_char(int x, int y, u32 color, char c)
{
    u8 *font = (u8*)(msx_font + (c - (u32)' ') * 8);
    int i, j;
    for (i = 0; i < 8; ++i) {
        for (j = 0; j < 8; ++j) {
            draw_plot(x+j, y+i, 0);
            if ((*font & (128 >> j))) draw_plot(x+j, y+i, color);
        }
        ++font;
    }
    return x+8;
}

int font_draw_string(int x, int y, u32 color, const char *string)
{
    if (string == NULL) return x;
    int startx = x;
    const char *s = string;
    while (*s) {
        if (*s == '\n') {
            x = startx;
            y+=8;
        } else if(*s == '\t') {
            x+=8*4;
        } else {
            font_draw_char(x, y, color, *s);
            x+=8;
        }
        ++s;
    }
    return x;
}
