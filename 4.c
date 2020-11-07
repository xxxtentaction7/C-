#include<stdio.h>
	
int delete(int a[],int n,int x)
{int i,j,b=0,d;
  for(i=0;i<n-1;i++)
  {if(x==a[i])
  { for(j=i;j<n-1;j++)
   {a[j]=a[j+1];}
   
   b++;
  }}
  
  return b;

}
int main()
{
	int a[10],i,j,min,c,w,max;
	double b;
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	min=a[0];
	max=a[0];
	for(i=0;i<9;i++)
	{if(min<=a[i+1])
     min=a[i+1];  }
     c=delete(a,10,min);
     for(i=0;i<9-c;i++)
     {if(max>=a[i+1])
     max=a[i];
	 }
	 w=delete(a,10-c,max);
	 for(i=0;i<10-c-w;i++)
	 {
	 b+=a[i];}
	 b=b/(10-c-w);
	 printf("%lf",b); }
