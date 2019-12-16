#include<bits/stdc++.h>

using namespace std;
const int MX = 1e6;


template<class T>
class MinHeap{
    private:
    T heap[MX];
    int p;
    int par(int x){
        return floor(x/2);
    }
    int min_child(int x){
        if((2*x) > p) return -1;
        if((2*x+1) > p) return 2*x;
        if(heap[2*x]<heap[2*x+1]) return 2*x;
        return 2*x+1;
    }

    public:
    MinHeap(){
        p = 1;
    }
    void insert(T x){
        heap[p] = x;
        if(p == 1) {p++;return;}
        int k = p;
        while(heap[k]<heap[par(k)]){
            swap(heap[k], heap[par(k)]);
            k = par(k);
            if(k == 1) break;
        }
        p++;
    }
    T min(){
        return heap[1];
    }
    void pop_min(){
        heap[1] = heap[p-1];
        p--;
        int k = min_child(1);
        int t = 1;
        while(k != -1 and heap[t] > heap[k]){
            swap(heap[t], heap[k]);
            t = k;
            k = min_child(t);
        }
    }
};

int main(){
    MinHeap<int> a;
    int n; cin>>n;
    for(int i = 0; i<n; i++){
        int temp; cin>>temp;
        a.insert(temp);
    }
    for(int i = 0; i < n; i++){
        cout<<a.min()<<" ";
        a.pop_min();
    }
    return 0;
}