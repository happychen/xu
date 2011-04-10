#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10
#define M 10

int main(int argc, const char *argv[])
{
    
    int array[N][M];
    int i = 0;
    int j = 0;
    int *p = &array[0][0];
    int temp = 0;

/*    for(j=0; j<N; j++)
    {
        for(i=0; i<M; i++)
        {
            array[j][i] = j*M+i+1;
        }
    }
*/
   /* for(i=0; i<M*N; i++)
      {
//        array[0][i] = i+1;
        p[i] = i+1;
      }
   */
    srand(time(NULL));
    
    for(i=0; i<M*N; i++)
    {
        array[0][i] =rand()%(M*N);
    }
    



    for(j=0; j<N; j++)
    {
        for(i=0; i<M; i++)
        {
            printf("%5d",array[j][i]);
        }
        printf("\n");
    }
    
    puts("The sort :");
    for(i=0; i<(M*N-1); i++)
    {
        for(j=i+1; j<M*N; j++)
        {
            if(array[0][i] > array[0][j])
            {
                temp =array[0][i];
                array[0][i] = array[0][j];
                array[0][j] = temp;
            }
        }
    }
    
    for(j=0; j<N; j++)
    {
        for(i=0; i<M; i++)
        {
            printf("%5d",array[j][i]);
        }
        printf("\n");
    }

    return 0;
}
