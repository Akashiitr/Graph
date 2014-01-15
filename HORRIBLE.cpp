#include<iostream>
#include<cstdio>

using namespace std;

long long *tree;

void update(int idx ,int val,int MaxVal){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

long long read(int idx){
	long long sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

long long ans(int p, int q)
{
    return read(q)-read(p-1);
}

int main()
{
    //cout << (13&(-13))<<endl;
    int t;
    scanf("%d",&t);
    while(t--){
        int n,c;
        scanf("%d%d",&n,&c);
        tree = new long long[n+1];
        for(int i = 0; i <= n; i++)tree[i] = 0;
        while(c--){
            int moa, p, q, v = 0;
            scanf("%d",&moa);
            if(moa == 0)scanf("%d%d%d",&p,&q,&v);
            else scanf("%d%d",&p,&q);

            update(p,q,n);
            if(moa == 1)cout << read(p) << endl;
        }
    }
}
