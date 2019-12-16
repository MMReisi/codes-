#include<bits/stdc++.h>

using namespace std;

template<class T>
class MyStack{
    private:
    int MaxSize = (int)1e5;
    T arr[(int)1e5];
    int n = 0;
    int p = 0;

    public:
    int size(){
        return n;
    }
    T front(){
        return arr[p-1];
    }
    void push(T x){
        n++;
        arr[p] = x;
        p++;
    }
    void pop(){
        n--;
        p--;
    }

};

int main()
{
    cout<<"hello world :)"<<endl;
    return 0;
}