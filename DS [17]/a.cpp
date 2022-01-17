
#include <iostream>
#include <vector>
using namespace std;
 
#define endl '\n'
 
struct Treap{
    Treap(int key) : key(key) {};
    int key;
    int priora = rand();
    Treap* left = nullptr;
    Treap* right = nullptr;
};
 
void dfs (Treap* node){
    if (node != nullptr){
        cout << node->key << ' ' << node->priora << "\n";
        dfs(node->left);
        dfs(node->right);
    }
    else{
        cout << "null\n";
    }
}
 
Treap* merge(Treap* left, Treap* right){
    if (left == nullptr){
        return right;
    }
    if (right == nullptr){
        return left;
    }
    if (left->priora < right->priora){
        right->left = merge(left, right->left);
        return right;
    }
    else {
        left->right = merge(left->right, right);
        return left;
    }
}
 
void split(Treap* node, int key, Treap*& left, Treap*& right){
    if (node == nullptr){
        left = right = nullptr;
        return;
    }
    if (node->key < key){
        left = node;
        split(left->right, key, left->right, right);
    }
    else{
        right = node;
        split(right->left, key, left, right->left);
    }
}
 
void insert(Treap*& tree, int key, int p){
    Treap* left = nullptr, *right = nullptr;
    Treap* node = new Treap(key);
    
    node->priora = p;
    
    split(tree, key, left, right);
    
    tree = merge(merge(left, node), right);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin >> n;
    Treap* tree = nullptr;
    for (int i = 0; i < n; i++){
        int key, priora;
        cin >> key >> priora;
        
        insert(tree, key, priora);
    }
    dfs(tree);
    
    return 0;
}