#include<bits/stdc++.h>
using namespace std;
struct node{
   char data;
   struct node* next;

};
struct node* top=NULL;
void push(char c)
{struct node* temp=new node();
	temp->data=c;
	temp->next=top;
     top=temp;
}
void pop()
{
    struct node* temp=new node();
	if(top==NULL) return;
	temp=top;
	top=top->next;
	free(temp);}
int isEmpty() 
{ 
    if( top == NULL)
       return 1;
     else 
         return -1;   
} 


int peek() 
{ 
    // check for empty stack 
    if (!isEmpty()) 
        return top->data; 
    else
        exit(1); 
} 
void check(string s)
{    int l=s.length();
    for(int i=0;i<l;i++)
    {  if(s[i]=='('||s[i]=='{'||s[i]=='[')
          {push(s[i]);
              continue ;}
       else if(s[i]==')')
            {  char z=peek();
                if(z=='(')
                   {
                    
                   pop();}            
              else
                   {push(s[i]);} 
                  }  
         else if(s[i]=='}')
            { char y=peek();
             if(y=='{')
                  
                   {pop(); }           
              else
                   {push(s[i]);} 
                  }
          else if(s[i]==']')
            {   char x=peek();
                if(x=='[')
                  { pop(); }           
              else
                   {push(s[i]);}
                  } 
         if(isEmpty())
    {   cout<<"valid";
       }                                 
}

//if(isEmpty())
    //{   cout<<"empty";}

   cout<<"not valid";
   

}
int main()
{string s;
    cin>>s;
 check(s);   
}