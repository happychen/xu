
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int number;
    char name[20]; 
    struct node *next;
};

typedef struct node V_NODE;

V_NODE *create_link(int n);
void print_link(V_NODE *p);
V_NODE *add_link(V_NODE *head);
V_NODE *delete_link(V_NODE *head);

void print_test(void);

void link_list(void);
int get_choice(void);
void save_link(V_NODE *p);
V_NODE *load_link(void);

void save_link(V_NODE *p)
{
    FILE *fp;
    fp = fopen("text", "w+");
    if (fp == NULL) 
    {
        perror("malloc");
        exit(0);
    }

    while(p != NULL)
    {

        fprintf(fp, "%d\t%s\n", p->number, p->name);
        p = p->next;     
    }
    fclose(fp);
}

V_NODE *load_link(void)
{
    FILE *fp;
    int num;
    char na[20];
    V_NODE *head = NULL;
    V_NODE *p = NULL;

    fp = fopen("text","r+");

    if(fp == NULL)
    {
        perror("malloc");
        exit(0);
    }
    if(fscanf(fp, "%d%s",&num, na) != EOF)
    {
        p = malloc(sizeof(V_NODE));
        if (p == NULL) 
        {
            perror("malloc");
            exit(0);
        }
        p->number = num;
        strcpy(p->name, na);
        p->next = NULL;
        head = p;
    }
    while(fscanf(fp, "%d%s", &num, na) != EOF)
    {
        p->next = malloc(sizeof(V_NODE));
        if (p->next == NULL) 
        {
            perror("malloc");
            exit(0);
        }
        p->next->number = num;
        strcpy(p->next->name, na);
        p->next->next = NULL;
        p = p->next;
    }
    return head;
}

int main(int argc, const char *argv[])
{
    V_NODE *head = NULL;
    char flag = 0;
    print_test();

    head =load_link();
    while(!flag)
    {
        link_list();    
        switch(get_choice())
        {
            case 1  : head = add_link(head); break;
            case 2  : head = delete_link(head);break;
            case 3  : print_link(head);break;
            case 4  : save_link(head);break;
            case 5  : flag = 1; break;
            default : break;
        }
    }
    return 0;
}
int get_choice(void)
{
    char choice[20];
    scanf("%s",choice);
    return atoi(choice);
}

void link_list(void)
{
    printf("Please make a choice:\n");
    printf("1.Add node\n");
    printf("2.delete node\n");
    printf("3.print link\n");
    printf("4.save link\n");
    printf("5.exit\n");
}
V_NODE *create_link(int n)
{
    V_NODE *p = NULL;
    V_NODE *head = NULL;
    int i = 0;
    
    p = head = malloc(sizeof(V_NODE));
    if(p == NULL)
    {
        perror("malloc");
        exit(0);
    }
    p->number = 1;
    strcpy(p->name,"fei");
    p->next = NULL;

    for(i=1; i<n; i++)
    {
        p->next = malloc(sizeof(V_NODE));
        if(p->next == NULL)
        {
            perror("malloc");
            exit(0);
        }
        p->next->number = i+1;
        strcpy(p->next->name,"chen");
        p->next->next = NULL;
        p = p->next;
    }
    return head;
}

V_NODE *add_link(V_NODE *head)
{
    V_NODE *p = NULL;
    V_NODE *ptr = head;//把原先创建的链表传过来

    p = malloc(sizeof(V_NODE));
    if(p == NULL)
    {
        perror("malloc");
        exit(0);
    }
//    printf("where do you want to  input a link? \n");
    printf("Please input number:\n");
    scanf("%d",&p->number);
    printf("Input link's name:\n");
    scanf("%s",p->name);
    p->next = NULL;

    if(ptr == NULL)
    {
        return p; 
    }
    if(p->number < ptr->number)
    {
        p->next = ptr;
        head = p;
        return head;
    }
    while((ptr->next != NULL)&&(p->number > ptr->next->number))
    {
        ptr = ptr->next;
    }
    p->next = ptr->next;
    ptr->next = p;
    
    return head;
}

V_NODE *delete_link(V_NODE *head)
{
    int num = 0;
    V_NODE *p = head;
    V_NODE *ptr = NULL;
    if(head == NULL)
    {
        printf("empty link!\n");
        return NULL;
    }
    printf("Please input number of node to delete:\n");
    scanf("%d",&num);

    if(num == head->number)
    {
        head = head->next;
        free(p);
        return head;
    }

    while((p->next != NULL) && (p->next->number != num))
    {
        p = p->next;
    }
    if(p->next == NULL)
    {
        printf("No number match!\n");
    }
    else
    {
        ptr = p->next;
        p->next = p->next->next;
        free(ptr);
    }
    return head;
}
void print_link(V_NODE *p)
{
    if (p == NULL) 
    {
        printf("link empty.\n");
    }
    printf("student information:\n");
    printf("number\tname\n");
    while(p != NULL)
    {
        printf("%d\t\%s\n",p->number,p->name);
        p = p->next;
    }
    printf("\n");
}
