#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, k; cin>>n>>k;
	vector<int> a(n); for(auto &x: a) cin>>x;
	deque<int> g = {a[0]};
	int i;
	for(i = 1; i<k; i++){
		while(g.size() and g.back()>a[i]){
			g.pop_back();
		}
		g.push_back(a[i]);
	}
	cout<<g.front()<<" ";
	for(; i< n; i++){
		while(g.size() and g.back()>a[i]){
			g.pop_back();
		}
		g.push_back(a[i]);
		if(g.front() == a[i-k]) g.pop_front();
		cout<<g.front()<<" ";
	}
	cout<<endl;
}
