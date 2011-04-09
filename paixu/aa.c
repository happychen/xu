#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    int tmp;
    char array[10]={4,8,-56,46,0,-23,100,28,18,-6};

    for(i = 0;i < 9;i++)
    {
        k = i;
        for(j = i+1;j < 10;j++)
        {
            if(array[k] > array[j])
            {
                k = j;
            }
        }
        if(k != i)
        {
            tmp = array[i];
            array[i] = array[k];
            array[k] = tmp;
        }
    }
    
    for(i = 0;i < 10; i++)
    {
        printf("%d  ",array[i]);
    }
    printf("\n");

    return 0;
}
