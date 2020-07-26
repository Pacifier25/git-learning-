#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;

}*first = '\0',*second = '\0',*third = '\0';
void create(int A[],int n)
{
    int i;
    struct node *t,*last;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = '\0';
    last = first;

    for(i = 1; i < n; i++)
    {
        t = (struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create2(int A[],int n)
{
    int i;
    struct node *t,*last;
    second = (struct node*)malloc(sizeof(struct node));
    second->data = A[0];
    second->next = '\0';
    last = second;

    for(i = 1; i < n; i++)
    {
        t = (struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void display(struct node *p)
{

    while(p != '\0')
    {
        printf("%d\n",p->data);
        p = p->next;
    }
}
int count(struct node *p)
{
    int c = 0;
    while(p != '\0')
    {
        c++;
        p = p->next;
    }
    return c;

}
int sum(struct node *p)
{
    int s = 0;
    while(!p == '\0')
    {
        s = s + p->data;
        p = p->next;
    }
    return s;
}
struct node* lsearch(struct node *p,int key)
{
    struct node *q;
    while(p != '\0')
    {
      if(p->data == key)
      {
          q->next = p->next;
          p->next = first;
          p = first;
          return p;
      }
      q = p;
      p = p->next;
    }
}
void insert(struct node *p,int index, int x)
{
    struct node *t;
     t = (struct node*)malloc(sizeof(struct node));
       t->data = x;
       t->next = '\0';
    if(index < 0 || index > count(p))
   {
     return;
   }
    else
    {
        if(index == 0)
        {
            t->next = first;
            first = t;
        }
        else
        {
            for (int i = 0; i < index - 1 ; i++)
            {
                p = p->next;

            }
                t->next = p->next;
                p->next = t;
        }
    }
}
void insertsort(struct node *p,int x)
{
    struct node *q;
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    t->next ='\0';
    p = first;
    q = '\0';
    if(first == '\0')
    {
        t = first;
    }
    else
    {

    while(p->data < x && p != '\0')
    {
        p = p->next;
        q = p;
    }
    if(first == p )
    {
    t->next = first;
    first = t;
    }
    else
    {

         q->next = t->next;
         t->next = p->next;
          t = q->next;
    }

}
}
int delete(struct node *p, int index)
{
    if(index < 1 ||  index > count(p) )
    {
        return 1;
    }
    struct node *q;
    q = '\0';
    if(index == 1)
    {
        q = first ;
        int x = first->data;
        first = first->next;
        free(q);
        return x;

    }
    else
    {
        for(int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        int x = p->data;
        free(p);
        return x;
    }
}
int issorted(struct node *p)
{
    int x = -65536;
    while(p != '\0')
    {
        if (p->data < x)
        {
            return 1;
        }
        else
        {
            x = p->data;
            p = p->next;
        }

    }
            return 0;


}
void duplicate(struct node *p)
{
    struct node *q;
    q = first;
    p = first->next;
    while(p != '\0')
    {
        if(p->data != q->data)
        {
            q = p;
            p = p->next;
        }
        else
        {
            q->next = p->next;
            free(p);
            p = q->next;

        }
    }
}
void reverse(struct node *p)
{
    struct node *q;
    struct node *r;
    q = '\0';
    r = '\0';
    while(p != '\0')
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;

    }
    first = q;
}
void merge(struct node *p,struct node *q )
{
    struct node *last;
    if (p->data < q->data )
    {
        third = last = p;
        p = p->next;
        third->next = '\0';

    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = '\0';
    }
    while(p !='\0' &&  q != '\0' )
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = '\0';
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = '\0';
        }
        if(p != '\0')
        {
            last->next = p;
        }
        if(q != '\0')
        {
        last->next = q;
        }
    }
}
int isloop(struct node *p)
{
    struct node *q,*r;
    q = r = p;
    do
    {
    q = q->next;
    r = r->next;
    r != '\0' ? r = r->next : r;
    }
    while(q !='\0' && r !='\0' && q != r);
    {
        if(p == q)
        {
            return 1;
        }
        else
            return 0;
    }
}
int main()
{

struct node *t1,*t2;
   int A[] = {10,20,40,50,60};
   /*int B[] = {15,18,25,30,55};*/
   create(A,5);
   t1 = first->next->next->next;
   t2 = first->next->next->next->next->next;
   t2->next = t1;
   printf("%d\n",isloop(first));
   /*create2(B,5);
   merge(first,second);
   display(third);*/
  /* reverse(first);*/
   /*duplicate(first);*/
   /*printf("%d\n",issorted(first));*/
  /* printf("delted value is %d\n",delete(first,1));*/
   /*display(first);*/
    /*insert(first,1,8);*/
       /*insertsort(first,3);*/
   /* struct node *temp;
    temp = lsearch(first,2);
    if (temp !='\0')
    {
        printf("key %d is found");
    }
    else
    {
        printf("key is not found" );
    }
    */

   /* printf("%d\n",sum(first));*/


    return 0;
}

