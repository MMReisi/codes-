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

ll tree[MX];
ll a[MX];

void build(ll node, ll start, ll end)
{
	if(start+1 == end) tree[node] = a[start];
	else {
		ll mid = (start+end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid, end);
		tree[node] = tree[2*node]+tree[2*node+1];
	}
}

void add(ll node, ll start, ll end, ll idx, ll val)
{
	if(start+1 == end) tree[node] += val;
	else{
		ll mid = (start+end)/2;
		if(idx>=start and idx<mid) add(2*node, start, mid, idx, val);
		else add(2*node+1, mid, end, idx, val);		
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}
ll give(ll node, ll start, ll end, ll l, ll r)
{
	if(end<l+1 or r < start+1) return 0;
	if(l<=start and end<= r)return tree[node];
	ll mid = (start+end)/2;
	ll left = give(2*node, start, mid, l, r);
	ll right = give(2*node+1, mid, end, l, r);
	return (left+right);
}


int main()
{	
	Init;
	ll n;cin>>n;
	FOR(i, 1, n+1) cin>>a[i];
	build(1, 1, n+1);
	add(1, 1, n+1, 4, 10);
	cout<<give(1, 1, n+1, 4, 6);
	//print_arr(tree, 16)
	return 0;
}

