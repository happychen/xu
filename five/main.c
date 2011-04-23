#include <stdio.h>
#include "main.h" 

int main(int argc, const char *argv[])
{
    init_screen();
    fb_one_pixel(512, 300, 0x000000ff);
    return 0;
}
