#include<bits/stdc++.h>
using namespace std;
struct Node{

  int data;
  struct Node *next;
};
struct Node *start=NULL;


void swap(int k)
{int count =0;
  struct Node* p=start;
  while(p->next!=NULL)
    {    p=p->next;
         count++; }
int n=count;

if(n<k)
   return;
   
if (2*k - 1 == n) 
    return;
    
    
      struct Node* x;
    struct Node* x_prev=NULL;
    x=start;

    for(int i=1;i<k;i++)
      {   x_prev=x;
           x=x->next; }
           
           struct Node* y=start;
           struct Node* y_prev=NULL;
           
   for(int j=1;j<(n-k+1);j++)
       {     y_prev=y;
             y=y->next; } 


    if(x_prev)
      {x_prev->next=y;} 

     if(y_prev)
       {   y_prev->next=x;}

      Node* temp=x->next;
      x->next=y->next;
      y->next=temp;

      if(k==1)
      {start=y;}
      if(k==n)
      {start=x;}                  
 }

 void insert(int y)
 {   Node *temp=new Node();
     temp->data=y;
     temp->next=start;
     start=temp;
}

void print()
{  Node* p;

     p=start;
     while(p!=NULL)
            {cout<<p->data;
                p=p->next;}   }


int main() 
{ 
    
    
    for (int i = 8; i >= 1; i--) 
       insert(i); 
  
    cout << "Original Linked List: "; 
    print(); 
  
    for (int k = 1; k < 9; k++) 
    { 
        swap( k); 
        cout << "\nModified List for k = " << k << endl; 
        print(); 
    } 
  
    return 0; 
}             

