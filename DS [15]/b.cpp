#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
const ll LINF = 1e18 + 14;
#define endl '\n'
 
struct SegmantTree{
    SegmantTree(const vector<ll>& v){ 
        n = v.size();
        tree.resize(4 * n);
        delay.resize(4 * n);
        build(1, 0, n-1, v);
    }
    void add(ll l, ll r, ll x){
        add(1, 0, n-1, l , r, x);
    }
    ll get(ll l, ll r){
        return get(1, 0, n-1, l, r);
    }
    
private:
 
    ll sum(ll a, ll b){
        return a + b;
    }
    
    void build(ll id, ll sl, ll sr, const vector<ll>& v){
        if (sl == sr){
            tree[id] = v[sl];
            return;
        }
        ll mid = (sl + sr) / 2;
        build(id * 2, sl, mid, v);
        build(id * 2 + 1, mid + 1, sr, v);
        tree[id] = sum(tree[id * 2], tree[id * 2 + 1]);
    }
    
    void add(ll id, ll sl, ll sr, ll ql, ll qr, ll x){
        if (ql <= sl && sr <= qr){
            delay[id] += x;
            return;
        }
        push(id, sl, sr);
        ll mid = (sl + sr) / 2;
        if (mid >= ql){
            add(id * 2, sl, mid, ql, qr, x);
        }
        if (mid < qr){
            add(id * 2 + 1, mid + 1, sr, ql, qr, x);
        }
        tree[id] = sum(get(id * 2, sl, mid, sl, mid),
                        get(id * 2 + 1, mid + 1, sr, mid + 1, sr));
    }
    
    void push (ll id, ll sl, ll sr){
        tree[id] += delay[id]  * (sr - sl + 1);
        if (sl != sr){
            delay[id * 2] += delay[id];
            delay[id * 2 + 1] += delay[id];
        }
        delay[id] = 0;
    }
    
    ll get(ll id, ll sl, ll sr, ll ql, ll qr){
        push(id, sl, sr);
        if (ql <= sl && sr <= qr){
            return tree[id];
        }
        ll mid = (sl + sr) / 2;
        ll res = 0;
        if (mid >= ql){
            res = sum(res, get(id * 2, sl, mid, ql, qr));
        }
        if (mid < qr){
            res = sum(res, get(id * 2 + 1, mid + 1, sr, ql, qr));
        }
        return res;
    }
    vector<ll> tree;
    vector<ll> delay;
    ll n;
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll& a: v){
        cin >> a;
    }
    
    SegmantTree tree(v);
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++){
        ll l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;
        
        tree.add(l, r, x);
        cout << tree.get(l, r) << "\n";
        //cout.flush();
    }
    
    return 0;
}