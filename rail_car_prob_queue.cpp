#include <iostream>
using namespace std;
const int size=9;

class node
{
    public:
        int val;
        node *next;

        node(int val)
        {
            this->val=val;
            next=NULL;
        }
};

class queue
{
    
    public:
        node *head;
        node *rear;
        node *front;
        int front_val;
        int len;
        queue();
        void enqueue(int val);
        int dequeue();
        bool is_empty();
};


bool queue::is_empty()
{
    if(len==0)
    {
        front=NULL;
        head=NULL;
        rear=NULL;
        front_val=0;
        return true;
    }
    return false;
}

queue::queue()
{
    head=NULL;
    rear=NULL;
    front=NULL;
    front_val=0;
    len=0;
}

void queue::enqueue(int val)
{
    if(len<10)
    {
        if(head==NULL)
        {
            len++;
            node *n=new node(val);
            n->next=head;
            head=n;
            rear=head;
            front=head;
        }
        else
        {
            len++;
            node *n=new node(val);
            rear->next=n;
            rear=rear->next;
        }
    }
    else
    {
        cout<<"OVERFLOW"<<endl;

    }

}

int queue::dequeue()
{
    if(len==0)
    {
        cout<<"UNDERFLOW"<<endl;
    }
    else
    {
        if(front==rear)
        {
            len--;
            int x=0;
            x=head->val;
            head=NULL;
            front=NULL;
            rear=NULL;
            return x;
        }
        else
        {
            len--;
            node *temp=NULL;
            temp=front;
            int x=0;
            x=temp->val;
            front=front->next;
            head=front;
            delete temp;
            front_val=x;
            return x;
        }
    }
           
}


void rail_car(int arr[]);



int main()
{
    int arr[size]={5,8,1,7,4,2,9,6,3};
    int arr1[size]={9,7,8,6,3,1,5,4,2};
    rail_car(arr);

    rail_car(arr1);


    //978631542
}



void rail_car(int arr[size])
{
    queue h1,h2,h3;

    int new_arr[size];
    int new_len=0;

    int index=size-1;
    int new_index=size-1;

    int turn=1;

    while(new_len<9)
    {

        if (arr[index]==turn && index>=0)
        {
            h1.enqueue(arr[index]);
            new_arr[new_index]=h1.dequeue();
            new_len++;
            new_index--;
            index--;
            turn++;
        }
        
        if(h2.is_empty()==true && index>=0)
        {
            h2.enqueue(arr[index]);
            index--;
        }
        while(h2.rear->val<arr[index] && index>=0)
        {
            
            h2.enqueue(arr[index]);
            index--;
        }
        if(h3.is_empty()==true && index>=0)
        {
            h3.enqueue(arr[index]);
            index--;
        }

        if(index>=0)
        {
            while(h3.rear->val<arr[index] && index>=0)
            {
                
                h3.enqueue(arr[index]);
                index--;
            }
        }
        
        
        
        if( h2.is_empty()==false && h2.front->val==turn)
        {
            new_arr[new_index]=h2.dequeue();
            new_index--;
            new_len++;
            turn++;
            
        }
        if(h2.is_empty()==false && h3.front->val==turn )
        {
            new_arr[new_index]=h3.dequeue();
            new_index--;
            new_len++;
            turn++;
            
        }

    }
    for(int i=0; i<size; i++)
    {
        cout<<new_arr[i]<<",";
    }
    cout<<endl;

}
