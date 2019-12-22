#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
Node *next;};
struct Node* start=NULL;
void insert(int x)
{     Node* newnode=new Node();
         newnode->data=x;
          newnode->next=start;
          start=newnode;
          }
 void print()
{  Node* p;

     p=start;
     while(p!=NULL)
            {cout<<p->data;
                p=p->next;}   }         

 int detect()
 { Node *slow=start;
 	Node *fast=start;
 while(slow && fast && fast->next)
 {  slow=slow->next;
 	fast=fast->next->next;
 	
 	if(slow==fast){

 		cout<<"found";
 		return 1;
 	}
}
 return 0;	
} 

 int main()
 {

 	insert(20);
 	insert(2);
    insert(27);
    insert(15);
    //print();
    start->next->next->next->next=start;
    detect();
}  



 