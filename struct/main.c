#include <stdio.h> 
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
};

typedef struct node V_NODE;

V_NODE *init_link(int n)
{
    int i = 0;
    V_NODE *head = NULL;
    V_NODE *p = NULL;
    if(n <= 0)
    {
        return NULL;
    }

    p = head = malloc(sizeof(V_NODE));
    if(p == NULL)
    {
        perror("malloc");
        exit(0);
    }
    p->number = 1;
    p->next = NULL;

    for(i = 1; i < n; i++) 
    {
        p->next = malloc(sizeof(V_NODE));
        if(p->next == NULL)
        {
            perror("malloc");
            exit(0);
        }
        p->next->number = i+1;
        p->next->next = NULL;
        p = p->next;
    }
    p->next = head;
    return p;

}
void print_link(V_NODE *p, int n)
{
    int i = 0;
    for (i = 0; i < n; i++) 
    {
        printf("%5d", p->number);
        if(((i+1)%8) == 0)
        {
            printf("\n");
        }
        p = p->next;
    }
    printf("\n");
}
int main(int argc, const char *argv[])
{
    V_NODE *head = NULL;
    V_NODE *rear = NULL; 
    int n = 10; 

    rear = init_link(n);    
    head = rear->next;
    print_link(head, 20);
    return 0;
}
