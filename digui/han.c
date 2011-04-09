//汉诺塔 递归调用

#include <stdio.h>
void han(char a, char b,char c, int n);

int main(int argc, const char *argv[])
{
    int n = 0;

    printf("please input the number :\n");
    scanf("%d", &n);

    han('A', 'B', 'C', n);
    return 0;
}

void han(char a, char b,char c, int n)
{
    if (n ==1) 
    {
        printf("%c---->%c\n", a, c);
        return ;
    }
    han(a,c,b,n-1);
    printf("%c---->%c\n", a, c);
    han(b,a,c,n-1);
}
