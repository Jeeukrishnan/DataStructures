#include<bits/stdc++.h>
using namespace std;
struct  Node
{int data;
	Node *next;
};
struct Node* start=NULL;
void insertend(int x){
   	Node* temp=new Node();
    struct Node* ptr=start;
    
    temp->data = x; 
    temp->next = NULL; 
  
    if (start == NULL) 
        start= temp; 
    else { 
        while (ptr->next != NULL) 
            ptr = ptr->next; 
        ptr->next = temp; 
    } 
}


    

void print()
{  Node* p;

     p=start;
     while(p!=NULL)
            {cout<<p->data;
                p=p->next;}  ;   }

void makezero()
{struct Node* prev=start;
	struct Node* curr=start->next;
	int temp=0;

if(prev->data==0 && curr->data!=0)
	{ curr->data=-1;  }
while(curr!=NULL)
{
if(temp==1 && curr->data!=0)
	{   curr->data=-1;
	    temp=0;}

if(curr->data==0)
{	 temp=1;
    prev->data= -1;
     }
curr=curr->next;
prev=prev->next;
}

curr=start;
while(curr!=NULL)
{

if(curr->data==-1)
	{     curr->data=0;}
curr=curr->next;
}
}

int main() 
{ 
     
     
    insert(3);
    insert(4);
    insert(0);
    insert(9);
    insert(8);
    makezero(); 
  
    print(); 
  
    return 0; 
} 

       
                      





