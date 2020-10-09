#include <iostream>
using namespace std;
class list
{
	int *head;
	int *tail;
	int *current;
	public:
		list();
		void start();
		void end();
		void next();
		void back();
		void add(int val);
		void update(int val);
		void remove();
		void get();
		void show();
		void length();
};

list::list()
{
	int *head=NULL;
    int *tail=NULL;
	int *current=NULL;
}

void list::start()
{
	head=new int[8];
	current=head;
	tail=head;
    int *temp=NULL;
	temp=head;
    
	for(int i=0; i<8; i++)
	{
        *temp=-1;
		temp++;
	}
}

void list::end()
{
    while(*tail!=-1)
	{
		tail++;
	}
}

void list::next()
{
	current=current+1;
}

void list::back()
{
	current=current-1;
}

void list::length()
{
	int *temp=NULL;
	temp=head;
	int x=0;
	while(temp!=tail+1)
	{
		temp++;
		x++;
	}
	cout<<"length is : "<<x<<endl;

}

void list::get()
{
	cout<<"currently pointer points : "<<*current<<endl;
}

void list::add(int val)
{
	if(*current==-1)
	{
    	list::end();
		*current=val;
		list::next();
	}
	else
	{
		int *ptr=NULL;
		ptr=current;
		while(ptr!=tail+1)
		{
			ptr++;
		}

		tail++;

		while(ptr!=current)
		{
			*(ptr+1)=*ptr;
			ptr--;
		}
		*(current+1)=val;
		list::next();
	}
}

void list::update(int val)
{
	*current=val;
}

void list::remove()
{
	int *temp=NULL;
	temp=current;
	
	while(temp!=tail)
	{
		
		*temp=*(temp+1);
		temp++;
		
	}
	*tail=-1;
	tail--;
}

void list::show()
{
	int *temp=NULL;
	temp=head;
    cout<<"address of head is : "<<head<<endl;
	cout<<"address of tail is : "<<tail<<endl;
	cout<<"address of current is : "<<current<<endl;
	cout<<endl;
    int x=1;
	while(temp!=tail+1)
	{
        cout<<"value "<<x<<" is : "<<*temp<<endl;
        cout<<"address of value "<<x<<" is : "<<temp<<endl;
		
		temp++;
		x++;
	}
    cout<<endl;
	cout<<"head's value : "<<*head<<endl;
	cout<<"tail's value : "<<*tail<<endl;
	cout<<"current's value : "<<*current<<endl;
	cout<<endl;
}

int main()
{
	list l;
	l.start();
	l.add(22);
	l.add(11);
	l.add(33);
	l.back();
	l.back();
	l.back();
	l.add(9);
	l.show();
	cout<<endl;
    cout<<"AFTER REMOVE THE VALUE"<<endl;
	cout<<endl;
	l.remove();
	l.show();  
	cout<<endl;  
	cout<<"AFTER UPDATING THE VALUE"<<endl;
	cout<<endl;
	l.update(99);
	l.show();
	l.get();
	l.length();
}
