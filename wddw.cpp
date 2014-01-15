#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
    if(a==0)return b;
    return gcd(b%a,a);
}
int main()
{
    //cout<<gcd(18,24);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,temp;
        scanf("%d%d",&a,&b);
        if((a<0&&b<0))
        {
            a*=-1;
            b*=-1;
        }
        /*
        if(a>0&&b>0)
        {

        }*/
        if(a>b)temp=a-b;
        else temp=b-a;
        int x=0,y=1,count=0;
        while(y)
        {
            y=(x+a%temp)%temp;
            count++;
            x=y;
        }
        printf("%d\n",count);
    }
}
