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


void rail_car(int arr[]);



int main()
{

int arr[size]={1,5,3,6,7,9,8,4,2};


 rail_car(arr);



}



void rail_car(int arr[size])
{
    stack h1,h2,h3;

    int new_arr[size];
    int new_len=0;

    int index=size-1;
    int new_index=size-1;

    int h1_val=0;
    int h2_val=0;
    int h3_val=0;

    int diff1=0;
    int diff2=0;
    int diff3=0;


    int turn=1;

    while(new_len<9)
    {
        if (arr[index]==turn && index>=0)
        {
            new_arr[new_index]=arr[index];
            new_len++;
            new_index--;
            index--;
            turn++;
        }
        if(h1_val==turn)
        {

            new_arr[new_index]=h1.pop();
            new_index--;
            new_len++;
            turn++;
            if(h1.is_empty()==false)
            {
                h1_val=h1.pop();
                h1.push(h1_val);
            }
            else
            {
                h1_val=0;
            }
        }
        if(h2_val==turn)
        {
            new_arr[new_index]=h2.pop();
            new_index--;
            new_len++;
            turn++;
            if(h2.is_empty()==false)
            {
                h2_val=h2.pop();
                h2.push(h2_val);
            }
            else
            {
                h2_val=0;
            }
        }
        if(h3_val==turn)
        {
            new_arr[new_index]=h3.pop();
            new_index--;
            new_len++;
            turn++;
            if(h3.is_empty()==false)
            {
                h3_val=h3.pop();
                h3.push(h3_val);
            }
            else
            {
                h3_val=0;
            }
        }



        if(h1.is_empty()==true && index>=0)
        {
            h1_val=arr[index];
            h1.push(h1_val);
            index--;
        }
        if(h2.is_empty()==true && index>=0)
        {
            h2_val=arr[index];
            h2.push(h2_val);
            index--;
        }
        if(h3.is_empty()==true && index>=0)
        {
            h3_val=arr[index];
            h3.push(h3_val);
            index--;
        }
        
        if (index>=0)
        {
            
            diff1=0;
             diff2=0;
             diff3=0;

            if(arr[index]<h1_val || h1_val==0)
            {
                if(h1_val==0)
                {
                    h1.push(arr[index]);
                    index--;
                }
                else
                {
                    diff1=h1_val-arr[index];
                }
            }
            if(arr[index]<h2_val || h2_val==0)
            {
                if(h2_val==0)
                {
                    h2.push(arr[index]);
                    index--;
                }
                else
                {
                    diff2=h2_val-arr[index];
                }
            }
            if(arr[index]<h3_val || h3_val==0)
            {
                if(h3_val==0)
                {
                    h3.push(arr[index]);
                    index--;
                }
                else
                {
                    diff3=h3_val-arr[index];
                }
            }

            if(diff1==0)
            {
                goto L1;
            }
            else if((diff1<diff2 && diff1<diff3) || diff2==0 || diff3==0)
            {
                h1_val=arr[index];
                h1.push(h1_val);
                index--;
                goto L3;
            }

            L1:
            if(diff2==0)
            {
                goto L2;
            }
            else if((diff2<diff1 && diff2<diff3) || diff1==0 || diff3==0)
            {
                h2_val=arr[index];
                h2.push(h2_val);
                index--;
                goto L3;
            }

            L2:
            if(diff3==0)
            {
                goto L3;
            }
            else if(diff3<diff1 && diff3<diff2 || (diff1==0 || diff2==0))
            {
                h3_val=arr[index];
                h3.push(h3_val);
                index--;
            }

            L3:
            
            if(h1.is_empty()==true || h2.is_empty()==true || h3.is_empty()==true  )
            {
                goto L4;
            }
            else if(arr[index]>h1_val && arr[index]>h2_val && arr[index]>h3_val)
            {
                cout<<"it can't be arrange by this procedure (:"<<endl;
                goto L5;
            }
            
            L4:;

        }
             


    }

    for(int i=0; i<size; i++)
    {
        cout<<new_arr[i]<<",";
    }

    L5:;

}
