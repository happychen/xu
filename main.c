#include <stdio.h>

int main(int argc, const char *argv[])
{
    int j = 0;
    int i = 0;
    int d = 0;
    unsigned int mask = 0x0f; 
    char str_h[20] = "0123456789abcdef";
    
    puts("Please input a number :\n");
    scanf("%d", &d);
    
    puts("The result :");
    
    j = 28;
    for(i = 0;i < 8; i++,j -= 4) 
    
    {
        printf("%c",str_h[(d >> j)&mask]);
    }
    printf("\n");
    return 0;
}
