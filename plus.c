#include<stdio.h>
#include<stdlib.h>
struct node{

          int data;
          struct node *next;



}*a,*b,*n;

struct node *newnode()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    return temp;
}
void travarse(struct node* *head_ref)
{
    struct node *p=(*head_ref);
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}



void insertfirst(struct node **head_ref,int x)
{
    struct node *n=newnode();
    n->data=x;
    if(head_ref==NULL)
    {
        head_ref=n;
        return;
    }
    n->next=(*head_ref);
    (*head_ref)=n;
}
void concatenate(struct node *a,struct node *b)
{
    if( a != NULL && b!= NULL )
    {
        if (a->next == NULL)
            a->next = b;
        else
            concatenate(a->next,b);
    }

}

int main()
{
    a=NULL;
    b=NULL;
    int p;

    insertfirst(&a,5);
    insertfirst(&a,6);
    insertfirst(&a,7);
    travarse(&a);
    printf("\n");

    insertfirst(&b,10);
    insertfirst(&b,20);
    insertfirst(&b,30);
    travarse(&b);
    printf("\n");
    concatenate(a,b);
    travarse(&a);




}
