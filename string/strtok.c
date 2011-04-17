#include <stdio.h>
#include <string.h>
#define N 100
void str_test(void);

int main(int argc, const char *argv[])
{
    str_test();
    return 0;
}

void str_test(void)
{
    
//    char str[100];
//    printf("Please input a string:\n");
//    scanf("%s",str);//scanf遇到空格就是认为是非法的

    char str[100] = "This is only Game !";
    char *p = str;
    
    p = strtok(p, " ");
    while(p != NULL)
    {

        printf("%s\n",p);
        p = strtok(NULL, " ");
    }
}
