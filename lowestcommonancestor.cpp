#include<bits/stdc++.h>
using namespace std;
struct node{
int key;
node* left;
node* right;
};
struct node* root=NULL;
struct node* createnode(int k)
{struct node* temp=new node();
temp->key=k;
temp->left=NULL;
temp->right=NULL;
return temp;}
struct node* insert(struct node* root,int k)
{if(root==NULL)
     {return createnode(k);} 
  else if(k<root->key)
        {root->left=insert(root->left,k);}
  else 
        {root->right=insert(root->right,k);}
   return  root; }
struct node* LCA(struct node* root, int k ,int j)
{struct node* curr=root;
while(root)
{if(curr->key>max(k,j))
    {curr=curr->left;}
 else if(curr->key<min(k,j))
 {curr=curr->right;}
 else 
       return curr; }}
 int main()
{
	//Node* root = nullptr;
		/* Construct below tree
              15
            /    \
           /      \
          10       20
         /  \     /  \
        /    \   /    \
       8     12 16    25
	*/

	int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

	for (int key : keys)
		root = insert(root, key);

	// lca stores lowest common ancestor of 8 and 12
	node* lca = LCA(root, 8, 12);

	// if lowest common ancestor exists, print it
	if (lca != nullptr)
		cout << "LCA is " << lca->key << endl;
	else
		cout << "LCA do not exist\n";

	return 0;
}         
