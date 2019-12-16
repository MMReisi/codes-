#include<bits/stdc++.h>

using namespace std;

const int MX = 2e5, Maxh = 18;

vector<int> adj[MX];
int par[MX][Maxh], h[MX], n;

void DFS(int u){
    for(auto v: adj[u]) if(par[u][0] != v) h[v] = h[u]+1, par[v][0] = u, DFS(v);
}
void init(){
    for(int i = 1; i<Maxh; i++) for(int j = 1; j<=n; j++) par[j][i] = par[par[j][i-1]][i-1]; 
}

int getAncestor(int u, int high){
    for(int i = Maxh-1; i>=0; i--){
        if(h[par[u][i]] >= high) u = par[u][i];
    }
    return u;
}
int lca(int u, int v){
    if(h[u] < h[v]) swap(u, v);
    u = getAncestor(u, h[v]);
    if(u == v) return v;
    for(int i = Maxh-1; i>0; i--){
        if(par[u][i] != par[v][i])u = par[u][i], v = par[v][i];
    }

    return par[u][0];
}

int main()
{
    cin>>n;
    for(int i = 0; i<n-1; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // using lca
    h[0] = -1;
    DFS(1);
    init();
    int u, v;
    cin>>u>>v;
    cout<<lca(u, v);
}