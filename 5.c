#include<stdio.h>
#include<math.h>
int main()
{int n,k,i,j,t,z,x;
printf(" ‰»Î∑∂Œß:");
scanf("%d%d",&i,&j);
z=0;
for(n=i;n<=j;n++)
{
	k=(int)sqrt(n*1.0);
	x=1;
    for(t=2;t<=k;t++)
{
	if(n%t==0)
	{x=0;
    break;} 
}
	if(x==1)
	{printf("%d ",n);
    z++;
	if(z%5==0)
		printf("\n");
	}
}
return 0;
}
