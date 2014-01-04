#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string s;
        cin >> s;
        //int a = s.find("101");
        //int b = s.find("010");
        int l = s.length();
        int flag1 = 0, flag2 = 0;
        for(int i=0; i <= l-3; i++)
        {
            if(s[i]=='1' && s[i+1]=='0' && s[i+2]=='1')flag1 = 1;
            if(s[i]=='0' && s[i+1]=='1' && s[i+2]=='0')flag2 = 1;
        }
        if(flag1 == 1 || flag2 == 1)printf("Good\n");
        else printf("Bad\n");
    }
}
