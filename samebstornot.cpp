#include<bits/stdc++.h>
using namespace std;
int isSamebst(int x[],int y[],int n)
{
if(n==0)
	return 1;
if(n==1)
	return 1;
int leftx[n-1],rightx[n-1],lefty[n-1],righty[n-1];
int k=0,l=0,m=0,b=0;
for(int i=1;i<n;i++)
{if(x[i]<x[0])
	{ leftx[k++]=x[i];}
 else 
      {rightx[l++]=x[i];}
  if(y[i]<y[0])
     {lefty[m++]=y[i];}
   else 
       {righty[b++]=y[i];}      	
}
if(k!=m)
{    return 0;}
if(l!=b)
{return 0;}
 
 return isSamebst(leftx,lefty,k) && isSamebst(righty,rightx,l);
}
int main(void)
{
	int X[] = { 15, 25, 20, 22, 30, 18, 10, 8, 9, 12, 6 };
	int Y[] = { 15, 10, 12, 8, 25, 30, 6, 20, 18, 9, 22 };

	int n = sizeof(X) / sizeof(X[0]);
	int m = sizeof(Y) / sizeof(Y[0]);

	if (m == n && isSamebst(X, Y, n))
		printf("Given keys represent same BSTs");
	else
		printf("Given keys represent different BSTs");

	return 0;
}
