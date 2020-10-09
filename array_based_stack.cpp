#include <iostream>
using namespace std;

const int size=8;

class stack
{
    int *top;
    int *arr;
    int len;
    public:
        stack();
        bool is_empty();
        bool is_full();
        void push(int val);
        int pop();
        void show();
        

};

stack::stack()
{
    top=NULL;
    len=0;
    arr=new int[size];
    
}

bool stack::is_empty()
{
    if(len==0)
    {
        top=NULL;
        return true;
    }
    return false;
}

bool stack::is_full()
{
    if(len==size)
    {
        return true;
    }
    return false;
}

void stack::push(int val)
{
    if(!stack::is_full())
    {
        if(top==NULL)
        {
            top=arr;
            *top=val;
            // top++;
            len++;
            return;

        }
        top++;
        *top=val;
        len++;
        return;
    }
    cout<<"STACK IS FULL :)"<<endl;
}

int stack::pop()
{
    if(!stack::is_empty())
    {
        int x=0;
        x=*top;
        top--;
        len--;
        return x;
    }
    cout<<"STACK IS EMPTY (:"<<endl;
}

void stack::show()
{
    int *temp=arr;
    int x=0;
    while(x<len)
    {
        cout<<*temp<<endl;
        temp++;
        x++;
    }

}

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.show();
    cout<<"poped value is : "<<s.pop()<<endl;
    cout<<"poped value is : "<<s.pop()<<endl;
    cout<<"poped value is : "<<s.pop()<<endl;
    cout<<"poped value is : "<<s.pop()<<endl;
    cout<<"poped value is : "<<s.pop()<<endl;
    cout<<"poped value is : "<<s.pop()<<endl;
    cout<<"poped value is : "<<s.pop()<<endl;
    cout<<"poped value is : "<<s.pop()<<endl;
    //cout<<"poped value is : "<<s.pop()<<endl;

    //s.show();

}