#include<bits/stdc++.h>

using namespace std;

const int MX = 1e6;
int sz[MX], par[MX];

void make(int n){
	for(int i = 1; i<=n; i++) par[i]=i , sz[i] = 1;
}

int find(int u){
	return par[u] = par[u] == u ? u : find(par[u]);
}

void uni(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	par[b] = a;
}

bool check(int a, int b){
	return find(a) == find(b);
}

int main(){
	int n, m; cin>>n>>m;
	make(n);
	priority_queue<array<int, 3>,vector<array<int, 3>> ,greater<array<int , 3>>> adj;

	for(int i = 0; i<m; i++){
		int u, v, w; cin>>u>>v>>w;
		adj.push({w, u, v});
	}

	vector<array<int, 3>> ans;
	int e = 0;
	while(adj.size()){
		auto x = adj.top();
		adj.pop();
		if(check(x[1], x[2])) continue;
		uni(x[1], x[2]);
		ans.push_back(x);
		e++;
		if(e == n-1) break;
	}
	for(auto x: ans){
		cout<<x[1]<<" "<<x[2]<<" "<<x[0]<<endl;
	}
	return 0;
}
