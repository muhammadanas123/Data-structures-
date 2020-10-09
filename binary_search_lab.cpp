#include <iostream>
using namespace std;

class node
{
    public:
        int val;
        node *left;
        node *right;

        node(int val)
        {
            this->val=val;
            left=NULL;
            right=NULL;
        }

};

class tree
{
    
    public:
        node* root;
        tree();
        void insertion(int val,node *ptr);
        node* deletion(int val, node *ptr);
        void inorder(node* ptr); 
        void preorder(node* ptr); 
        void postorder(node* ptr); 
        void search(int val,node* ptr);
        node* maximum(node* ptr);
        node* minimum(node* ptr);
        node *successor(int val, node *ptr);
        node *predecessor(int val, node *ptr);
        void print(node* ptr);
        int getlevel(node *ptr,int val,int level);

        
};

tree::tree()
{
    root=NULL;
    
}

void tree::insertion(int val, node *ptr=NULL)
{
    if(root==NULL)
    {
        node *n=new node(val);
        root=n;
    }
    else if(val<ptr->val)
    {
        if(ptr->left==NULL)
        {
            node *n=new node(val);
            ptr->left=n;
        }
        else
        {
            ptr=ptr->left;
            insertion(val,ptr);
        }
    }
    else if(val>ptr->val)
    {
        if(ptr->right==NULL)
        {
            node *n=new node(val);
            ptr->right=n;
        }
        else
        {
            ptr=ptr->right;
            insertion(val,ptr);
        }
    }
}



void tree::inorder(node* ptr) 
{ 
    if (ptr==NULL)
    {
        return;
    } 
    inorder(ptr->left); 
    cout<< ptr->val<<","; 
    inorder(ptr->right); 
} 

void tree::preorder(node* ptr) 
{ 
    if (ptr==NULL)
    {
        return; 
    } 
    cout<<ptr->val<<","; 
    preorder(ptr->left);  
    preorder(ptr->right); 
}  

void tree::postorder(node* ptr) 
{ 
    if (ptr==NULL)
    {
        return;
    } 
    postorder(ptr->left);  
    postorder(ptr->right); 
    cout<<ptr->val<<","; 
} 

void tree::search(int val,node *ptr)
{
    if(val==ptr->val)
    {
        cout<<ptr->val<<" found"<<endl;
        return;
    }
    else if(val<ptr->val)
    {
        if(ptr->left==NULL)
        {
            cout<<"not found"<<endl;
            return;
        }
        else
        {
            search(val,ptr->left);
        }
    }
    else if(val>ptr->val)
    {
        if(ptr->right==NULL)
        {
            cout<<"not found"<<endl;
            return;
        }
        else
        {
            search(val,ptr->right);
        }
    }
    
}

node* tree::maximum(node *ptr)
{
    if(ptr->right==NULL)
    {
        return ptr;
    }
    else
    {
        maximum(ptr->right);
    }

}

node* tree::minimum(node *ptr)
{
    if(ptr->left==NULL)
    {
        
        return ptr;
    }
    else
    {
        minimum(ptr->left);
    }

}

node *tree::deletion(int val,node *ptr)
{
    if (ptr==NULL)
    {
        return ptr;
    }
    else if(val<ptr->val)
    {
        ptr->left=deletion(val,ptr->left);
    }
    else if(val>ptr->val)
    {
        ptr->right = deletion(val,ptr->right);
    }
    else
    {
        if(ptr->left==NULL && ptr->right==NULL)
        {
            delete ptr;
            ptr = NULL;
        }
        else if(ptr->left==NULL)
        {
            node *temp=ptr;
            ptr=ptr->right;
            delete temp;
        }
        else if(ptr->right==NULL)
        {
            node *temp=ptr;
            ptr=ptr->left;
            delete temp;
        }
        else
        {
            node *temp=minimum(ptr->right);
            ptr->val=temp->val;
            ptr->right=deletion(temp->val,ptr->right);
        }
    }
    return ptr;
}


node *tree::successor(int val, node *ptr)
{
    if (ptr==NULL)
    {
        return NULL;
    }
    else if(ptr->val==val)
    {
        node *temp = minimum(ptr->right);
        return temp;
    }
    else if(val>ptr->val)
    {
        successor(val,ptr->right);
    }
    else if(val<ptr->val)
    {
        successor(val,ptr->left);
    }
}

node *tree::predecessor(int val, node *ptr)
{
    if (ptr==NULL)
    {
        return NULL;
    }
    else if(ptr->val==val)
    {
        node *temp = maximum(ptr->left);
        return temp;
    }
    else if (val>ptr->val)
    {
        predecessor(val,ptr->right);
    }
    else if (val<ptr->val)
    {
        predecessor(val,ptr->left);
    }
}

void tree::print(node *ptr)
{
    if (ptr==NULL)
    {
        return;
    } 
    inorder(ptr->left); 
    cout<< ptr->val<<","; 
    inorder(ptr->right); 
}

int tree::getlevel(node *ptr,int val,int level)
{
    if(ptr==NULL)
        return 0;
    if(ptr->val==val)
        return level;
    return getlevel(ptr->left,val,level+1) | getlevel(ptr->right,val,level+1);
}

int main()
{
    tree t;
    t.insertion(6,t.root);
    t.insertion(3,t.root);
    t.insertion(5,t.root);
    t.insertion(7,t.root);
    t.insertion(2,t.root);
    t.insertion(9,t.root);
    t.insertion(8,t.root);
    t.insertion(1,t.root);
    t.insertion(4,t.root);

    t.inorder(t.root);
    cout<<endl;
    int x=0;
    x=t.getlevel(t.root,9,0);
    //cout<<x<<endl;
    // cout<<endl;
    // t.preorder(t.root); 
    // cout<<endl;
    // t.postorder(t.root); 
    // cout<<endl;

    //t.search(6,t.root);
     
    //t.deletion(9,t.root);

    // node *test=t.maximum(t.root);
    // cout<<"max val is "<<test->val<<endl;
    // test=t.minimum(t.root);
    // cout<<"min val is "<<test->val<<endl;

    // t.print(t.root);
    // cout<<endl;

    // test=t.successor(6,t.root);
    // cout<<test->val<<endl;
    //test=t.predecessor(6,t.root);
    node *temp=t.successor(6,t.root);
    cout<<temp->val<<endl;
    //t.deletion(9,t.root);

    // cout<<t.root->right->right->val;
}