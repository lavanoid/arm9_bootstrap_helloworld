#include "draw.h"

int main()
{
    clear_screen();
    font_draw_string(10, 10, WHITE, "Hello world!");
    
    while(true);

    return 0;
}
