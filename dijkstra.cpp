#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for(int i =a;i<=b; i++)
const int MX = 2e5 + 3;

int mark[MX], dis[MX];
vector<pi> adj[MX];
void dijkstra(int k);
int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m;
	cin>>n>>m;
	REP(i, 0, m-1)
	{
		int x, y, z;
		cin>>x>>y>>z;
		adj[x].PB(MP(z, y));
		adj[y].PB(MP(z, x));
	}
	dijkstra(0);
	REP(i, 0, n) cout<<dis[i]<< endl;
	return 0;
}
void dijkstra(int k)
{
	set<pi> s;
	s.insert(MP(k, 0));
	while(s.size())
	{
		auto temp = (*s.begin());
		s.erase(s.begin());	
		if(mark[temp.S]) continue;
		mark[temp.S] = 1;
		dis[temp.S] = temp.F;
		for(auto x: adj[temp.S]) if(!mark[x.S]) s.insert(MP(temp.F+x.F, x.S));
	}
}
