//指针的操作

#include <stdio.h>

int main(int argc, const char *argv[])
{
    char str[20] = "This is a C world!";
    char *p = str;
    char c_str[20];
    char *p_c = c_str;
    for(p = str; *p != '\0';p++)//把空格去掉
    {
        if(*p != ' ')
        {
            *p_c = *p;
            p_c++;
        }
    }
    *p_c = '\0';
    printf("%s",c_str);
    printf("\n");
    for(p=str;*p != '\0';p++)
    {
       // printf("%c",*p);
       putchar(*p);
    }
    //printf("\n");
    putchar('\n');

//    while (*p != '\0') p++;//倒着来打印

  //  for(p--; p != (str-1); p--)
  //  {
    //    putchar(*p);
   // }

    for(*p='\0';p!=(str-1);p--)//倒着打印
     {
       printf("%c",*p); 
     }
    printf("\n");
    return 0;
}
