#include<bits/stdc++.h>

using namespace std;
void selection_sort(long long *begin, long long *end){
	for(long long *i = begin; i<end; i++)
		for(long long *j = i+1; j<end; j++)
			if(*j < *i) swap(*j, *i); 
}

int main(){
	int n; cin>>n;
	long long a[n]; for(int i = 0; i<n;i++) cin>>a[i];
	selection_sort(a, a+n);
	for(int i = 0; i<n; i++) cout<<a[i]<<" ";
	return 0;
}
