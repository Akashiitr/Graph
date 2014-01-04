#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

double primes [] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

long long power(long long x, int y)
{
    if( y == 0)
        return 1;
    else if (y%2 == 0)
        return power(x, y/2)*power(x, y/2);
    else
        return x*power(x, y/2)*power(x, y/2);

}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		double k;
		int flag =0;int m;
		for(int i=0;i<16;i++)
		{
            k = 1.0/(primes[i]);
			k = pow(n,k);
			m=primes[i];
            //cout<<k<<endl;
            k = int(k);
			long long x = power(k-1,m);
			x-=n;
			//cout<<x<<endl;
			long long y = power(k,m);
			y-=n;
			//cout<<y<<endl;
			long long z = power(k+1,m);
			z-=n;
			//cout<<z<<endl;
			if((x==0)||(y==0)||(z==0))
			{flag = 1;
			break;}

		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
}
