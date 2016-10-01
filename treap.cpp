#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
struct treap_node{
	treap_node *left,*right;
	int value;
	int prioxity;
};
void treap_walking(treap_node *n){
	if(n){
		treap_walking(n->left);
		cout<<n->value;
		treap_walking(n->right);
	}
}
treap_node treap_finding(treap_node x,int n){
	if(!x)return 0;
	if(x->value==n)return x;
	else if(x->value>n)return treap_finding(x->left,n);
	else return treap_finding(x->right,n);
}
void treap_left_rotate(treap_node *&x){
	treap_node *y=x->right;
	x->right=y->left;
	y->left=x;
	x=y;
}
void treap_right_rotate(treap_node *&x){
	treap_node *y=x->left;
	x->left=y->right;
	y->right=x;
	x=y;
}
void treap_insert(treap_node *&x,int value){
	if(!x){
		x=new treap_node;
		x->value=value;
		x->prioxity=rand();
	}else if(x->value>value){
		treap_insert(x->left,value);
		if(x->left->prioxity<x->prioxity)treap_right_rotate(x);
	}else{
		treap_insert(x->right,value);
		if(x->right->prioxity<x->prioxity)treap_left_rotate(x);
	}
}
void treap_del(treap_node *&x,int value){
	if(value==x->value){
		if(!x->left || !x->right){
			treap_node *t=x;
			if(!x->right)x=x->left;
			else x=x->right;
			delete t;
		}else{
			if(x->left->prioxity<x->right->prioxity){
				treap_right_rotate(x);
				treap_del(x->right,value);
			}else{
				treap_left_rotate(x);
				treap_del(x->left,value);
			}
		}
	}
	else if(value<x->value){
		treap_del(x->left,value);
	}else{
		treap_del(x->right,value);
	}
}
int main(){
	srand((unsigned)time(NULL));
	 
	return 0;
}
