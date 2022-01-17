#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
//const int INF = 1e20 + 7;
 
struct SegmentTree {
    SegmentTree(const vector<ll>& v) {
        n = v.size();
        tree.resize(4 * n);
        add_tree.resize(4 * n); 
        build(1, 0, n - 1, v);
    }
    /*
    int print(){
        for (int i = 0; i < n*4; i++){
            cout << tree[i] << ' ';
        }
    }
    */
    ll get(ll pos) {
        return get(1, 0, n - 1, pos);
    }
    
    void add(ll l, ll r, ll x){
        return add(1, 0, n-1, l, r, x);
    }
    
private:
    
    void build(ll id, ll sl, ll sr, const vector<ll>& v) {
        if (sl == sr) {
            tree[id] = v[sl];
            return;
        }
 
        ll mid = (sl + sr) / 2;
        build(id * 2, sl, mid, v);
        build(id * 2 + 1, mid + 1, sr, v);
        tree[id] = tree[id * 2] + tree[id * 2 + 1];
    }
    
    ll get(ll id, ll sl, ll sr, ll pos) {
        if (sl == sr){
            return tree[id] + add_tree[id];
        }
        ll mid = (sl + sr) / 2;
        if (mid >= pos){
            return get(id * 2, sl, mid, pos) + add_tree[id];
        }
        else{
            return get(id * 2 + 1, mid + 1, sr, pos) + add_tree[id];
        }
        
    }
    
    void add(ll id, ll sl, ll sr, ll ql, ll qr, ll x){
        if (ql <= sl && sr <= qr){
            add_tree[id] += x;
            return;
        }
        ll mid = (sl + sr) / 2;
        if (mid >= ql){
            add(id * 2, sl, mid, ql, qr, x);
        }
        if (mid < qr){
            add(id * 2 + 1, mid + 1, sr, ql, qr, x);
        }
    }
    vector<ll> add_tree;
    vector<ll> tree;
    ll n;
};
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll& a : v) {
        cin >> a;
    }
    SegmentTree tree(v);
    
    ll q, key;
    cin >> q;
    
    for (ll i = 0; i < q; i++){
        cin >> key;
        if (key == 1){
            ll l, r, x;
            cin >> l >> r >> x;
            tree.add(l - 1, r - 1, x);
        }
        else{
            ll s;
            cin >> s;
            cout << tree.get(s - 1) << "\n";
        }
    }
    //cout << endl << endl;
    //tree.print() int;
    //cout << endl << endl;
    
    return 0;
}