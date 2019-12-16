#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pb push_back
#define MP make_pair
#define pii pair<int, int>

using namespace std;

const int MX=2e5+5, Maxh=20;

int n, m, h[MX], par[MX][Maxh];

vector<int> adj[MX];

bool mark[MX];

void dfs(int v){
	mark[v]=1;
	for(int i=0;i<adj[v].size();i++){
		int u=adj[v][i];
		if(!mark[u]){
			par[u][0]=v;
			h[u]=h[v]+1;
			dfs(u);
		}
	}
}

void init(){
	for(int t=1;t<Maxh;t++) for(int i=1;i<=n;i++) par[i][t]=par[par[i][t-1]][t-1];
}

int getAncestor(int v, int hi){
	for(int i=Maxh-1;i>=0;i--){
		int p=par[v][i];
		if(h[p]>=hi){
			v=p;
		}
	}
	return v;
}

int lca(int v, int u){
	if(h[v]<h[u]) swap(v, u);
	v=getAncestor(v, h[u]);
	if(v==u) return v;
	for(int i=Maxh-1;i>=0;i--){
		if(par[v][i]!=par[u][i]){
			v=par[v][i], u=par[u][i];
		}
	}
	return par[v][0];
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n-1;i++){
		int v, u;
		cin>>v>>u;
		adj[v].pb(u), adj[u].pb(v);
	}
	h[0]=-1;
	dfs(1);
	init();
	for(int i=0;i<m;i++){
		int v, u;
		cin>>v>>u;
		cout<<lca(v, u)<<endl;
	}
	return 0;
}
