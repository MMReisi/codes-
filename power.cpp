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

ll pw(int a, int b);

int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int i, j;
	cin>>i >> j;
	cout<<pw(i,j);
	return 0;
}
ll pw(int a, int b)
{
	if(b== 1) return a;
	ll temp = pw(a, b/2);
	temp *= temp;
	if(b%2== 1) temp *= (ll) a;
	return temp;
}
