#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
    FILE *fp;
   char s[100] = "hello world!\nthis is C world\n";
   char d[100] = "hehe";
    int i = 0;
    fp = fopen ("text1","w+");

    if (fp == NULL) 
    {
        perror ("Open");
        exit (0);

    }
    i = 0;
    while (s[i] != '\0')
    {
         putc (s[i++],fp);  
    }
//        while(d[i]=getc (fp));
//    {
 //       i++;
//    }
    printf("%s\n",d);

    fclose (fp);
    return 0;
}
