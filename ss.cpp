#include<iostream>
#include<cstdio>

using namespace std;

int RMQ[1000001][1000001];

void rmq(long long a[], int n)
{
    for(int i = 1; i <= n; i++)RMQ[i][i] = i;
    //for(int l = 2; l <= n; l = (1 << l) )
}

int main()
{
    //cout <<;
    int n;
    scanf("%d",&n);
    while(n)
    {
        long long a[n+1];
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld",&a[i]);
        }
    }
}
