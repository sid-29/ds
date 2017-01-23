#include<iostream>
using namespace std;

class merge1
{
    struct node
    {
    int data;
    node *link;
    } *start=NULL,*newnode;
public:
    void create()
    {
        newnode=new(struct node);
        int v;
        cin>>v;
        newnode->data=v;
        newnode->link=NULL;
	}

	void insert1()
	{
            create();
	    if(start==NULL)
    	    {
                start=newnode;
    	    }
    	    else
            {
      		struct node *ptr;
    		ptr=start;
    		while(ptr->link!=NULL)
    		{
        	    ptr=ptr->link;
    		}
                ptr->link=newnode;
                newnode->link=NULL;

            }
    }
void mergee( merge1 m1,merge1 m2)
{
    struct node *ptr,*ptr1;
    start=m1.start;
    ptr= start;

    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=m2.start;
    ptr1=ptr->link;
    while(ptr1->link!=NULL)
    {
        ptr1=ptr1->link;
    }


}

void sort1()
{
    struct node *ptr,*ptr1;
    ptr=start;

    while(ptr->link!=NULL)
    {
        ptr1=ptr->link;
        while(ptr1->link!=NULL)
        {
            if(ptr->data>ptr1->data)
            {
                int temp=ptr->data;
                ptr->data=ptr1->data;
                ptr1->data=temp;
            }
            ptr1=ptr1->link;
        }
ptr=ptr->link;
    }
}

void display()
{

    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {

        cout<<ptr->data;
        ptr=ptr->link;
    }
    cout<<endl;
}
};
main()
{
    merge1 m1,m2,m3;

    for(int i=0;i<4;i++)
    {
        m1.insert1();

    }

    m1.display();
    cout<<"enter second list"<<endl;
    for(int i=0;i<5;i++)
    {
        m2.insert1();

    }
    m2.display();
    m3.mergee(m1,m2);
    m3.sort1();
    m3.display();
}



