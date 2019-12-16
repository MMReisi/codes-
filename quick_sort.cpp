#pragma GCC optimize "-Ofast"
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define reg(x) (x).begin(), (x).end();
#define sz(x) ((int)(x).size())
#define print(x) cerr << x <<endl;
#define print_it(v) for(auto x: v) cout<<x<<" ";cout<<endl;
#define print_arr(a, n) REP(i, n) cout<<a[i]<<" "; cout<<endl;
#define FOR(i, a, b) for(ll i =a;i < b; i++)
#define REP(i, b) FOR(i, 0, b)
#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout << fixed << setprecision(12)
const ll INF = (ll)1e17+10;
const ll mod = (ll)1e9 + 7;
const ll MX = (ll)2e5 + 3;
const int Maxh = 20;

vector<int> quick_sort(vector<int> f)
{
	if(f.size() <= 1) return f;
	vector<int> left, right, equal, out;
	int pvot = f.front();
	for(auto x: f)
	{
		if(x>pvot) right.PB(x);
		else if(x == pvot) equal.PB(x);
		else left.PB(x);
	}
	left = quick_sort(left);
	right = quick_sort(right);
	for(auto x: left) out.PB(x);
	for(auto x: equal) out.PB(x);
	for(auto x: right) out.PB(x);
	return out; 
}

int main()  
{
    Init;
	vector<int> v;
	int temp;
	while(cin>>temp) v.PB(temp);
	print_it(quick_sort(v));
    return 0;
}
