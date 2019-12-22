#include<bits/stdc++.h>
using namespace std;
struct tree{
int h;
int data;
struct tree* right=NULL;
struct tree* left=NULL;
};
tree *root=NULL;

int height(tree* root)
{ int l,r;
if(root==NULL)
return 0;
else
{
    l=height(root->left);
    r=height(root->right);
} 
return max(l,r)+1;
}

tree* newnode(int k)
{ struct tree *temp=new tree();
   temp->data=k;
   temp->right=NULL;
   temp->left=NULL;
   temp->h=0;
   return temp; 
}

tree* srotationright(tree *z)
{  tree *y=z->right;
    tree *temp= y->left;
    y->left=z;
    z->right=temp;
    z->h=max(height(z->right),height(z->left))+1;
    y->h=max(height(y->left),z->h)+1;
    return y;}

tree* srotationleft(tree* z)
{ tree *y=z->left;
tree *temp=y->right;
y->right=z;
z->left=temp;
z->h=max(height(z->right),height(z->left))+1;
y->h=max(height(y->right),z->h)+1;
return y;}

tree* drotationleft(tree* z)
{  z->left=srotationright(z->left);
return srotationleft(z);
}

tree* drotation(tree* z)
{ z->right=srotationleft(z->right);
 return srotationright(z);
}

int getBalance(tree *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  

tree* insert(tree* node, int key)  
{  
    /* 1. Perform the normal BST insertion */
    if (node == NULL)  
        return(newnode(key));  
  
    if (key < node->data)  
        node->left = insert(node->left, key);  
    else if (key > node->data)  
        node->right = insert(node->right, key);  
    else // Equal keys are not allowed in BST  
        return node;  
  
    /* 2. Update height of this ancestor node */
    node->h = 1 + max(height(node->left),  
                        height(node->right));  
  
    /* 3. Get the balance factor of this ancestor  
        node to check whether this node became  
        unbalanced */
    int balance = getBalance(node);  
  
    // If this node becomes unbalanced, then  
    // there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 && key < node->left->data)  
        return srotationleft(node);  
  
    // Right Right Case  
    if (balance < -1 && key > node->right->data)  
        return srotationright(node);  
  
    // Left Right Case  
    if (balance > 1 && key > node->left->data)  
    {  
        //node->left = leftRotate(node->left);  
        return drotationleft(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && key < node->right->data)  
    {  
        //node->right = rightRotate(node->right);  
        return drotation(node);  
    }  
  
    /* return the (unchanged) node pointer */
    return node;  
}  
void preorder(tree* root)
{
  if(root)
  {
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
  }
}

int main()  
{  
    //Node *root = NULL;  
      
    /* Constructing tree given in  
    the above figure */
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);  
      
    /* The constructed AVL Tree would be  
                30  
            / \  
            20 40  
            / \ \  
        10 25 50  
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    preorder(root);  
      
    return 0;  
}  
   















