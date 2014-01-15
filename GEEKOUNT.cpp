#include<iostream>
#include<cstdio>

long long power(int a, int b)
{
    long long ans = 1;
    while(b)
    {
        if(b % 2 == 1)ans = ans * a;
        a = a*a;
        b = b/2;
    }
    return ans;
}

using namespace std;

int main()
{
    ////cout << power(5,3);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l,r;
        scanf("%d%d",&l,&r);

        int temp = (r - l + 1);
        ////cout <<"temp" << temp <<endl;
        int L[9],R[9];

        int ltemp = l, i = 0;
        while(ltemp)
        {
            //L[i] = ltemp % 10;
            i++;
            ltemp = ltemp/10;
        }
        ltemp = l;int lsize = i;
        while(ltemp)
        {
            L[lsize-1] = ltemp % 10;
            lsize--;
            ltemp = ltemp/10;
        }
        int rtemp = r, j = 0;
        while(rtemp)
        {
            //R[j] = rtemp % 10;
            j++;
            rtemp = rtemp/10;
        }
        rtemp = r;int rsize = j;int rf = 0;
        while(rtemp)
        {
            R[rsize -1] = rtemp % 10;
            if(R[rsize -1]%2==0)rf = 1;
            rsize--;
            rtemp = rtemp/10;
        }
        long long ans = 0;
        for(int a = i+1; a <= j-1; a++)
        {
            ans = ans + power(5,a);
        }
        int flag = 0;
        ////cout << "ans 1 :" << ans << endl;
        for(int a = 0; a <= i-1; a++)
        {
            if(L[a] % 2 == 0){
                ans = ans + ( (10 - L[a])/2 ) * power (5, i - a -1);flag = 1;
                break;
            }
            else{
                ans = ans + ( (9 - L[a])/2 ) * power(5, i - a -1);
            }

        }
        ////cout << ans << endl;
        if(flag == 0)ans++;int x;
        long long lans = ans;
        ////cout << "lans  :  "<< flag << endl;
        flag = 0;
        for(int a = 0; a <= j-1; a++)
        {
            if(R[a] % 2 == 0){
                x = ( (R[a])/2 );
                ////cout << "x  " << x <<" "<<R[a]<<" "<< j<< endl;
                ans = ans + ( x ) * power (5, j - a -1);flag = 1;
                // * power (5, j - a -1);
                break;
            }
            else{
                ans = ans + ( (R[a])/2 ) * power(5, j - a -1);
            }

        }
        ////cout << "x  " << x <<" "<<R[1]<<" "<< j<< endl;
        if(flag == 0)ans++;
        //cout << "rans  :  "<< ans << endl;
        ans = temp - ans;
        if(i != j)
        cout<<ans <<endl;
        else
        {
            long long rans = 0;flag = 0;
            for(int a = 0; a <= i-1; a++)
            {
                if(R[a] % 2 == 0){
                    rans = rans + ( (10 - R[a])/2 ) * power (5, i - a -1);flag = 1;
                    break;
                }
                else{
                    rans = rans + ( (9 - R[a])/2 ) * power(5, i - a -1);
                }
            }
            if(flag == 0)rans++;
            ans = lans - rans;
            if(rf == 1);
            else ans++;
            ans = temp - ans;
            cout <<ans << endl;
        }
    }
}
