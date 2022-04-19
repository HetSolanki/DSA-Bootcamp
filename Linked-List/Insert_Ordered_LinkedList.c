#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int val)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = val;
    p->next = NULL;

    return p;
}

struct node *insert(struct node *first)
{
    struct node *s = createNode(35);

    if (s->data < first->data)
    {
        s->next = first;
        first = s;
    }
    else
    {
        struct node *p = first;
        struct node *ptr = p;
        while (s->data > p->data && p->next != NULL)
        {
            ptr = p;
            p = p->next;
        }
        if(p->next == NULL)
        {
            ptr = ptr->next;
        }
        s->next = ptr->next;
        ptr->next = s;
    }

    return first;
}
void display(struct node *first)
{
    struct node *p = first;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main()
{
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *five;
    struct node *six;

    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    five = (struct node *)malloc(sizeof(struct node));
    six = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = first;

    first->data = 20;
    first->next = second;

    second->data = 30;
    second->next = third;

    third->data = 40;
    third->next = fourth;

    fourth->data = 50;
    fourth->next = five;

    five->data = 60;
    five->next = six;

    six->data = 70;
    six->next = NULL;

    head = insert(head);
    display(head);
    // printf("\n");
    // head = insertFirst(head);
    // head = insertEnd(head);
    // display(head);
}