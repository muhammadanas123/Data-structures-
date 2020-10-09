#include <iostream>
using namespace std;
const int size=3;

class list
{
	int *head;
	int *rear;
	int *front;
	int arr[size];
	
	

	public:
	    int len;
	    static int count;
		list();
		
		void enqueue(int val);
		void dequeue();
		void show();
};
int list::count=0;
list::list()
{

	head=NULL;
    rear=NULL;
	front=NULL;
	head=arr;
	len=0;
	
}


void list::enqueue(int val)
{
	if(rear==NULL)
	{
		rear=arr;
		front=head;
		*rear=val;
		len++;
    	
	}
	else if(len==1)
	{
		len++;
		rear++;
		*rear=val;
		
	}
	else if(front==arr && rear!=arr+(size-1))
	{
		rear++;
		len++;
		*rear=val;
		
	}
	
	else if(rear==arr+(size-1) && *head==-1)
	{
		len++;
		rear=arr;
		*rear=val;
		
	}
	else if(front==rear+1)
	{
		
		cout<<"OVERFLOW"<<endl;
	}
	else if(front==arr && rear==arr+(size-1))
	{
		cout<<"OVERFLOW"<<endl;
	}
	

		
}


void list::dequeue()
{
	
	
    if(front==arr+(size-1))
	{
		len--;
		front=arr;
		cout<<"dequeued is "<<*front<<endl;
		*front=-1;
	}
	else if(count==1)
	{
		
		front++;
		len--;
		cout<<"dequeued is "<<*front<<endl;
		count--;
		*front=-1;
	}
	else if(front==arr && len==size)
	{
		len--;
		count=0;
		count++;
		cout<<"dequeued is "<<*front<<endl;
		*front=-1;
		return;
		
	}
	else if(front==rear || len==0)
	{
		cout<<"UNDERFLOW"<<endl;
	}
	else
	{
		front++;
		len--;
		cout<<"dequeued is "<<*front<<endl;
		*front=-1;
	}
	


}

void list::show()
{
	int *temp=NULL;
	temp=arr;
   
    int x=0;
	while(x<size)
	{
        cout<<*temp<<",";		
		temp++;
		x++;
	}
	cout<<endl;
    
}

int main()
{
	list l;
	l.enqueue(1);
	l.enqueue(2);
	l.enqueue(3);
	l.show();
	l.dequeue();
	l.enqueue(4);
	l.show();
	l.dequeue();
	l.dequeue();
	l.dequeue();
	l.show();
	l.dequeue();
	l.enqueue(9);
	l.show();

	
}
