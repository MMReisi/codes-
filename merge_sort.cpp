#include<bits/stdc++.h>

using namespace std;

void merge(long long *begin, long long *end){
	long long *p2 = begin+(end- begin)/2, *p1 = begin;
	long long *middle = p2;
	long long temp[int(end-begin)];
	for(int i = 0; i<int(end- begin); i++){
		if(p2 >= end) temp[i] = *p1, p1++;
		else if(p1 >= middle) temp[i] = *p2, p2++;
		else if(*p1 <= *p2) temp[i] = *p1, p1++;
		else if(*p2 <= *p1) temp[i] = *p2, p2++; 
	}
	int k = 0;
	for(long long *i = begin; i<end; i++){
		*i = temp[k];
		k++;
	} 
}

void merge_sort(long long *begin, long long *end){
	if(begin >= end-1) return;
	long long *middle = begin+(end-begin)/2;
	merge_sort(begin, middle);
	merge_sort(middle, end);
	merge(begin, end);	
}

int main(){
	int n; cin>>n;
	long long a[n]; for(int i = 0; i<n; i++) cin>>a[i];
	merge_sort(a, a+n);
	for(int i = 0; i<n; i++) cout<<a[i]<<" ";
	return 0;
}
