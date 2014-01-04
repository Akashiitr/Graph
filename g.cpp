#include <cstdio>
#include <cmath>
#include<iostream>
#include <cstdlib>

int main()
{
	int t,i;
	long int *r;
	long double result;
	scanf("%d",&t);
	r=malloc(t*sizeof(long int));
	for(i=0;i<t;i++)
	{
		scanf("%ld",(r+i));
	}
	for(i=0;i<t;i++)
	{
		result=(float)4*(*(r+i))-(float)1/4/(*(r+i))/(*(r+i))/(*(r+i))+(float)1/2/(*(r+i));
		result=result*(*(r+i));
		printf("Case %d: %0.2Lf\n",i+1,result);
	}
	free(r);
	return 0;
}
