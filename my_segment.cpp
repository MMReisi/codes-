#include<bits/stdc++.h>

using namespace std;

const int MX = (int) 1<<20;
int sum[MX];
bool mark[MX];

void add(int who, int l, int r, int i, int x){
    if(i<l or r<=i) return;
    sum[who] += x;
    if(l+1 == r) return;
    add(2*who, l, (r+l)/2, i, x);
    add(2*who+1, (r+l)/2, r, i, x);
}

int get_sum(int who, int l, int r, int ql, int qr){
    if(qr <= l or ql >= r) return 0;
    if(ql <= l and r <= qr) return sum[who];
    return get_sum(2*who, l, (l+r)/2, ql, qr) + get_sum(2*who+1, (l+r)/2, r, ql, qr);
}


int main(){
    return 0;
}