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
    int len;
    public:
        list();
        void insert(int val,int pos);
        void print();
        void remove(int val);
        int length();
        void get(int pos);
        bool find(int val);
        bool empty();

};


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
        head=n;
    }
    else if(pos>(len+1))
    {
        cout<<"this is an invalid position"<<endl;
        return;
    }
    else if(pos==(len+1))
    {
        len++;
        node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        node *n=new node(val);
        temp->next=n;
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
            head=head->next;
            delete temp;
        }
        else if(pos==len)
        {
            len--;
            node *temp=NULL;
            temp=head;
            node *temp_next=NULL;
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
                temp_next=temp->next;
                delete temp_next;
                temp->next=NULL;
                
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
    
bool list::empty()
{
    if(head==NULL)
    {
        return 1;

    }
    return 0;
}


bool list::find(int val)
{
    node *temp=NULL;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->val==val)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;


}

void list::get(int pos)
{
    int count=1;
    node *temp=NULL;
    temp=head;
    while(count<=len)
    {
        if(count==pos)
        {
            cout<<"value at position "<<count<<" is "<<temp->val<<endl;
            return;
        }
        temp=temp->next;
        count++;

    }
}

int list::length()
{
    return len;
}


void list::print()
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<",";
        temp=temp->next;

    }
    cout<<endl;
}



int main()
{
    list l1;
    l1.insert(1,1);
    l1.insert(2,1);
    l1.insert(3,3);
    
    // l1.insert(5,5);
    // l1.insert(6,6);
    l1.insert(4,4);
    l1.insert(0,4);
    l1.print();
     
    cout<<"AFTER REMOVING THE VALUE"<<endl;
    l1.remove(6);
    l1.print();
    cout<<"length of list is : "<<l1.length()<<endl;
    l1.get(3);
    cout<<"value found or not : "<<l1.find(9)<<endl;
    cout<<"check the emptyness of list : "<<l1.empty()<<endl;

}