#include<bits/stdc++.h>

using namespace std;

const int P = (1 << 17);
int n;


int st[P * 2];
int lazy[P * 4];
int arr[P];

void push(int u) {
    lazy[u * 2] += lazy[u];
    lazy[u * 2 + 1] += lazy[u];
    st[u] += lazy[u];
    lazy[u] = 0;
}

void build(int u, int l, int r) {
    // cout << u << ": " << l << " " << r << endl; 
    if (l == r) {
        st[u] = arr[l-1];
        return;
    }
    int mid = (l + r) >> 1;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
    st[u] = max(st[u * 2], st[u * 2 + 1]);
    return;
}


int q(int u, int l, int r, int lq, int rq) {
    if(l > rq || r < lq) return 0;
    // cout << l << " " << r << endl;

    if(l >= lq && rq >= r) return st[u] + lazy[u];

    push(u);
    
    int mid = (l + r) >> 1;

    return max(q(u * 2, l, mid, lq, rq), q(u * 2 + 1, mid + 1, r, lq, rq));
}

void up(int u, int l, int r, int lq, int rq, int a) {
    if(l > rq || r < lq) return;

    if(l >= lq && rq >= r) {
        lazy[u] += a;
        return;
    }

    push(u);

    int mid = (l + r) >> 1;

    up(u * 2, l, mid, lq, rq, a);
    up(u * 2 + 1, mid + 1, r, lq, rq, a);
    
    st[u] = max(st[u * 2] + lazy[u * 2], st[u * 2 + 1] + lazy[u * 2 + 1]);
    return;
}



int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];
    build(1, 1, P);

    while (1) {
        char Q;
        cin >> Q;
        if (Q == '?') {
            int l, r;
            cin >> l >> r;
            cout << q(1, 1, P, l, r) << endl;
        } else {
            int l, r, a;
            cin >> l >> r >> a;
            up(1, 1, P, l, r, a);
        }
    }



}
