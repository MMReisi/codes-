#include<bits/stdc++.h>

using namespace std;

template<class T>
class MyQueue{
    private:
    int MaxSize = (int)1e5;
    T arr[(int)1e5];
    int n = 0;
    int p = 0;

    public:
    int size(){
        return n;
    }
    void push(T x){
        n++;
        arr[p] = x;
        p++;
        p%=MaxSize;
    }
    T front(){
        return arr[p-n];
    }
    void pop(){
        n--;
    }
};

int main(){
    cout<<"hello world:)"<<endl;
    return 0;
}
