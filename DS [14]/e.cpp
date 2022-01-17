#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
const int INF = 1e5 + 7;
#define endl '\n'
 
struct SegmantTree{
    SegmantTree(const vector<ll>& v){
        n = v.size();
        tree.resize(4 * n);
        build(1, 0, n-1, v);
    }
    ll get(ll l, ll r){
        return get(1, 0, n-1, l , r);
    }
    void set(int pos, int x){
        return set(1, 0, n-1, pos, x);
    }
private:
    void build(ll id, ll sl, ll sr, const vector<ll>& v){
        if (sl == sr){
            tree[id] = v[sl];
            return;
        }
        ll mid = (sl + sr) / 2;
        build(id * 2, sl, mid, v);
        build(id * 2 + 1, mid + 1, sr, v);
        tree[id] = tree[id * 2] + tree[id * 2 + 1];
    }
    
    ll get(ll id, ll sl, ll sr, ll ql, ll qr){
        if (ql <= sl && sr <= qr){
            return tree[id];
        }
        ll mid = (sl + sr) / 2;
        if (mid >= qr){
            return get(id * 2, sl, mid, ql, qr);
        }
        if (mid < ql){
            return get(id * 2 + 1, mid + 1, sr, ql, qr);
        }
        return get(id * 2, sl, mid, ql, qr) + get(id * 2 + 1, mid + 1, sr, ql, qr);
    }
    
    void set(ll id, ll sl, ll sr, ll pos, ll x){
        if (sl == sr){
            tree[id] += x;
            return;
        }
        int mid = (sl + sr) / 2;
        if (mid < pos){
            set(id * 2 + 1, mid + 1, sr, pos, x);
        }
        else{
            set(id * 2, sl, mid, pos, x);    
        }
        tree[id] = tree[id * 2] + tree[id * 2 + 1];
    }
    ll n;
    vector<ll> tree;
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    ll n;
    cin >> n;
    vector<ll> new_tree(INF, 0);
    vector<ll> v(n+1);
    
    for (ll i=0; i<n; i++){
        cin >> v[i+1];
        new_tree[v[i+1]] += v[i+1];
    }
    
    SegmantTree tree(new_tree);
    
    ll q;
    cin >> q;
    for (ll i=0; i<q; i++){
        ll key, l, r;
        cin >> key >> l >> r;
        if (key == 0){
            cout << tree.get(l, r) << "\n";
        }
        else{
            tree.set(v[l], -v[l]);
            v[l] = r;
            tree.set(r, r);
        }
    }
}