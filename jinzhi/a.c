
#include <stdio.h>
int main(int argc, const char *argv[])
{
    int j = 0;
    int i = 0;
    int d;
    
    puts("Please input a number :\n");
    scanf("%d", &d);
    
    puts("The result :");
    
    
    j = sizeof (int)*8 - 4;
    for(i = 0;i < sizeof(int)*2; i++,j -= 4)
    {
        if(((d >> j)&0x0f) <= 9)
            printf("%d",((d >> j)&0x0f));
        else
            printf("%c",('a' + (((d >> j)&0x0f) - 10)));
    }
    printf("\n");
    return 0;
}
