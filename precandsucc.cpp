#include<bits/stdc++.h>
using namespace std;
struct node
{int key;
	node* left;
	node* right;
};
struct node* root=NULL;
struct node* succ=NULL;
struct node* prec=NULL;
struct node* createnode(int k)
{struct node* temp=new node();
temp->key=k;
temp->left=NULL;
temp->right=NULL;
return temp;}
struct node* insert(struct node* root,int k)
{if(root==NULL)
	{    return createnode(k);}
else if(k<root->key)
{root->left=insert(root->left,k);}
else 
    {root->right=insert(root->right,k);}
  return root;  	
}
void precsucc(struct node* root, int k)
{ struct node* temp;
	if(root==NULL)
	{return ;}
  if(root->key==k)
  {if(root->right!=NULL)
       {temp=root->right;
           while(temp->left)
               {temp=temp->left;}
           succ=temp;}
 if(root->left!=NULL)
 {temp=root->left;
     while(temp->right)
            {temp=temp->right;}
        prec=temp;}    
}

if(k<root->key)
    {succ=root;
      precsucc(root->left,k);}
else 
    {prec=root;
       precsucc(root->right,k);}
 }            
 int main() 
{ 
    int key = 65;    
    //Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 63); 
    insert(root, 80); 
  
  
    //Node* pre = NULL, *suc = NULL; 
  
    precsucc(root,key); 
    if (prec != NULL) 
      cout << "Predecessor is " << prec->key << endl; 
    else
      cout << "No Predecessor"; 
  
    if (succ != NULL) 
      cout << "Successor is " << succ->key; 
    else
      cout << "No Successor"; 
    return 0; 
} 