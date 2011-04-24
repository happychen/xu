#include <stdio.h>
#include "main.h"

extern int mx;
extern int my;
char flag = 0;
u32_t current_color = 0;
char current_player = 0;

char chess_board[B_Y*B_X];

int chess_do(void)
{
    int x = mx;
    int y = my;

    int lx = 0;
    int ly = 0;
    int winner = 0;

    if (flag == 0) 
    {
        print_board();
        flag = 0xff;
        return 0;
    }

    if (x < ST_X || (x > ST_X+SPACE*(B_X-1))) 
    {
        if ((x > 42) && (x < 78) && (y > 82) && (y < 118))
        {
            current_color = BLACK;
            current_player = 1;//逻辑切换
            
        }
        else if((x > 42) && (x < 78) && (y > 182) && (y < 218))
        {
            current_color = WHITE;    
            current_player = 2;
        }
        return 0;
    }
    if (y < ST_Y || (y > ST_Y+SPACE*(B_Y-1))) 
    {
        return 0;
    }

    x = (x-ST_X) % SPACE;
    y = (y-ST_Y) % SPACE;
    if (x < (SPACE/2)) 
    {
        x = mx -x;
    }
    else
    {   
      x =  mx+(SPACE-x);
    }
    if (y < (SPACE/2)) 
    {
        y = my -y;
    }
    else
    {
        y = my+(SPACE-y);
    }

    lx = (x - ST_X)/SPACE;
    ly = (y - ST_Y)/SPACE;

    chess_board[lx + ly*B_X] = current_player;//指示who
    fb_circle(x, y, 13, current_color);
    
    winner = check_win();
    if (winner > 0)
    {
        printf("player %d won!\n", winner);        
        return 0;

    }
    
    return 0;
}
