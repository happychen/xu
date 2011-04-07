#include <stdio.h>

int main(int argc, const char *argv[])
{
    int j = 0;
    int i = 0;
    int d = 0;
    char str_h[20] = "0123456789abcdef";
    
    puts("Please input a number :\n");
    scanf("%d", &d);
    
    puts("The result :");
    
    j = sizeof (int)*8 - 4;
    for(i = 0;i < sizeof(int)*2; i++,j -= 4) 
    
    {
        printf("%c",str_h[(d >> j)&0x0f]);
    }
    printf("\n");
    return 0;
}
