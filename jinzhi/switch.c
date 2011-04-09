#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i = 0;
    int j = 0;
    int t = 0;
    char c;
    
    puts("Please input a number :");
    scanf("%c", t);
    j = sizeof(int)*8-4;
    for(i=0; i<sizeof(int)*2; i++, j-=4)
    {
        if(t <= 9)
        {
             printf("%d", t);
        }
        else
        {
            switch(t)
            {
                case 10 : c = 'a';break;
                case 11 : c = 'b';break;
                case 12 : c = 'c';break;
                case 13 : c = 'd';break;
                case 14 : c = 'e';break;
                case 15 : c = 'f';break;
                default : break;
            }
            printf("%c",c);
            printf("\n");
        }
    }
    return 0;
}
