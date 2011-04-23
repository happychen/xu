#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include "main.h"

fbscr_t fb_v;

int init_screen(void)
{
    int fd;

    struct fb_var_screeninfo fb_var;
    u32_t *p = NULL; 
    fd = open("/dev/fb0", O_RDWR);
    if (fd == -1) 
    {
        perror("fb0");
        exit(0);
    }
    
    if(ioctl(fd, FBIOGET_VSCREENINFO, &fb_var))
    {
        perror("ioctl");
        exit(0);
    }

    fb_v.w = fb_var.xres;
    fb_v.h = fb_var.yres;
    fb_v.bpp = fb_var.bits_per_pixel;

    printf("x=%d\ty=%d\tbits=%d\n", fb_var.xres, fb_var.yres, fb_var.bits_per_pixel);

    p = mmap(NULL, fb_v.w*fb_v.h*fb_v.bpp/8, PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
    if(p == MAP_FAILED)
    {
        perror("map");
        exit(0);
    }
    int i = 0;
    int j = 0;
    for (j = 0; j < 100; j++) 
    {
        for (i = 0; i < 100; i++) 
        {
            p[j*fb_v.w+i] = 0x00ff0000;
        }
    }

    return 0;
}
