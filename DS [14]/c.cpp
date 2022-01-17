#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
struct SegmentTree{
    SegmentTree(const vector<ll>& v){
    n = v.size();
    tree.resize(n * 4);
    build(1, 0, n - 1, v);
    }
 
    ll get(int l, int r){
        return get(1, 0, n - 1, l, r);
    }
 
    void set(int pos, ll x){
        set(1, 0, n - 1, pos, x);
    }
 
 
private:
    void build(int id, int sl, int sr, const vector<ll>& v){
        if (sl == sr){
            tree[id] = v[sl];
            return;
        }
        
        int mid = (sl + sr) / 2;
        build(id * 2, sl, mid, v);
        build(id * 2 + 1, mid + 1, sr, v);
        tree[id] = tree[id * 2] + tree[id * 2 + 1];
    }
    
    ll get(int id, int sl, int sr, int ql, int qr){
        if (ql <= sl && sr <= qr){
            return tree[id];
        }
        int mid = (sl + sr) / 2;
        if (mid >= qr){
            return get(id * 2, sl, mid, ql, qr);
        }
        if (mid < ql) {
            return get(id * 2 + 1, mid + 1, sr, ql, qr);
        }
        
        return get(id * 2, sl, mid, ql, qr) +
        get(id * 2 + 1, mid + 1, sr, ql, qr);
    }
    
    void set(int id, int sl, int sr, int pos, ll x){
        if (sl == sr){
            tree[id] += x;
            return;
        }
        int mid = (sl + sr) / 2;
        if (mid >= pos){
            set(id * 2, sl, mid, pos, x);
        }
        else{
            set(id * 2 + 1, mid + 1, sr, pos, x);
        }
        tree[id] = tree[id * 2] + tree[id * 2 + 1];
    }
    
    vector<ll> tree;
    int n;
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll& a : v){
        cin >> a;
    }
    
    SegmentTree tree(v);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int key, l, r;
        cin >> key >> l >> r;
        if (key == 0){
            l--;
            r--;
            cout << tree.get(l, r) << "\n";
        }
        else{
            l--;
            tree.set(l, r);
        }
    }
    return 0;
}