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

#endif
