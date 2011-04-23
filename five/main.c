#include <stdio.h>
#include "main.h" 

int main(int argc, const char *argv[])
{
    init_screen();
 //   fb_one_pixel(512, 300, 0x000000ff);
 //   fb_line(0, 300, 1000, 400, 0x0000ff00);
//    fb_line(1000,400,0,300,0x0000ff00);
//    fb_line(0,400,1000,300,0x0000ff00);
    
//    fb_line(400,700,600,0,0x0000ff00);
//    fb_line(300,0,600,700,0x0000ff00);
//    fb_circle(512,350,100,0x0000ff00);
//    print_board();
    draw_cursor(100, 200);
    return 0;
}
