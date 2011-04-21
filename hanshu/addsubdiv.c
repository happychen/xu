#include <stdio.h>
int mul(int a,int b);
int div(int a,int b);
int sub(int a,int b);
int add(int a,int b) ;

int main(int argc, const char *argv[])
{
    int a = 12;
    int b = 6;
    int c = 0;

    c = add(a ,b);
    c = sub(a ,b);
    c = mul(a ,b);
    c = div(a ,b);
    printf("c = %d \n",c);
    return 0;
}
int add(int a,int b) 
{
    return (a + b);
}

int sub(int a,int b)
{
    return (a * b);
}
int mul(int a,int b)
{
    return (a - b);
}

int div(int a,int b)
{
    return (a / b);
}









