#include<iostream>
#include<string>
using  namespace std;

class list{
private:
	int *head ;
	int size,len,*current,*temp;
public:

    //Constructor for initializing List
	list()
	{
		size=8;
		head=NULL;
		head=new int[size];
		current=NULL;
		current=head;
		temp=NULL;
		len=0;

		for(int i=0; i<size; i++)
		{
            *current=0;
			current++;
		}
		current=NULL;
	}

    //Deep Copy Constructor
	list(list& othrList)
	{
		this->size=othrList.size;
		this->len=othrList.len;
		this->head=new int[size];
		this->current=NULL;
		this->current=this->head;
		this->temp=NULL;
        othrList.current=othrList.head;
		
		for(int i=0; i<this->len; i++)
		{
			
			*current=*(othrList.current);
			current++;
			othrList.current++;
		}
	}


    //Clear Or Empty the List
	void clear()
	{
		temp=head;
		int x=0;
		while(x<=len)
		{
			*temp=0;
			temp++;
		}
		current=NULL;
		current=head;
		len=0;

	
	
	}


    //Insert a Value at Specific Position
	void insert(int value,int pos)
	{


		if(len>=size)
		{
			cout<<"you exceeded the limit"<<endl;
			return;
		}
		else if(len==0)
		{
			len++;
			current=head;
			*current=value;
			return;
		}
		else if(pos>len+1)
		{
			cout<<"previous positions are empty so please filled them "<<endl;
		}
		else
		{
            int *tail=NULL;
			tail=head;
			tail=tail+(len-1);
			temp=head;
			temp=temp+(pos-1);
			current=NULL;
			current=temp;
			temp=tail+1;
			while(temp!=current)
			{
				*temp=*(temp-1);
				temp--;
			}
			len++;
			*current=value;
		}
		



	}

    //Insert the given value in the list at the next available position
    void insert(int value)
	{
		if(len>=size)
		{
			cout<<"you exceeded the limit"<<endl;
			return;
		}
		else if(len==0)
		{
			len++;
			current=head;
			*current=value;
			return;
			
		}
		else
		{
			current=head;
			current=current+len;
			len++;
			*current=value;
			return;
		}

	
	}


    //Remove a value at specific position
	void remove(int value)
	{
		current=head;
		int *temp1=NULL;
		temp1=head;
		temp1=temp1+len;
		for(int i=0; i<size; i++)
		{
			

			if(*current==value)
			{

				
				
				while(current!=temp1)
				{
                    *current=*(current+1);
					current++;
					
				}


			}
			current++;
			
		}
		temp1=NULL;
		temp1=head;
		temp1=temp1+len;
		*temp1=0;

		len--;

	
	

	}



    


    //Move to starting position of the list
	void start()
	{
		current=head;
	
	}

    //Move to the end of the list
	void end()
	{
		current=head;
		current=current-(len-1);
	
	}

	void show()
	{
		int *temp1=NULL;
		temp1=head;
		int x=0;
		while(x<len)
		{
			cout<<*temp1<<",";
			temp1++;
			x++;

		}
		cout<<endl;
	}


};

int main()
{
	list l1;
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.insert(6);
	l1.insert(7);
	cout<<"first list : ";
    l1.show();
	
	list l2(l1);
	cout<<"second list : ";
	l2.show();
	l1.remove(2);
	l1.show();
	l1.insert(0,3);
	l1.show();
    
	
	

}    
