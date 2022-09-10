#include<stdio.h>
#include<stdlib.h>
struct node{


      int data;
      struct node *next;

}*head;
struct node* newnode()
{
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->next=NULL;
    return t;
}
void travarse()
{
    struct node *p=head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void swap(int x ,int y)
{
    struct node *t=head;
    struct node *p=head;

    while(t!=NULL)
    {
        if(t->data==x)
        {
            t->data=y;
        }
        t=t->next;
    }

    while(p!=NULL)
    {
        if(p->data==y)
        {
            p->data=x;
        }
        p=p->data;
    }
}
void riv()
{
    struct node *prev,*current,*next;
    prev=NULL;
    current=head;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;


    }
    head=prev;
}
void findbydata(int x)
{
    struct node *p=head;
    int count=1;
    while(p->next!=NULL)
    {
        if(p->data==x)
        {
           break;
        }
        p=p->next;
        count++;
    }
    printf("the pos is %d",count);
}
void deletfast()
{
    struct node *temp=head;
    head=temp->next;
    temp->next=NULL;
}
void deletatpos(int pos)
{
    struct node *temp=head;
    int i;
    for(i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;



}
void deletlast()
{
   struct node  *temp=head;
   while(temp->next->next!=NULL)
    temp=temp->next;
   temp->next=NULL;

}
void insertlast(int x)
{
    struct node *temp=head;
    struct node *n=newnode();
    n->data=x;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=NULL;
}
void insertmiddle( int pos ,int x)
{

    struct node *n=newnode();
    struct node *temp=head;
    int i;


    n->data=x;
    if(pos==1)
    {
        insertfirst(x);
    }
    for(i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;




}
void insertfirst(int x)
{

    struct node *temp=newnode();
    temp->data=x;
    if(head==NULL)
    {
       head=temp;
       return;
    }
    temp->next=head;
    head=temp;
}
int main()
{
    head=NULL;
    insertfirst(5);
    insertfirst(10);
    insertfirst(20);
    insertfirst(30);
    travarse();
    printf("\n");

    insertlast(60);
    insertmiddle(3,50);
    travarse();
    printf("\n");
    deletlast();
    travarse();
    printf("\n");
    deletatpos(3);
    travarse();
    printf("\n");
    deletfast();
    travarse();
    printf("\n");
    findbydata(5);
    printf("\n");
    riv();
    travarse();
    printf("\n");
    swap(20,5);
    travarse();


}

