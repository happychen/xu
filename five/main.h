#ifndef _MAIN_N_
#define _MAIN_H_

typedef unsigned int u32_t;
typedef unsigned char u8_t;
typedef struct
{
    int w;
    int h;
    int bpp;
    void *memo;
    
} fbscr_t;

int init_screen(void);
int fb_one_pixel(int x, int y, u32_t color);
int fb_line(int x1, int y1, int x2, int y2, u32_t color);
#endif
