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
	free(temp);
}


int isEmpty() 
{ 
    return top == NULL; 
} 

int peek() 
{ 
    // check for empty stack 
    if (!isEmpty()) 
        return top->data; 
     
}

bool isnumeric(char c)
{
    if(c>=0 && c<=9) return true ;
    else 
         return false;
}

bool isoperator(char c)
{
if(c=='+'|| c=='-'||c=='*'||c=='/')
    return true;
else 
    return false;

}

int perform(char o,int op2,int op1)
{
if(o=='+')
    return op2+op1;
else if(o=='-')
    return op2-op1;
else if(o=='/')
    return op2/op1;
else if(o=='*')
    return op2*op1;
else 
      return(1);}




void Evaluate(string s)
{ int l=s.length();
    int num=0;
    int result;
    for(int i=0;i<l;i++)
    {  if(s[i]==' '||s[i]==',')
           continue;
       else if(isoperator(s[i]))
       {   int op2=peek();
             pop();
            int op1=peek();
            pop();
          result=perform(s[i],op2,op1);
             push(result); } 
        else if(isnumeric(s[i]))
        {   //int num=0;
            while(i<l && isnumeric(s[i]))
                {num= (num*10)+(s[i]);
                    i++;}
             i--;} 
         push(num); }
   // k=peek();
    //cout<<k; 

}            


int main()
{ //cout<<"jeeu"<<endl;
    string  s;
    cin>>s;
    int k;
    //cout<<"sdje";
    //cout<<peek()<<endl;
    Evaluate(s);
    //cout<<"dhscxu";
    k=peek();
    cout<<k; 
}
                



    
   

