#include <iostream>
#include <vector>
 
using namespace std;
 
struct Treap{
    Treap(int key_) : val(key_), sum(key_) {};
    int val;
    int sum;
    bool rev;
    int size = 1;
    int prior = rand();
    Treap* left = nullptr;
    Treap* right = nullptr;
};
 
int sum(Treap* node){
    if (node == nullptr){
        return 0;
    }
    return node->sum;
}
 
int size(Treap* node){
    if (node == nullptr){
        return 0;
    }
    return node->size;
}
 
bool reverse(Treap* node){
    if (node == nullptr){
        return false;
    }
    return node->rev;
}
 
void update(Treap* node){
    if (node == nullptr){
        return;
    }
    node->sum = sum(node->left) + sum(node->right) + node->val;
    node->size = size(node->left) + size(node->right) + 1;
}
 
void push(Treap* node){
    if (node == nullptr || reverse(node) == false){
        return;
    }
    node->rev = false;
    swap(node->left, node->right);
    if (node->left != nullptr){
        node->left->rev ^= 1;
    }
    if (node->right != nullptr){
        node->right->rev ^= 1;
    }
}
 
Treap* merge(Treap* left, Treap* right){
    if (left == nullptr){
        return right;
    }
    if (right == nullptr){
        return left;
    }
    push(left);
    push(right);
    if (left->prior < right->prior){
        right->left = merge(left, right->left);
        update(right);
        return right;
    }
    else {
        left->right = merge(left->right, right);
        update(left);
        return left;
    }
}
 
void split(Treap* node, int key, Treap*& left, Treap*& right){
    if (node == nullptr){
        left = right = nullptr;
        return;
    }
    push(node);
    if (size(node->left) + 1 < key){
        left = node;
        split(left->right, key - size(node->left) - 1, left->right, right);
    }
    else{
        right = node;
        split(right->left, key, left, right->left);
    }
    update(right);
    update(left);
}
 
void insert(Treap*& tree, int val, int key){
    Treap* left = nullptr, *right = nullptr;
    Treap* node = new Treap(val);
    
    split(tree, key, left, right);
    
    tree = merge(merge(left, node), right);
}
 
int get (Treap*& tree, int l, int r){
    Treap* left;
    Treap* mid;
    Treap* right;
    split(tree, r + 1, left, right);
    split(left, l, left, mid);
    int res = sum(mid);
    left = merge(left, mid);
    tree = merge(left, right);
    return res;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin >> n;
    Treap* tree = nullptr;
    for (int i = 0; i < n; i++){
        int val, key;
        cin >> val >> key;
        insert(tree, val, key + 1);
    }
    
    for (int i = 0; i < n; i++){
        cout << get(tree, i + 1, i + 1) << ' ';
    }
    
    
    return 0;
}