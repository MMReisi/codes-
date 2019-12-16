#include<bits/stdc++.h>

using namespace std;

template<class T>
class LinkedList{
    private:
    struct node{
      T data;
      bool begin, end;
      node *next, *last;  
    };

    node first;
    node *p = &first;

    public:
    LinkedList(){
        p->begin = 1;
        p->end = 1;
        p->data = -1;
    }
    void print_begin_to_end(){
        if(first.end) return;
        node temp = *first.next;
        while(true){
            cout<<temp.data;
            if(temp.end) break;
            temp = *temp.next;
        }
    }
    void insert(T data){
        node* temp = (node*) malloc(sizeof(node));
        temp->data = data;
        temp->last = p;

        if(p->end){
            p->end = 0;
            p->next = temp;
            temp->end = 1;
            p = temp;
            p->begin = 0;
        }
        else{
            temp->next = p->next;
            p->next = temp;
            temp->last = p;
            temp->begin = 0;
            temp->end = 0;
            p = temp;
        }
    }
    void to_right(){
        if(p->end) return;
        p = p->next;
    }
    void to_left(){
        if(p->begin) return;
        p = p->last;
    }
};

int main(){
    string s;cin>>s;
    int n = 0;
    LinkedList<char> a;
    for(auto x: s){
        if(x == 'L') a.to_left();
        else if(x == 'R') a.to_right();
        else a.insert(x), n++;
    }
    a.print_begin_to_end();
    return 0;
}