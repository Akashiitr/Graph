#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        long long l[n];
        for(int i =0; i < n; i++)
        {
            scanf("%lld",&l[i]);
        }
        long long a, b, c;
        scanf("%lld%lld%lld",&a,&b,&c);
        string s;
        cin >> s;
        int rtemp = 0, ft = 0, lt = n-1;
        long long cop[n];
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'R')rtemp++;
            if(rtemp % 2 == 0)
            {
                cop[i] = l[ft]; ft++;
            }
            else
            {
                cop[i] = l[lt]; lt--;
            }
        }
        /*for(int i = 0; i < n; i++)
        {
            cout << cop[i] << "  ";
        }*/

    }

}
