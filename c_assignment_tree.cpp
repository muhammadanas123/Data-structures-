#include <iostream>
using namespace std;

class node
{
    public:
        int val;
        node *left;
        node *right;
        node *parent;

        node(int val,node *ptr)
        {
            this->val=val;
            left=NULL;
            right=NULL;
            parent=ptr;
        }

};


























class node1
{
    public:
        int val;
        node1 *next;

        node1(int val)
        {
            this->val=val;
            next=NULL;
        }
};

class stack
{
    node1 *top;
    node1 *head;
    int len;
    node1 *stack_values;
    int checker;
    public:
        stack();
        ~stack();
        bool is_empty();
        void push(int val);
        int pop();
        

        void value_checker();
};


stack::stack()
{
    top=NULL;
    head=NULL;
    stack_values=NULL;
    checker=0;
    len=0;
}

stack::~stack()
{
    top=NULL;
    head=NULL;
    stack_values=NULL;
    checker=0;
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
            
            node1 *n=new node1(val);
            head=n;
            top=head;
            stack_values=head;
            len++;
            return;

        }
        node1 *n=new node1(val);
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
            node1 *temp=head;
            node1 *temp1=NULL;
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




void stack::value_checker()
{
    if(stack::stack_values->next==NULL)
    {
        if(top->val==stack_values->val)
        {
            checker++;
            stack_values=head;
            cout<<"the value ("<<top->val<<") is "<<checker<<" time occurs in tree"<<endl;
            return;
        }
        else
        {
            stack_values=head;
            return;

        }
    
    }
    else
    {
        if(top->val==stack_values->val)
        {
            checker++;
            stack_values=stack_values->next;
            stack::value_checker();

            checker=0;
            //cout<<"the value ("<<top->val<<") is "<<checker<<" time occurs in tree"<<endl;
        }
        else
        {
            stack_values=stack_values->next;
            stack::value_checker();
            checker=0;

            
        }
    }

    

}



















struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}

void printTree(node *root, Trunk *prev, bool isRight)
{
    if (root == NULL)
        return;
    
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->val << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}




class tree
{
    
    public:
        node* root;
        stack s;
        tree();
        void insertion(int val,node *ptr);
        void deletion(int val,node *ptr);
        node* search(int val,node *ptr);
};

tree::tree()
{
    root=NULL;
    
}

node* tree::search(int val,node *ptr)
{
    if(val==ptr->val)
    {
        return ptr;
    }
    else if(val<ptr->val)
    {
        search(val,ptr->left);
    }
    else if(val>ptr->val)
    {
        search(val,ptr->right);
    }
    else
    {
        return NULL;
    }
}

void tree::insertion(int val, node *ptr=NULL)
{
    if(root==NULL)
    {
        node *n=new node(val,NULL);
        s.push(n->val);
        root=n;
    }
    else if(val<ptr->val)
    {
        if(ptr->left==NULL)
        {
            node *n=new node(val,ptr);
            s.push(n->val);
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
            node *n=new node(val,ptr);
            s.push(n->val);
            ptr->right=n;
        }
        else
        {
            ptr=ptr->right;
            insertion(val,ptr);
        }
    }
    else
    {
        s.push(val);
        //cout<<"This number ("<<val<<") is already in this tree (:"<<endl;
        s.value_checker();
    }
}

void tree::deletion(int val,node *ptr)
{
    node *temp=tree::search(val,ptr);

    if(temp==NULL)
    {
        cout<<"number ("<<val<<") not exist"<<endl;
    }
    else if(temp->left==NULL && temp->right==NULL)
    {
        temp=NULL;
        delete temp;
    }
    else if(temp->right==NULL)
    {
        temp->parent->left=temp->left;
        temp=NULL;
        delete temp;
    }
    else if(temp->left==NULL)
    {
        temp->parent->right=temp->right;
        temp=NULL;
        delete temp;
    }
    else if(temp->left!=NULL && temp->right!=NULL)
    {
        if(val<tree::root->val)
        {
            node *temp1=temp;
            temp1=temp1->left;
            if(temp1->right==NULL)
            {
                temp1->right=temp1->parent->right;
                temp->parent->left=temp->left;
                temp=NULL;
                delete temp;
            }
            else
            {
                while(temp1->right!=NULL)
                {
                    temp1=temp1->right;
                }
                temp->val=temp1->val;
                temp1=NULL;
                delete temp1;
            }
        }
        else
        {
            node *temp1=temp;
            temp1=temp1->right;
            if(temp1->left==NULL)
            {
                temp1->left=temp1->parent->left;
                temp->parent->right=temp->right;
                temp=NULL;
                delete temp;
            }
            else
            {
                while(temp1->left!=NULL)
                {
                    temp1=temp1->left;
                }
                temp->val=temp1->val;
                temp1=NULL;
                delete temp1;
            }
        }
        
    }
}



int main()
{
    tree t;
    t.insertion(6,t.root);
    t.insertion(3,t.root);
    t.insertion(5,t.root);
    t.insertion(7,t.root);
    t.insertion(7,t.root);
    t.insertion(2,t.root);
    t.insertion(9,t.root);
    t.insertion(7,t.root);
    t.insertion(8,t.root);
    t.insertion(1,t.root);
    t.insertion(4,t.root);
    t.insertion(4,t.root);
    t.insertion(1,t.root);
    t.insertion(1,t.root);
    
    printTree(t.root, NULL, false);
    
    t.deletion(3,t.root);

    printTree(t.root, NULL, false);
    
}