#include<iostream>
#include<cstdio>

using namespace std;

bool die_live(long long  l, long long  d, long long  s, long long  c)
{
    long long ans = s;
    c++;
    d--;
    while(d)
    {
        if(d % 2 == 1)ans = ans * c;
        if(c >= l)return 1;
        c = c *c;
        d = d/2;
        //cout << "fff" <<endl;
        //cout << ans << endl;
        if(ans >= l || c >= l)return 1;
    }
    //return ans;
    if(ans >= l)return 1;
    return 0;
}

int main()
{
    //cout << die_live(5,4,5,4);
    long long  t;
    scanf("%lld",&t);
    while(t--)
    {
        long long  L, D, S, C;
        scanf("%lld%lld%lld%lld",&L, &D, &S, &C);
        bool ans = die_live(L,D,S,C);
        if(ans)printf("ALIVE AND KICKING\n");
        else printf("DEAD AND ROTTING\n");
    }
}
