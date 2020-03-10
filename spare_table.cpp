#include<bits/stdc++.h>

using namespace std;

const int MX = 1e5, maxh = 10;
int table[MX][maxh];

void pre(int a[], int n){
	for(int h = 1; h<maxh; h++)
		for(int i = 0; i<n; i++)
			table[i][h] = min(table[i][h-1],table[i+(1<<(h-1))][h-1]);
}

int query(int l, int r){
	int x = r-l;
	int ans = table[l][0];
	for(int i = maxh-1; i>=0; i--) if(x & (1<<i)) ans = min(ans, table[l][i]), l+=(1<<i);
	return ans;
}

int main(){
	int n; cin>>n;
	int a[n]; for(int i = 0; i<n; i++) cin>>a[i];
	for(int i = 0; i<n; i++) table[i][0] = a[i];
	pre(a, n);
	int q; cin>>q;
	while(q--){
		int l, r; cin>>l>>r;
		cout<<query(l, r)<<endl;
	}
	return 0;
}
