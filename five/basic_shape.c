#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int fb_line(int x1, int y1, int x2, int y2, u32_t color)
{
    int dx = x2-x1;
    int dy = y2-y1; 
    int p = 0;

    int inc = ((dx*dy<0)?-1:1);

    if (abs(dx) > abs(dy)) 
    {
        if (dx < 0) 
        {
            swap(&x1, &x2);
            swap(&y1, &y2);
            dx = -dx;
            dy = -dy;
        }

        dy = abs(dy);
        p =2*dy-dx;
        while(x1 <= x2)
        {
            fb_one_pixel(x1, y1, color);
            x1++;
            if (p < 0) 
            {
                p += 2*dy;
            }
            else
            {
                y1 += inc;
                p += 2*(dy-dx);
            }
        }
    }
    else
    {
        
        if (dy < 0) 
        {
            swap(&x1, &x2);
            swap(&y1, &y2);
            dx = -dx;
            dy = -dy;
        }

        dx = abs(dx);
        p =2*dx-dy;
        while(y1 <= y2)
        {
            fb_one_pixel(x1, y1, color);
            y1++;
            if (p < 0) 
            {
                p += 2*dx;
            }
            else
            {
                x1 += inc;
                p += 2*(dx-dy);
            }
        }
    }
    return 0;
}
