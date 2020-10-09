#include<iostream>
#include<string>
using  namespace std;

class list{
private:
	int *const head;
	int size,len,*current,*temp;
public:

    //Constructor for initializing List
	list()
	{
		size=8;
		head=NULL;
		head=new int[size];
		current=head;
		current=NULL;
		temp=NULL;
		len=0;

		for(int i=0; i<size; i++)
		{
            *current=0;
			current++;
		}
	}

    //Deep Copy Constructor
	list(list& othrList){
	
	
	}


    //Clear Or Empty the List
	void clear(){
	
	
	}


    //Insert a Value at Specific Position
	void insert(int value,int pos){
	

	}

    //Insert the given value in the list at the next available position
    void insert(int value){
	
	}


    //Remove a value at specific position
	void remove(int pos){
	
	

	}



    //Get value stored at a specific position
	int get(int pos){
	
	}

    //Update Existing value at a position
	void update(int value,int pos){
	

	}


    //Find a value in the list
	bool find(int value){
	

	}


    //Return Current Length of the list
	int length(){
	
	}


    //Move to starting position of the list
	void start(){
	
	}

    //Move to the end of the list
	void end(){
	
	}


};

void main(){

	

	system("pause");
}    
