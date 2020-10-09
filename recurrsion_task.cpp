#include <iostream>
using namespace std;


void palindrome(string str,int s,int e)
{
    if(str.length()%2!=0)
    {
        if(s==e)
        {
            /*if(str[s]==str[e])
            {*/
                cout<<"PALINDROME"<<endl;
            /*}
            else
            {
                
                cout<<"NOT PALINDROME"<<endl;
            }*/
            
        }
        else if(str[s]==str[e])
        {
            s++;
            e--;
            palindrome( str, s, e);
        }
        else
        {
            //cout<<"haha"<<endl;
            
            cout<<"NOT PALINDROME"<<endl;
        }
    }
    else
    {
        if(s==(str.length()/2)-1 && e==(str.length()/2))
        {
            if(str[s]==str[e])
            {
                cout<<"PALINDROME"<<endl;
            }
            else
            {
                
                cout<<"NOT PALINDROME"<<endl;
            }
            
        }
        else if(str[s]==str[e])
        {
            s++;
            e--;
            palindrome( str, s, e);
        }
        else
        {   
            cout<<"NOT PALINDROME"<<endl;
        }
    }
    
    
}

const int size=5;

void fun1(int *arr,int pos,int index,int val)
{
    if(pos!=size)
    {
        if(index==size)
        {
            *(arr+pos)=val;
            val=1;
            pos++;
            index=0;
            fun1(arr,pos,index,val);
        }
        else if(index==pos)
        {
            index++;
            fun1(arr,pos,index,val);
        }
        else
        {
            val=val*(*(arr+index));
            index++;
            fun1(arr,pos,index,val);
        }

    }
    
}

int factorial(int n)
{
    if(n>1)
        return n*factorial(n-1);
    else
        return 1;
}





int main()
{

//  PALINDROME

    string str="civic";
    int e=str.length()-1;
    palindrome(str,0,e);

    cout<<endl;

//  ARRAY MULTIPLICATION  

    int arr[size]={1,2,1,1,2};
    fun1(arr,0,0,1);

    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<endl;

//  FACTORIAL

    int num=5;
    cout<<"factorial of "<<num<<" is "<<factorial(num);


}