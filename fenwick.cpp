#pragma GCC optimize "-Ofast"
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define reg(x) x.begin(),x.end()
#define FOR(i, a, b) for(ll i =a;i < b; i++)
#define REP(i, b) FOR(i, 0, b)
#define print(x) cerr << #x << " is " << x << endl;
#define print_it(v) for(auto x: v) cout<<x<<" ";cout<<endl;
#define print_arr(a, n) REP(i, n) cout<<a[i]<<" "; cout<<endl;
#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout << fixed << setprecision(12)
#define vi vector<ll> 
#define pii pair<ll, ll>

const ll mod = 1e9 + 7;
const ll MX = 2e5 + 3;

ll fen[MX];

// fenwick: 
inline void add(ll id, ll val)
{for(;id<MX;id+=id&-id) fen[id] += val;}

inline ll get(ll id)
{ll sum = 0;for(;id;id-=id&-id) sum+=fen[id];return sum;}


int main()
{	
	Init;
	vi num = {5, 6, 10, 20, 30 , 40 , 9};
	int i = 1;
	for(auto x: num) 
	{
		add(i, x);
		i++;
	}
	cout<<get(7)<<endl;
	memset(fen, 0, MX);
	add(10, 5);
	add(21, -5);
	add(15, 6);
	add(21, -6);
	cout<<get(19)<<endl;
	return 0;
}

