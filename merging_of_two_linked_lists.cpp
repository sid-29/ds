
#include<iostream>
#include<conio.h>
#include<process.h>
using namespace std;
//   Creating a NODE Structure
struct node
{
   int data;  // data
   struct node *next;  // link to next node and previous node
};

// Creating a class LIST
class list
{
   struct node *start;
   public:
      void create(); // to create a list
      void show();   // show
      void merge(list,list);  // Merge two list's
};

// Main function
int main()
{
    list l1,l2,l3;
   cout<<"Enter the First List in ascending order";
   l1.create(); // to create a first list
   cout<<"Enter the Second List in ascending order.";
   l2.create(); // to create a second list
   cout<<"The first list is";
   l1.show();
   cout<<"The second list is";
   l2.show();
   l3.merge(l1,l2);
   l3.show();
   getch();
   return (0);
}

//    Functions

// Creating a new node
void list::create()
{
   struct node *nxt_node,*pre_node;
   int value,no,i;
   start=nxt_node=pre_node=NULL;
   cout<<"How many nodes : ";
   cin>>no;
   cout<<"Enter "<<no<<" Elements: ";
   for(i=1;i<=no;i++)
   {
      cin>>value;
      nxt_node=new node;
      nxt_node->data=value;
      nxt_node->next=NULL;
      if(start==NULL)
	 start=nxt_node;
      else
	 pre_node->next=nxt_node;
      pre_node=nxt_node;
   }
   cout<<"The list is created!";
}

// Displaying LIST
void list::show()
{
   struct node *ptr=start;
   cout<<"The List is ";
   while(ptr!=NULL)
   {
      cout<<ptr->data<<" -> ";
      ptr=ptr->next;
   }
   cout<<"   ";
}

void list::	merge(list l1,list l2)
{
   struct node *nxt_node,*pre_node,*ptr1,*ptr2;
   int dat;
   ptr1=l1.start;
   ptr2=l2.start;
   start=nxt_node=pre_node=NULL;

   while(ptr1!=NULL && ptr2!=NULL)
   {
      if(ptr1->data<=ptr2->data)
      {
		dat=ptr1->data;
		ptr1=ptr1->next;
      }

      else
      {
		dat=ptr2->data;
		ptr2=ptr2->next;
      }

      nxt_node=new node;
      nxt_node->data=dat;
      nxt_node->next=NULL;
      if(start==NULL)
		start=nxt_node;
      else
		pre_node->next=nxt_node;
      pre_node=nxt_node;
   }
   if(ptr1==NULL)
   {
      while(ptr2!=NULL)
      {
		nxt_node=new node;
		nxt_node->data=ptr2->data;
		nxt_node->next=NULL;
			if(start==NULL)
				start=nxt_node;
			else	
				pre_node->next=nxt_node;
		pre_node=nxt_node;
		ptr2=ptr2->next;
      }
   }
   else if(ptr2==NULL)
   {
      while(ptr1!=NULL)
      {
		nxt_node=new node;
		nxt_node->data=ptr1->data;
		nxt_node->next=NULL;
			if(start==NULL)
				start=nxt_node;
			else
				pre_node->next=nxt_node;
		pre_node=nxt_node;
	 ptr1=ptr1->next;
      }
   }
   cout<<"The lists are merged.";
   return;
}
