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

class stack
{
    node *top;
    node *head;
    int len;
    public:
        stack();
        bool is_empty();
        void push(int val);
        int pop();
        void show();
};


stack::stack()
{
    top=NULL;
    head=NULL;
    len=0;
}

bool stack::is_empty()
{
    if(len==0)
    {
        top=NULL;
        head=NULL;
        return true;
    }
    return false;
}

void stack::push(int val)
{
        if(top==NULL && head==NULL)
        {
            
            node *n=new node(val);
            head=n;
            top=head;
            len++;
            return;

        }
        node *n=new node(val);
        top->next=n;
        top=n;
        len++;
        return;
}

int stack::pop()
{
    if(!stack::is_empty())
    {

        if(len==1)
        {
            len--;
            int x=0;
            x=top->val;
            top=NULL;
            head=NULL;
            return x;

        }
        else
        {
            len--;
            node *temp=head;
            node *temp1=NULL;
            int x=0;
            while(temp->next!=top)
            {
                temp=temp->next;
            } 
            temp1=top;
            x=temp1->val;
            top=temp;
            temp->next=NULL;
            delete temp1;
            return x;
        }
        
    }
    else
    {
        cout<<"STACK IS EMPTY (:"<<endl;
    }
    
}

void stack::show()
{
    node *temp=head;

    while(temp!=NULL)
    {
        cout<<temp->val<<",";
        temp=temp->next;
    }
    cout<<endl;
    
}


void bracket(string str);

int main()
{
    

    bracket("(a+b))(");

    

}



void bracket(string str)
{
    stack s;

    for (int i=0; i<str.length(); i++)
    {
        if (str[i]=='(')
        {
            s.push(i);
        }
        else if(str[i]==')')
        {
            if(s.is_empty())
            {
                cout<<"there is a right bracket at "<<i<<" position its left bracket is not present"<<endl;
                
            }
            else
            {
                s.pop();
            }
        }
    }

    while(!s.is_empty())
    {
        cout<<"there is a left bracket at "<<s.pop()<<" position its right bracket is not present"<<endl;
    }
    
}
