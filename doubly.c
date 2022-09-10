#include<stdio.h>
#include<stdlib.h>
struct node{


       int data;
       struct node *prev;
       struct node *next;

}*head;
struct node* newnode()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
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
void insertfirst(int data)
{
    struct node *n=newnode();
    n->data=data;

    if(head==NULL)
    {
        head=n;
        return;
    }


    n->next=head;
    head->prev=n;
    head=n;
}
void insertlast(int x)
{
    struct node *n=newnode();
    n->data=x;
    struct node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }

    p->next=n;
    n->prev=p;

}
void insertatpos(int pos,int x)
{
    struct node *n=newnode();
    n->data=x;
    struct node *p=head;
    int i;
    for(i=1;i<pos-1;i++)
    {
        p=p->next;
    }
    n->next=p->next;
    p->next->prev=n;
    n->prev=p;
    p->next=n;



}
void deletfast()
{
    struct node *p=head->next;
    p->prev=NULL;
    head->next=NULL;
    head=p;
}
void deletlast()
{
    struct node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    struct node *t=p->prev;
    t->next=NULL;
    p->next=NULL;
}
void deletatpos(int pos)
{
    struct node *p=head;
    int i;
    for(i=1;i<pos;i++)
    {
        p=p->next;
    }
    struct node *q=p->prev;
    struct node *r=p->next;

    p->next=NULL;
    p->prev=NULL;
    q->next=r;
    r->prev=q;


}
void swap(int x, int y)
{
    struct node *p=head;
    while(p->next!=NULL)
    {
        if(p->data==x)
        {
            p->data=y;
        }
        p=p->next;
    }
    struct node *q=head;
    while(q->next!=NULL)
    {
        if(q->data==y)
        {
            q->data=x;
        }
        q=q->next;
    }
}
void circularlist()
{
    struct node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    head->prev=p;
    p->next=head;
}
int main()
{   head=NULL;
    insertfirst(5);
    insertfirst(6);
    insertfirst(7);
    insertfirst(10);
    travarse();
    printf("\n");
    insertlast(66);
    travarse();
    printf("\n");
    insertatpos(3,60);
    travarse();
    printf("\n");
    deletfast();
    travarse();
    printf("\n");
    deletlast();
    travarse();
    printf("\n");
    deletatpos(3);
    travarse();
    printf("\n");
    swap(7,5);
    travarse();
    printf("\n");
    circularlist();
    travarse;
    printf("\n");

}
