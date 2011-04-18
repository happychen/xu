#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100


void print_array(int *p)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < N; i++) 
    {
        if (p[i] > 0) 
        {
            j++;
            if ((j%7) == 0) 
            {
                printf("\n");
            }
            printf("%5d",p[i]);
        }
    }
}
int main(int argc, const char *argv[])
{
    int array[N];
    init_array(array);
    print_array(array);
    return 0;
}
