#include <iostream>
using namespace std;

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

class list
{
    node *head;
    node *rear;
    node *front;
    int len;
    public:
        list();
        void enqueue(int val);
        void print();
        int dequeue();
};


list::list()
{
    head=NULL;
    rear=NULL;
    front=NULL;
    len=0;
}

void list::enqueue(int val)
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

int list::dequeue()
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
            return x;
        }
    }
           
}


int main()
{
    list l1;
    l1.enqueue(1);
    l1.enqueue(2);
    l1.enqueue(3);
    l1.enqueue(4);
    l1.enqueue(5);
    l1.enqueue(6);
    l1.enqueue(7);
    l1.enqueue(8);
    l1.enqueue(9);
    l1.enqueue(10);
    l1.enqueue(11);
    
     
    cout<<"AFTER REMOVING THE VALUE"<<endl;
    l1.dequeue();
    l1.dequeue();
    l1.dequeue();
    l1.dequeue();
    l1.dequeue();
    l1.dequeue();
    l1.dequeue();
    l1.dequeue();
    l1.dequeue();
    l1.dequeue();
    

    
}