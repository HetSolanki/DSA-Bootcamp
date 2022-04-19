#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

void display(struct node *s)
{
  while(s!=NULL)
  {
    printf("%d\n",s->data);
    s=s->next;
  }
}

struct node *DeleteAtFirst(struct node *s)
{
  struct node *ptr = s;
  s=s->next;
  free(ptr);
  
  return s;
}

struct node *DeleteAtEnd(struct node *s)
{
  struct node *p;
  struct node *ptr;
  
  p=s;
  ptr=s->next;
  while(ptr->next!=NULL)
  {
    p=p->next;
    ptr=ptr->next;
  }
  p->next=NULL;
  
  free(ptr);
  return s;
  
}

struct node *DeleteAtValue(struct node *s, int value)
{
  
  struct node *ptr;
  struct node *p;
  ptr=s;
  p=s->next;
  while(p->next!=NULL && p->data!=value)
  {
    ptr=ptr->next;
    p=p->next;
  }
  
  if(p->data == value)
  {
    ptr->next=p->next;
    free(p);
  }
  else
  {
    printf("\nData Is not Deleted..!!\n\n");
  }
  return s;
}

struct node *DeleteAtIndex(struct node *s, int index)
{
  int i=0;
  struct node *ptr;
  struct node *p;
  
  ptr=s;
  p=s->next;
  while(i!=index-1)
  {
    ptr=ptr->next;
    p=p->next;
    i++;
  }
  ptr->next=p->next;
  
  free(p);
  return s;
  
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
  second  = (struct node *)malloc(sizeof(struct node));
  third = (struct node *)malloc(sizeof(struct node));
  fourth = (struct node *)malloc(sizeof(struct node));
  five = (struct node *)malloc(sizeof(struct node));
  six = (struct node *)malloc(sizeof(struct node));
  
  
  head->data=10;
  head->next=first;
  
  first->data=20;
  first->next=second;
  
  second->data=30;
  second->next=third;
  
  third->data=40;
  third->next=fourth;
  
  fourth->data=50;
  fourth->next=five;
  
  five->data=60;
  five->next=six;
  
  six->data=70;
  six->next=NULL;
  
  
  //head = DeleteAtFirst(head);
  printf("Before Delete a node \n");
  display(head);
  
  head = DeleteAtEnd(head);
  printf("\n\nAfter Delete a node At End\n");
  display(head);
    
  printf("\n\nAfter Delete a Value \n");
  head = DeleteAtValue(head,20);
  display(head);
  
  printf("\n\nAfter Delete a node \n");
  head = DeleteAtIndex(head,3);
  display(head);
  return 0;
}