#include<bits/stdc++.h>

using namespace std;

const long long MX=1e6,mod=998244353;

long long f[MX];

long long __pow(long long a, long long b){
	if(!b) return 1;
	long long temp = __pow(a, b/2);
	if(b%2) return (((temp*temp)%mod)*a)%mod;
	return (temp*temp)%mod;
}

long long C(long long a, long long b){
	return ((f[a] * __pow((f[b]*f[a-b])%mod, mod-2)) % mod);
}

int main(){
	long long n, m; cin>>n>>m;
	f[0] = 1; for(int i = 1; i<MX; i++) f[i] = ((f[i-1] * i)%mod);
	cout<<((((n-2) * C(m, n-1))%mod) * __pow((long long)2, (long long)n-3))%mod<<endl;

}
