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
    //node *last_head;
    int len;
    public:
        list();
        void insert(int val,int pos);
        void print();
        void remove(int val);
        void leader();
        node* last_element();

};

node* list::last_element()
{
    node *temp=head;
    int x=0;
    while(x<len-1)
    {
        temp=temp->next;
        x++;

    }
    return temp;
}

list::list()
{
    head=NULL;
    len=0;
}

void list::insert(int val,int pos)
{
    if(pos==1)
    {
        len++;
        node *n=new node(val);
        n->next=head;
        //last_head=head;
        
        head=n;
        //cout<<head<<endl;
        if(len==1)
        {
            head->next=head;
            return ;
        }
    
        node* temp=NULL;
        temp=list::last_element();
        temp->next=head;
    }
    else if(pos>(len+1))
    {
        cout<<"this is an invalid position"<<endl;
        return;
    }
    else if(pos==(len+1))
    {
        
        node *temp=head;
        int x=1;
        while(x<len)
        {
            temp=temp->next;
            x++;
        }
        node *n=new node(val);
        temp->next=n;
        n->next=head;
        len++;
    }
    else
    {
        len++;
        node *temp=head;
        int count=1;
        while(temp->next!=NULL && count<(pos-1))
        {
            temp=temp->next;
            count++;

        }
        node *n=new node(val);
        n->next=temp->next;
        temp->next=n;
    }

}

void list::remove(int pos)
{
    if(pos>len)
    {
        cout<<"this position does not exist (:"<<endl;
    }
    else
    {

        if(pos==1)
        {
            len--;
            node *temp=head;
            node *temp1=NULL;
            head=head->next;
            temp1=list::last_element();
            temp1->next=head;
            delete temp;
        }
        else if(pos==len)
        {
            len--;
            node *temp=head;
            node *temp_next=NULL;
            int x=1;
            while(x<len)
            {
                temp=temp->next;
                x++;
            }
                temp_next=temp->next;
                delete temp_next;
                temp->next=head;
                
                return ;
        }
        else
        {
            len--;
            node *temp=head; 
            node *temp_next=NULL;
            int count=1;
            while(count<pos-1)
            {
                temp=temp->next;
                count++;
            }
            temp_next=temp->next;
            temp->next=temp_next->next;
            delete temp_next;
        }
    }
        
}
  
void list::leader()
{
    node *temp=head;
    
    while(len!=1)
    {
        node *temp1=NULL;
        int x=1;
        while(x<3)
        {
            temp=temp->next;
            x++;

        }
        temp1=temp->next;
        temp->next=temp1->next;
        temp1=NULL;
        delete temp1;
        temp=temp->next;
        len--;

    }
    head=temp;

}

void list::print()
{
    node *temp=head;
    //cout<<head<<endl;
    int x=0;
    
    while(x<len)
    {
        cout<<temp->val<<",";
        temp=temp->next;
        x++;

    }

    cout<<endl;
}



int main()
{
    list l1;
    l1.insert(1,1);
    l1.insert(2,2);
    l1.insert(3,3);
    l1.insert(4,4);
    l1.insert(6,5);
    l1.insert(7,6);
    l1.insert(8,7);
    l1.insert(9,8);
    l1.insert(10,9);
    l1.print();
    cout<<"AFTER INSERTION OF 5 AT 5TH POSITION"<<endl;
    l1.insert(5,5);
    l1.print();
    cout<<"AFTER DELETION OF 5 AT 5TH POSITION"<<endl;
    l1.remove(5);
    l1.print(); 
    cout<<"LEADER IS : ";  
    l1.leader();
    l1.print(); 
}