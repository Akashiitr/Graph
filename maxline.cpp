#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    int i = 1;
    while(t--)
    {
        int r;
        scanf("%d",&r);
        long long ans = 4 * r * r;
        //double ans1 = (double)ans + .25;
        printf("Case %d: %lld.25\n",i,ans);
        //cout << ans1 <<endl;
        i++;
    }
}
