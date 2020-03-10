#include<bits/stdc++.h>

using namespace std;

const int MX = 1e5;
set<array<int ,3>> adj, ans;
int par[MX], sz[MX];

void make(int n){
	for(int i = 1; i<=n;i++) par[i] = i, sz[i] = 1;
}

int find(int u){
	if(par[u] == u) return u;
	return par[u] = find(par[u]);
}

void uni(int u, int v){
	u = find(u), v = find(v);
	if(u == v) return;
	if(sz[u] < sz[v]) swap(u, v);
	sz[u] += sz[v];
	par[v] = u;
}

bool check(int u, int v){
	return find(u) == find(v);
}

int main(){
	int n, m; cin>>n>>m;
	make(n);
	for(int i = 0; i<m; i++){
		int u, v, w; cin>>u>>v>>w;
		adj.insert({w, u, v});
	}
	while(adj.size()){
		auto e = *(adj.begin());
		adj.erase(adj.begin());
		if(check(e[1], e[2])) continue;
		if(ans.size() == n-1) break;
		uni(e[1], e[2]);
		ans.insert(e);
	}
	for(auto x: ans){
		cout<<x[1]<<" "<<x[2]<<" "<<x[0]<<endl;
	}
	return 0;
}
