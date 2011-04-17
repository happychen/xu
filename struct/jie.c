#include <stdio.h>
#include <string.h>

struct node//定义类型
{
    int number;
    char name[20];
    int score;
};
typedef struct node V_NODE;

int main(int argc, const char *argv[])
{
    V_NODE stu;//定义变量
    V_NODE *ptr = NULL;

    ptr = &stu;
//    ptr->number = 2;
//    strcpy(ptr->name,"xu");

    printf("Please input number :\n");
    scanf("%d",&ptr->number);
    printf("name :\n");
    scanf("%s",ptr->name);
    getchar();//从缓冲区里读取
    printf("score :\n");
    scanf("%d",&ptr->score);

    printf("number: %d\tname:%s\tscore:%d\n",ptr->number,ptr->name,ptr->score);
    return 0;
}
