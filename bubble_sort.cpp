#include<bits/stdc++.h>

using namespace std;

void bubble_sort(long long *begin, long long *end){
	for(long long *i = begin; i < end; i++)
		for(long long *j = begin; j < end; j++)
			if(*j > *(j+1)) swap(*j, *(j+1));
}

int main(){
	int n; cin>>n;
	long long a[n];
	for(int i = 0; i<n;i++) cin>>a[i];
	bubble_sort(a, a+n);
	for(int i = 0; i<n; i++) cout<<a[i]<<" ";
	return 0;
}
