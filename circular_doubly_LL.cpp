#include <iostream>
using namespace std;

class node
{
    public:
        int val;
        node *next;
        node *prev;

        node(int val)
        {
            this->val=val;
            next=NULL;
            prev=NULL;
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
        
        if(head==NULL)
        {

            
            node *n=new node(val);
            n->next=n;
            n->prev=n;
            head=n;
            len++;


        }
        else
        {
            if(pos==1)
            {
                
                node *temp=NULL;
                node *n=new node(val);
                
                temp=list::last_element();
                head->prev=n;
                n->next=head;
                n->prev=temp;
                temp->next=n;
                
                head=n;   
                len++;         
            }
            else if(pos>(len+1))
            {
                cout<<"this is an invalid position"<<endl;
                return;
            }
            else if(pos==(len+1))
            {
                
                node *temp=NULL;
                temp=list::last_element();
                node *n=new node(val);
                temp->next=n;
                n->prev=temp;
                n->next=head;
                head->prev=n;
                len++;
            }
            else
            {
                
                node *temp=head;
                int count=1;
                while(temp->next!=NULL && count<(pos-1))
                {
                    temp=temp->next;
                    count++;

                }
                node *n=new node(val);
                n->next=temp->next;
                n->prev=temp;
                temp->next=n;
                n->next->prev=n;
                len++;

            
        }
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
            head->prev=temp1;
            temp1->next=head;
            temp->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
        else if(pos==len)
        {
            len--;
            node *temp=NULL;
            node *temp_next=NULL;
            temp=list::last_element();
            temp=temp->prev;
            temp->next=head;
            head->prev=temp;
            temp_next=temp->next;
            temp->next=NULL;
            temp_next->next=NULL;
            temp_next->prev=NULL;
            delete temp_next;
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
            temp_next->next->prev=temp;
            temp_next->prev=NULL;
            temp_next->next=NULL;
            delete temp_next;
        }
    }
    
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
    // node *temp1=NULL;
    // temp1=head;
    int x=0;
    
    while(x<len)
    {
        cout<<temp->val<<",";
        temp=temp->next;
        x++;

    }
    
    cout<<endl;
    x=0;
    temp=temp->prev;
    while(x<len)
    {
        cout<<temp->val<<",";
        temp=temp->prev;
        x++;
    }

    cout<<endl;
}



int main()
{
    list l1;
    l1.insert(6,1);
    l1.insert(5,1);
    l1.insert(4,1);
    l1.insert(3,1);
    l1.insert(2,1);
    l1.insert(1,1);
    l1.print(); 



    cout<<"AFTER REMOVING THE VALUE"<<endl;
    l1.remove(1);
    l1.print();
    // cout<<"length of list is : "<<l1.length()<<endl;
    // l1.get(3);
    // cout<<"value found or not : "<<l1.find(9)<<endl;
}