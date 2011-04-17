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

int main(int argc, const char *argv[])
{
    V_NODE *head;
    int n = 0;
    printf("Input a number :\n");
    scanf("%d",&n);
    puts("The link you created :\n");

    head = create_link(n);
    print_link(head);
//    head = add_link(head);
//    print_link(head);
    head = delete_link(head);
    print_link(head);
    return 0;
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
    printf("where do you want to  input a link? \n");
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
    while((p->number > ptr->next->number) && (ptr->next != NULL))
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
    while(p != NULL)
    {
        printf("%d\t\%s\n",p->number,p->name);
        p = p->next;
    }
    
}
