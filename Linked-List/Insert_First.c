#include <stdio.h>
#include <stdlib.h>

struct node *sort(struct node *);
struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int data, struct node *head)
{

    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;

    head->next = p;

    return p;
}

struct node *insertBeginning(struct node *head)
{
    int value;
    struct node *p = (struct node *)malloc(sizeof(struct node));

    printf("Enter New Value:: ");
    scanf("%d", &value);

    p->data = value;
    p->next = head;
    head = p;

    return head;
}

struct node *InsertAtEnd(struct node *head)
{
    struct node *p = head;
    struct node *q = (struct node *)malloc(sizeof(struct node));

    int value;

    printf("Enter New Value:: ");
    scanf("%d", &value);

    q->data = value;
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = q;
    q->next = NULL;

    return head;
}

// struct node *InsertSortedOrder(struct node *head)
// {
//     head = sort(head);
//     struct node *p = (struct node *)malloc(sizeof(struct node));
//     struct node *q = head;

//     int value;

//     printf("%d", head->data);
//     printf("Enter New Value:: ");
//     scanf("%d", &value);

//     p->data = value;
//     while (q->next != NULL)
//     {
//         if (q->data < value)
//         {
//             q = q->next;
//         }
//         else
//         {
//             break;
//         }

//     }

//     p->next = q;
//     q->next = p;

//     return head;
// }

// struct node *sort(struct node *head)
// {
//     struct node *p = head;
//     struct node *q = head->next;

//     printf("%");
//     while (p->next != NULL)
//     {
//         q = p->next;
//         while (q != NULL)
//         {
//             if (p->data > q->data)
//             {
//                 int temp = p->data;
//                 p->data = q->data;
//                 q->data = temp;
//             }
//             q = q->next;
//         }
//         p = p->next;
//     }

//     return head;
// }

void display(struct node *head)
{
    struct node *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *head = temp;

    int n;
    int value;

    printf("Enter Size :: ");
    scanf("%d", &n);

    printf("Enter value :: ");
    scanf("%d", &value);

    temp->data = value;
    for (int i = 0; i < n - 1; i++)
    {

        printf("Enter value :: ");
        scanf("%d", &value);
        temp = createNode(value, temp);
    }

    // head = insertBeginning(head);
    // display(head);
    // head = InsertAtEnd(head);

    display(head);
    head = InsertSortedOrder(head);
    display(head);
}