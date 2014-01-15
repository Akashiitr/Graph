#include<iostream>
#include<cstdio>

using namespace std;

int tree[101] = {0}, MaxVal;
void update(int idx ,int val){
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

int main()
{
    for(int i = 1; i <= 100; i++)tree[i] = 0;
    MaxVal = 100;
    update(5,1);
}
