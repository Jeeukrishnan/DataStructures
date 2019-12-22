#include<bits/stdc++.h>
using namespace std;
struct Node
{int data;
	Node *prev,*next; 

};
struct Node* start=NULL;
void insert(int x)
{ Node *temp=new Node();
	temp->data=x;
	temp->prev=NULL;
	temp->next=NULL;
	if(start==NULL)
		{start=temp;}
    else
    	 {start->prev=temp;
    	 	temp->next=start;
    	 	start=temp;}
}
void delete()
{
if(start==NULL)
	{ cout<<"list empty";}
else
	 {r=start;
	 	start=start->next;
	 	start->prev=NULL:
	 	free (r); 
	 }
}
void viewlist()
{
struct  Node* t;
if(start==NULL)
{cout<<"empty";}
t=start;
while(t!=NULL)
	{   cout<<t->data; 
	     t=t->next;  }



}