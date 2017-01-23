#include<iostream>
using namespace std;
struct node
{
   int data; 
   struct node *next;  
};


class list
{
    struct node *start;
public:
    void create(); 
    void show(); 
    void delete_mid();
    void reverse();
};

int main()
{
    list l1;
    l1.create();
    l1.delete_mid();
    l1.reverse();
    l1.show();
    return (0);
}

void list::create()
{
   struct node *nxt_node,*pre_node;
   int value,no,i;
   start=nxt_node=pre_node=NULL;
 while(value!=(-1))
   {
      cin>>value;
      if(value!=(-1))
      {
          nxt_node=new node;
          nxt_node->data=value;
          nxt_node->next=NULL;
          if(start==NULL)
	     start=nxt_node;
          else
	     pre_node->next=nxt_node;
          pre_node=nxt_node;
      }
    }
}

void list::show()
{
   struct node *ptr=start;
   while(ptr!=NULL)
   {
      cout<<ptr->data<<endl;
      ptr=ptr->next;
   }
}

void list::delete_mid()
{
    struct node *ptr,*ptr1,*ptr2;
    int c=0;
    ptr=start;
    while(ptr!=NULL)
        {
            ptr=ptr->next;
            c++;
        }
        ptr1=start;
        if(c%2==0)
        {
            for(int i=1;i<(c/2);i++)
            {
                ptr1=ptr1->next;
            }
        }
        else
        {
            for(int i=1;i<((c/2)+1);i++)
            {
                ptr1=ptr1->next;
            }
        }
        ptr2=ptr1->next;
        ptr1->next=ptr2->next;
        free(ptr2);
}

void list::reverse()
{
    struct node *ptr,*current,*prev;
    prev = NULL;
    current=start;

    while(current != NULL)
    {

        ptr=current->next;
        current->next=prev;
        prev=current;
        current=ptr;
    }
    start=prev;
}
