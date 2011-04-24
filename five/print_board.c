#include <stdio.h>
#include <string.h>
#include "main.h" 

extern fbscr_t fb_v;
int print_board(void)
{
    int i = 0;
    int j = 0;

    memset((u32_t *)fb_v.memo, 0, fb_v.w*fb_v.h*fb_v.bpp/8);
//board
    for (j = 10; j < ST_Y+(SPACE*B_Y); j++) 
    {
        for (i = 30; i < ST_X+(SPACE*B_X); i++) 
        {
            fb_one_pixel(i, j, YELLOW);
        }
    }
//lines
    for (i = 0; i < B_Y; i++) 
    {
        fb_line(ST_X, ST_Y+i*SPACE, ST_X+(B_X-1)*SPACE, ST_Y+i*SPACE, BLACK);
    }
    for (i = 0; i < B_X; i++) 
    {
        fb_line(ST_X+i*SPACE, ST_Y, ST_X+i*SPACE, ST_Y+(B_Y-1)*SPACE, BLACK);
    }
    fb_circle(60, 100, 18, BLACK);
    fb_circle(60, 200, 18, WHITE);
    return 0;
}
