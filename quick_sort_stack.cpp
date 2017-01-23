#include<iostream>
#include<stack>
using namespace std;



class quicksort
{
public:	

	void quick()
	{

stack<int>upper;
stack<int>lower;	
	
	int n,i,beg,end,loc;
cout<<"enter the no of elements \n";
cin>>n;
int a[n];

	for(i=0;i<n;i++)
	{
	cin>>a[i];	
	}

upper.push(n-1);
lower.push(1);
			while(!lower.empty() && !upper.empty())
			{
				beg=lower.top();
				end=upper.top();
				lower.pop();
				upper.pop();
				loc=quick_sort(a,n,beg,end);
					if(beg<(loc-1))
					{
						lower.push(beg);
						upper.push(loc-1);
					}
			
						if((loc+1)<end)
						{
							lower.push(loc+1);
							upper.push(end);
						}

			}
	if(lower.empty() && upper.empty())
	{
		cout<<"sorted elements are : \n";
		for(i=0;i<n;i++)
		{
		cout<<a[i]<<endl;	
		}
		
	}		
	}

int quick_sort(int a[],int n,int beg,int end)
{
int left,right,loc,flag1=0,flag2=0;
left=beg;
right=end;
loc=beg;	
	while(flag1!=0 && flag2!=0)
	{
		while(a[loc]<=a[right]&& loc!=right)
		{
			right=right-1;
		}
	
			if(loc==right)
			{
				flag1=1;
			}
	
				else if(a[loc]>a[right])
				{
					int temp=a[loc];
					a[loc]=a[right];
					a[right]=temp;
					
					loc=right;
				}
					while(a[left]<=a[loc] && loc!=left)
					{
					left=left+1;
					}
						if(loc==left)
						{
						flag2=1;
						}
							else if(a[loc]<a[left])
							{
							int temp=a[loc];
							a[loc]=a[left];
							a[left]=temp;
							loc=left;
							}		


	}
	return loc;
}

};

void main()
{
	quicksort q;
	q.quick();
	return 0;
}




