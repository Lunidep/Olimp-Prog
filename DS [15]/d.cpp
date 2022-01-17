#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 14;
 
#define endl '\n'
#define int long long
 
struct Node{
    ll data = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};
 
struct SegmantTree{
    SegmantTree(int n_) : n(n_) {}
    
    void set(int pos, int x){
        root = set(root, 0, n-1, pos, x);
    }
    
    int get(int ql, int qr){
        return get(root, 0, n - 1, ql, qr);
    }
    
private:
    Node* set(Node* node, int sl, int sr, int pos, int x){
        if (node == nullptr){
            node = new Node;
        }
        if (sl == sr){
            node->data += x;
            return node;
        }
        int mid = (sl + sr) / 2;
        if (mid >= pos){
            node->left = set(node->left, sl, mid, pos, x);
        }
        else {
            node->right = set(node->right, mid + 1, sr, pos, x);
        }
        node->data = sum(data(node->left), data(node->right));
        return node;
    }
    
    
    int sum(int a, int b){
        return a + b;
    }
    
    int get(Node* node, int sl, int sr, int ql, int qr){
        if (node == nullptr){
            return 0;
        }
        if (ql <= sl && sr <= qr){
            return node->data;
        }
        int mid = (sl + sr) / 2;
        int res = 0;
        if (mid >= ql){
            res = sum(res, get(node->left, sl, mid, ql, qr));
        }
        if (mid < qr) {
            res = sum(res, get(node->right, mid + 1, sr, ql, qr));
        }
        return res;
    }
    
    int data(Node* node){
        if (node == nullptr){
            return 0;
        }
        return node->data;
    }
    
    Node* root = nullptr;
    int n;
};
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    SegmantTree tree(INF);
    for (int i = 0; i < n; i++){
        int key;
        cin >> key;
        if (key == 0){
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << tree.get(l, r) << endl;
            cout.flush();
        }
        else{
            int pos, x;
            cin >> pos >> x;
            pos--;
            tree.set(pos, x);
        }
    }
    
    
    return 0;
}