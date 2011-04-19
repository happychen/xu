#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp;
    char str[100] = "everyone";
    char str_1[100];
    int number = 100;
    int r_number = 0; 

    fp = fopen("text1", "r+");
    if (fp == NULL) 
    {
        perror("open:");
        exit(0);
    }
    fprintf(fp,"%d  %d\n", number, number+1);
    fscanf(fp,"%d  %d", &number, &r_number);
    printf("number=%d  r_number=%d\n", number, r_number);

    fclose(fp);
    return 0;
}
