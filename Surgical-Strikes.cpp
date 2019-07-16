#include <iostream>
#include<cmath>
using namespace std;

int primefactor(int num) 
{
		int factors[10];
	int k=0,n=num;
	for(int i=2;i<=n/2;i++)
	{
		while(num%i==0)
		{
			num=num/i;
			factors[k++]=i;
		}
	}
	if(k==0)
	{
		factors[k++]=n;
	}
	int max=factors[0];
	for(int i=1;i<=k;i++)
	{
		if(max<=factors[i])
		{
			max=factors[i];
		}
	}
	return max;
}



int main() 
{
	int N,M,T,i,j;
	int x[100],y[100],basex,basey,ID[100],x1[100],y1[100],ID1[100];
	cin>>N>>M>>T;
	for(i=0;i<N;i++)
	{
		cin>>x[i]>>y[i]>>ID[i];
	}
	for(i=0;i<M;i++)
	{
		cin>>x1[i]>>y1[i]>>ID1[i];
	}
	cin>>basex>>basey;
   int visited[M];
	for(i=0;i<M;i++)
	{
		visited[i]=0;
	}
	int count1=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
		    int e,f;
			if(visited[j]==0)
			{
			 int a,b,c,d;
			  a=abs((x[i]-x1[j])+(y[i]-y1[j]));
			 b=abs((x[j]-basex)+(y[j]-basey));
			 c=primefactor(a);
			 d=primefactor(b);
			  if(ID[i]>c)
			 {
			 	e=ID[i];
			 }
			 else
			 {
			   e=c;
			 }
			 if(ID1[j]>d)
			 {
			 	f=ID1[j];
			 }
			 else
			 {
			 	f=d;
			 }
			 if(e+f<T)
			 {
			 	visited[j]=1;
			 	count1++;
			 	break;
			 }
		   }
		}
	}
	cout<<count1;
	return 0;
}
