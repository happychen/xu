#include <stdio.h>
#include <string.h>

struct node//定义类型
{
    int number;
    char name[20];
    int score;
};
int main(int argc, const char *argv[])
{
    struct node stu;//定义变量

    stu.number = 2;
    strcpy(stu.name,"xu");

    printf("number: %d\tname:%s\n",stu.number,stu.name);
    return 0;
}
