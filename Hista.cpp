#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

long long a[100001];
int M[100001][20];
long long max1(long long a,long long b)
{if(a>b)return a;
return b;}

void range(int n)
{
    int i, j;

  //initialize M for the intervals with length 1
      for (i = 1; i <= n; i++)
          M[i][0] = i;
  //compute values from smaller to bigger intervals
      for (j = 1; (1 << j) <= n; j++){
          for (i = 1; i + (1 << j) - 1 <=n ; i++){
              if (a[M[i][j - 1]] < a[M[i + (1 << (j - 1))][j - 1]])
                  M[i][j] = M[i][j - 1];
              else
                  M[i][j] = M[i + (1 << (j - 1))][j - 1];
            }
      }
}

int rmq(int i, int j)
{
    int size1 = (j-i+1),count1 = 0, ans=i;
    long long temp = 1000000000l;
    temp*=temp;
    while(size1)
    {
        if(size1 % 2 == 1){
            if(a[M[i][count1]] <  temp){
                    temp = a[M[i][count1]];
                    ans = M[i][count1];
            }
            i=i+(1<<count1);
        }
        count1++;
        size1 = size1/2;
    }
    return ans;
}

long long l_area(int i, int j){
    if(i>j)return 0;
    if(j - i == 0)return a[i];
    long long ans, temp1, temp2;
    int size1 = (j-i+1);int q = rmq(i,j);
    ans = size1 * a[q];
    temp1 = l_area(i, q-1);
    temp2 = l_area(q+1, j);
    if(ans >= temp1 && ans >= temp2)return ans;
    else if(temp1 >= ans && temp1 >= temp2)return temp1;
    else return temp2;
}

int main()
{
    //cout << power(2,1);
    int n;
    scanf("%d",&n);
    while(n)
    {
        //long long a[n+1];
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld",&a[i]);
        }
        range(n);
        //int i,j;
        //while(1){cin>>i>>j;cout << rmq(i,j)<<endl;;}
        //cout << l_area(1,n) << endl;
        long long ans = l_area(1,n);
        printf("%lld\n",ans);

        scanf("%d",&n);

    }

}
