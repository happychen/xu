#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h" 

extern fbscr_t fb_v;

static u32_t cursor_pixel[C_W*C_H]=
{
    BORD,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    BORD,BORD,T___,T___,T___,T___,T___,T___,T___,T___,
    BORD,X___,BORD,T___,T___,T___,T___,T___,T___,T___,
    BORD,X___,X___,BORD,T___,T___,T___,T___,T___,T___,
    BORD,X___,X___,X___,BORD,T___,T___,T___,T___,T___,

    BORD,X___,X___,X___,X___,BORD,T___,T___,T___,T___,
    BORD,X___,X___,X___,X___,X___,BORD,T___,T___,T___,
    BORD,X___,X___,X___,X___,X___,X___,BORD,T___,T___,
    BORD,X___,X___,X___,X___,X___,X___,X___,BORD,T___,
    BORD,X___,X___,X___,X___,X___,X___,X___,X___,BORD,

    BORD,X___,X___,X___,X___,X___,BORD,BORD,BORD,BORD,
    BORD,X___,X___,BORD,X___,X___,BORD,T___,T___,T___,
    BORD,X___,BORD,T___,BORD,X___,X___,BORD,T___,T___,
    BORD,BORD,T___,T___,BORD,X___,X___,BORD,T___,T___,
    T___,T___,T___,T___,T___,BORD,X___,X___,BORD,T___, 
    T___,T___,T___,T___,T___,BORD,X___,X___,BORD,T___,
    T___,T___,T___,T___,T___,T___,BORD,BORD,T___,T___,
};

static u32_t bg_save[C_H*C_W] = {0};

int mx;
int my;

int draw_cursor(int x, int y)
{
    int i = 0;
    int j = 0;

    save_bg(x, y);

    for (j = 0; j < C_H; j++) 
    {
        for (i = 0; i < C_W; i++) 
        {
            fb_one_pixel(x+i, y+j, cursor_pixel[i+j*C_W]);
        }
    }
    return 0;
}

int save_bg(int x, int y)
{
    int i = 0;
    int j = 0;
    
    for (j = 0; j < C_H; j++) 
    {
        for (i = 0; i < C_W; i++)
        {
            bg_save[i+j*C_W] = *((u32_t *)fb_v.memo+x+i+(y+j)*fb_v.w);
        }
    }
    return 0;
}

int restore(int x, int y)
{
    
    int i = 0;
    int j = 0;
    for (j = 0; j < C_H; j++) 
    {
        for (i = 0; i < C_W; i++) 
        {
            fb_one_pixel(x+i, y+j, bg_save[i+j*C_W]);
        }
    }
    return 0;
}

int get_m_info(int fd, mouse_event *p)
{
    int n;
    char buf[8];

    n = read(fd, buf, 3);
    if (n > 0) 
    {
        p->dx = buf[1];
        p->dy = -buf[2];
        p->button = (buf[0]&0x07);
    }
    return n;
}
int mouse_doing(void)
{
    int fd;
    mouse_event m_event;

    fd = open("/dev/input/mice", O_RDWR|O_NONBLOCK);
    if (fd == -1) 
    {
        perror("mice");
        exit(0);
    }

    mx = fb_v.w/2;
    my = fb_v.h/2;

    draw_cursor(mx, my);

    while(1)
    {

        if((get_m_info(fd, &m_event)) > 0)
        {
            restore(mx, my);
            mx += m_event.dx;
            my += m_event.dy;
            switch(m_event.button)
            {
                case 1 : fb_circle(mx, my, 13, 0x000000ff);break;
                case 2 : break;
                case 3 : break;
                default : break;
            }
            draw_cursor(mx, my);
        }
        usleep(1000);
    }
   
    
    return 0;
}
