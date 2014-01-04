#include<iostream>
#include<cstdio>

using namespace std;

long long table[100002];
long long f[100002];
long long l[100002];

void quickSort(long long arr[], int left, int right) {
      int i = left, j = right;
      long long tmp;
      int pivot = arr[(left + right) / 2];
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  swap(f[i],f[j]);
                  swap(l[i],l[j]);
                  i++;
                  j--;
            }
      };
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

void QuickSort(long long arr[], int left, int right) {
      int i = left, j = right;
      long long tmp;
      int pivot = arr[(left + right) / 2];
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  swap(table[i],table[j]);
                  swap(l[i],l[j]);
                  i++;
                  j--;
            }
      };
      if (left < j)
            QuickSort(arr, left, j);
      if (i < right)
            QuickSort(arr, i, right);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n, k;
        scanf("%lld%lld",&n,&k);
        //long long f[n+1], l[n+1], table[n+1];
        //f = new long long[n+1];
        //table = new long long[n+1];
        //l = new long long[n+1];
        for(int i = 1;i <= n; i++)
        {
            scanf("%lld%lld%lld",&f[i], &l[i], &table[i]);
        }
        //cout << "fdsfdsf"<<endl;
        table[n+1] = -1;
        quickSort(table, 1, n);

        long long count = 0;
        for(int i = 1; i <= n;)
        {
            long long c1 = 0;
            long long temp = table[i];
            while(temp == table[c1+i]){c1++;}
            QuickSort(f, i, i+c1-1);

            //for (int i = 1; i <=n ;i++)cout << "initially " <<table[i]<<" "<< f[i] <<"  " <<l[i]<<endl;
            long long fans = f[i], lans = l[i];
            //cout <<"sadasd"<<endl;
            count++;
            for(int j = i+1; j <= i+c1-1; j++)
            {
                //cout << f[j] << " " << l[j]<<endl;
                if(f[j] >= lans)
                {
                    count++;
                    fans = f[j];
                    lans = l[j];
                    //cout << "f :  " << fans <<"   l : "<<lans <<endl;
                }
                else
                {
                    if(l[j] < lans)
                    {
                        fans = f[j];
                        lans = l[j];
                    }
                }
            }
            i = i + c1;
            //cout << i << endl;
        }
        printf("%lld\n",count);
    }
}

