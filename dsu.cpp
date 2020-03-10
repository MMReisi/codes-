#include<bits/stdc++.h>

using namespace std;
const int MX = 1e5;
int parent[MX], size[MX];

int make(int n){
    for(int i = 0; i<n; i++) parent[i] = i, size[i] = 1;
}

int find(int i){
    if(parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void un(int a, int b){
    a = find(a), b = find(b);
    if(a!=b){
        if(size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a]+=size[b];
    }
}

bool check(int a, int b){
    return find(a)==find(b);
}

int main(){
    make(11);
    un(1, 2);
    un(2, 3);
    un(5, 6);
    un(6, 3);
    cout<<check(1, 5)<<endl;
    cout<<check(5, 9)<<endl;
    return 0;
}