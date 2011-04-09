#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i = 0;
    int j = 0;
    int min = 0;
    int tmp = 0;
    int a[11];

    printf("Please input 10 numbers :\n");
    for(i = 1;i <= 10;i++)
    {
        printf("a[%d] = ",i);
        scanf("%d", &a[i]);
    }
    printf("\n");

    printf("The original numbers :\n");
    for(i = 1;i <= 10;i++)
    printf("%5d",a[i]);
    printf("\n");

    for(i = 1;i <= 9;i++)
    {
       min = i;
       for(j = i+1;j <=10;j++)
       if(a[min]>a[j]) 
       min = j;
       {
             tmp = a[i];
             a[i] = a[min];
             a[min] = tmp;
       }
    }
    printf("\nthe sorted numbers :\n");

    for(i =1;i <= 10;i++)
    printf("%5d",a[i]);
    printf("\n");
    return 0;
}
