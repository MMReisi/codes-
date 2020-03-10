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
vi adj[MX];

void BFS(int k);

int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	REP(i, 0,m-1)
	{
		int x, y;
		cin>>x>>y;
		adj[x].PB(y);
		adj[y].PB(x);
	}
	BFS(0);
	REP(i, 0, n) cout<<dis[i]<<endl;
	return 0;
}
void BFS(int k)
{
	deque<int> dq;
	dq.PB(k);
	while(dq.size())
	{
		int temp = dq.front();
		dq.pop_front();	
		mark[temp] = 1;
		for(auto x: adj[temp])
		{
			if(!mark[x])
			{
				mark[x] = 1;
				dq.PB(x);
				dis[x] = dis[temp]+1;
			}
		}
	}
}
