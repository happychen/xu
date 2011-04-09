#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i = 0;
    int j = 0;
    int tmp = 0;
    int array[10];

    puts("Please input 10 numbers :\n");
    for(i = 0;i < 10 ;i++)
    scanf("%d",&array[i]);
    printf("\n");
    
    for(i = 0; i < 10; i++) 
    {
        printf("%d   ",array[i]);
    }
    printf("\n");
    
    for(j = 0;j < 9;j++)
    {
        for(i = 0;i < 9-j; i++)
        {
            if(array[i] > array[i+1])
            {
                tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp; 
            }
            
        }
    }
    
    printf("the sorted numbers :\n");
    for(i = 0; i < 10; i++) 
    {
        printf("%d   ",array[i]);
    }
    printf("\n");
    
    return 0;
}
