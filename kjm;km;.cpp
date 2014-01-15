#include<iostream>
#include<cstdio>
using namespace std;
void quickSort(int arr[], int index[], int left, int right)
{
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      while (i <= j)
      {
            while (arr[i] < pivot)i++;
            while (arr[j] > pivot)j--;
            if (i <= j)
            {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  swap(index[i],index[j]);
                  i++;
                  j--;
            }
      };
      if (left < j)quickSort(arr, index, left, j);
      if (i < right)quickSort(arr, index, i, right);
}
inline long long next_int()
{
        long long n = 0;
        char c = getchar_unlocked();
        while (!('0' <= c && c <= '9'))
        {
                c = getchar_unlocked();
        }
        while ('0' <= c && c <= '9')
        {
                n = (n<<3)+(n<<1) + c - '0';
                c = getchar_unlocked();
        }
        return n;
}
int main()
{
    int n;
    //scanf("%d",&n);
    n = next_int();
    while(n)
    {
        int a[n],ix[n],check[n];
        for(int i = 0; i < n; i++)
        {
            //scanf("%d",&a[i]);
            a[i] = next_int();
            //ac[i]=a[i];
            ix[i]=i;
            check[i]=0;
        }

        quickSort(a,ix,0,n-1);

        long long low, high, ans = 0, temp;
        long long x=0;
        for(int i=0;i<n;i++)
        {
            check[(ix[i])] = 1;
            low = ix[i]-1;
            high = ix[i]+1;
            while(check[low] == 0 && low >= 0)low--;
            while(check[high] == 0 && high <= n-1)high++;
            x=x+high-low-1;
            temp = (high-low-1)*a[i];
            ans = max(ans,temp);
        }
        //cout<<x<<endl;
        printf("%lld\n",ans);
        //scanf("%d",&n);
        n = next_int();
    }
}

