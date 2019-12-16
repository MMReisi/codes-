#include<bits/stdc++.h>

using namespace std;

template<class T>
class BST{
	private:
	struct node{
		T data;
		bool mark_d = 0, mark_r = 0, mark_l = 0;
		node *right, *left, *par;
	};
	node root;
	node* min_right_child(node* p){
		if(!(p->mark_l)) return NULL;
		p = p->left;
		while(p->mark_r) p = p->right;
		return p;
	}

	public:
	node* find(T data){
		node* p = &root;
		if(!(p->mark_d)) return NULL;
		while(true){
			if(p->data == data) return p;
			if(data > p->data){
				if(!(p->mark_r)) return NULL;
				p = p->right;
			}
			else{
				if(!(p->mark_l)) return NULL;
				p = p->left;
			}
		}
	}
	void insert(T data){
		node* p = &root;
		if(!(p -> mark_d)){p->data = data; p->mark_d = 1; return;}
		node *temp = (node*) malloc(sizeof(node));
		temp->data = data;
		temp->mark_d = 1;
		while(true){
			if(data == p->data) return;
			if(data > p->data){
				if(p->mark_r) p = p->right;
				else{
					p->right = temp;
					temp->par = p;
					p->mark_r = 1;
					return;
				}
			} 
			if(data < p->data){
				if(p->mark_l) p = p->left;
				else{
					p->left = temp;
					p->mark_l = 1;
					temp->par = p;
					return;
				}
			}
		}
	}
	void remove(node* temp){
		if(temp == NULL) return;
		// have no child
		if(!(temp->mark_l) and (!temp->mark_r)){
			if(temp == &root){root.mark_d = 0;return;}
			if(temp->par->mark_l and temp->par->left == temp) temp->par->mark_l = 0;
			else if(temp->par->mark_r and temp->par->right == temp) temp->par->mark_r = 0;
			free(temp);
			return;
		}
		// have one child (right)
		if(temp->mark_r and !(temp->mark_l)){
			if(temp == &root){root = *root.right;return;}
			if(temp->par->mark_l and temp->par->left == temp){
				temp->par->left = temp->right;
				temp->right->par = temp->par;
			}
			else if(temp->par->mark_r and temp->par->right == temp){
				temp->par->right = temp->right;
				temp->right->par = temp->par;
			}
			free(temp);
			return;
		}
		//have one child (left)
		if(!(temp->mark_r) and temp->mark_l){
			if(temp == &root){root = *root.left;return;}
			if(temp->par->mark_l and temp->par->left == temp){
				temp->par->left = temp->left;
				temp->left->par = temp->par;
			}
			else if(temp->par->mark_r and temp->par->right == temp){
				temp->par->right = temp->left;
				temp->left->par = temp->par;
			}
			free(temp);
			return;
		}
		// have two child
		node* last = min_right_child(temp);
		temp->data = last->data;
		remove(last); 
	}
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	static BST<int> b;
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		string s; cin>>s;
		int x; cin>>x;
		if(s == "insert") b.insert(x);
		else if(s == "remove") b.remove(b.find(x));
		else if(s== "find"){
			if(b.find(x) == NULL) cout<<"no"<<endl;
			else cout<<"yes"<<endl;
		}
	}
	return 0;
}