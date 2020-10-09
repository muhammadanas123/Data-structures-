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
        static int index;
        tree();
        void insertion(int val,node *ptr);
        void inorder(node* ptr,int *arr); 
        void L_O_Traversal(node* root);
        bool printlevel(node* root, int level);



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

void tree::inorder(node* ptr,int *arr) 
{ 
    if (ptr==NULL)
    {
        return ;
    } 
    inorder(ptr->left,arr); 
    //cout<< ptr->val<<",";
    *(arr+index)=ptr->val;
    index++;
     
    inorder(ptr->right,arr); 

} 
int tree::index=0;

bool tree::printlevel(node* root, int level)
{
    if (root==NULL)
        return false;

    if (level==1)
    {
        cout<<root->val<<",";
        return true;
    }
    bool left = printlevel(root->left,level-1);
    bool right = printlevel(root->right,level-1);

    return left || right;
}


void tree::L_O_Traversal(node* root)
{
    int level=1;

    while (printlevel(root, level))
        level++;
}


int main()
{
    tree t;
    int arr[9]= {6,3,5,7,2,9,8,1,4};
    int *arr1=arr;
    for(int i=0; i<9; i++)
        t.insertion(arr[i],t.root);

    t.inorder(t.root,arr1);

    cout<<endl;
    for(int i=0; i<9; i++)
        cout<<arr[i]<<",";
    cout<<endl;


    t.L_O_Traversal(t.root);


}
