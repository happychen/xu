#include <stdio.h>
#include <string.h>
int string_to_number(char *s);

int main(int argc, const char *argv[])
{
    char str[100];
    int number = 0;

    printf("Please input a string:\n");
    scanf("%s",str);

    number = string_to_number(str);
    if(number == -1)
    {
        printf("No number\n");

    }
    else
    {
        printf("number = %d\n", number);
    }
    return 0;
}

int string_to_number(char *s)
{
    int number = 0;
    if((*s >= '0')&&(*s <= '9'))
    {
//        number = (*s-0x30);
        while( (*s >= '0') && (*s <= '9') )
        {
            number *= 10;
            number += (*s-0x30);
//            printf("%d\n",number);
            s++;
        }
    }
    else
    {
        return -1;
    }
    return number;
}
