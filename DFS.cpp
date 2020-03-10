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

void DFS(int k);

vi adj[MX];
int mark[MX], dis[MX];

int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int m,n;
	cin>> n>>m;
	REP(i, 0, m-1)
	{
		int x, y;
		cin>>x>>y;
		adj[x].PB(y);
		adj[y].PB(x);
	}	
	DFS(0);
	REP(i, 0, n) cout<<dis[i]<<endl;
	return 0;
}
void DFS(int k)
{
	mark[k] = 1;
	for(auto x: adj[k])
	{
		if(!mark[x])
		{	 
			dis[x] = dis[k]+1;
			DFS(x);
		}
	}	
}
