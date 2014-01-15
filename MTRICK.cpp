#include<iostream>
#include<cstdio>

using namespace std;

unsigned long long mul( unsigned long long a,  unsigned long long b, unsigned long long c)
{
     unsigned long long ans = 0;
    while(b)
    {
        if(b&1)
        ans = (ans + a)%c;
        b>>=1;
        a = (a+a)%c;
    }
    return ans;
}

 unsigned long long power( unsigned long long m,  unsigned long long mcount,  unsigned long long c)
{
     unsigned long long ans = 1;
    while(mcount)
    {
        if(mcount&1)ans = mul(ans,m,c);//((ans % c)*(m % c)) % c
        m = mul(m,m,c);//  ((m%c)*(m%c))%c;
        mcount>>=1;
    }
    return ans;
}

int main()
{
    //cout << power(2,10,1000);
    //cout<< mul(5,6,100000);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
         unsigned long long l[n];
        for(int i =0; i < n; i++)
        {
            scanf("%llu",&l[i]);
        }
         unsigned long long a, b, c;
        scanf("%llu%llu%llu",&a,&b,&c);
        string s;
        cin >> s;
        int rtemp = 0, ft = 0, lt = n-1;
         unsigned long long cop[n];
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'R')rtemp^1;
            if(!rtemp)
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
         unsigned long long acount = 0,mcount = 0,ans1 = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'A')
            {
                acount++;
                ans1 = ( ans1 + a )%c;
            }
            if(s[i] == 'M')
            {
                mcount++;
                ans1 = mul(ans1,b,c);// ( ans1 * b%c ) % c;
            }
            //cop[i] = ((cop[i] + (acount * (a % c) % c)) % c * (power(b, mcount, c)));
            cop[i] = ( mul(cop[i],power(b,mcount,c),c) + ans1 ) %c;
            //cop[i] =( ( (cop[i] % c) * power(b,mcount,c) ) % c + ans1 ) % c;
        }
        for(int i = 0; i < n; i++)
        printf("%llu ",cop[i]);
        printf("\n");

    }
}
