#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *prev;
  struct node *next;
};

void Travers(struct node *head)
{
  struct node *p = head;
 
  printf("Ordered LinkedList : \n");
  do
  {
    printf("%d\n",p->data);
    p=p->next;
  }while(p->next!=NULL);
  printf("%d",p->data);
 
  printf("\n\nReveresed LinkedList : \n");
  do
  {
    printf("%d\n",p->data);
    p=p->prev;
  }while(p!=NULL);
  
}

struct node *InsertAtEnd(struct node *head)
{
  struct node *ptr;
  ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data=100;
  
  struct node *p = head->next;
  struct node *q = head;
  while(p->next!=NULL)
  {
    p=p->next;
    q=q->next;
  }
  ptr->next = NULL;
  ptr->prev = p;
  p->next = ptr;
  p->prev = q;
  
  return head;
  
}
struct node *InsertAtFirst(struct node *head)
{
  struct node *ptr;
  ptr = (struct node *)malloc(sizeof(struct node));
  
  struct node *p = head;
  
  ptr->data=100;
  ptr->next=p;
  ptr->prev=NULL;
  p->prev=ptr;
  head = ptr;
  
  return head;
}

struct node *InsertAfterNode(struct node *head, struct node *s)
{
  struct node *ptr;
  ptr = (struct node *)malloc(sizeof(struct node));
  struct node *p = s;
  p=p->next;
  
  ptr->data=500;
  ptr->next=s->next;
  ptr->prev=s;
  s->next=ptr;
  p->prev=ptr;
  
  return head;
  
}
int main()
{
  struct node *head;
  struct node *first;
  struct node *second;
  struct node *third;
  struct node *fourth;
  
  head = (struct node *)malloc(sizeof(struct node));
  first = (struct node *)malloc(sizeof(struct node));
  second  = (struct node *)malloc(sizeof(struct node));
  third = (struct node *)malloc(sizeof(struct node));
  fourth = (struct node *)malloc(sizeof(struct node));
  
  head->data=10;
  head->prev=NULL;
  head->next=first;

  first->data=20;
  first->prev=head;
  first->next=second; 
  
  second->data=30;
  second->prev=first;
  second->next=third;
  
  third->data=40;
  third->prev=second;
  third->next=fourth;
  
  fourth->data=50;
  fourth->prev=third;
  fourth->next=NULL;
  
  //head = InsertAtFirst(head);  
  //head = InsertAtEnd(head);
  head = InsertAfterNode(head,fourth);
  Travers(head);
}