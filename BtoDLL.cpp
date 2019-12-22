#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* right;
    node* left;
    //node* next;
    //node* prev=NULL;
};
struct node* root=NULL;
struct node* p=NULL;
struct node* createnode(int k)
{ struct node* temp=new node();
          temp->data=k;
          temp->right=NULL;
          temp->left=NULL;
          return temp;}
 struct node* insert(struct node* root, int k)
 {     if(root==NULL)
          {  return createnode(k);}
       if(k<root->data)
           {root->left=insert(root->left ,k);} 
        if(k>root->data)   
        {root->right=insert(root->right,k);}

        return root;}  
void convert(struct node* root,struct node* p)
{if(root==NULL)
    return ;

 static node* prev=NULL;cout<<"y";


 convert(root->left ,p);
 
 if(prev==NULL)
 {  p=root;}
 else 
    {root->left=prev;
     prev->right=root;}
    prev=root; 
  
  
  convert(root->right,p); 

 //return p; 
} 
void inorder(struct node* p)
{    //cout<<"u";
    if(p==NULL)
        return ;
    inorder(p->left);
    cout<<p->data<<" ";
    inorder(p->right);  
}
      
int main()
{  //cout<<"k";
     root=insert(root,5);
    root=insert(root,6);
     root=insert(root,7);
      root=insert(root,8);
      root=insert(root,9);
       root=insert(root,2);
       root=insert(root,3);
       //cout<<"me";
       //inorder(root);
       //struct node* k;
        convert(root,p);
       //cout<<"jeeu";
       inorder(p);
}
