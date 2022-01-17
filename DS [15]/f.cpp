#include <cstdlib>
#include <string>
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
    
    ll get(ll l, ll r){
        return get(1, 0, n-1, l, r);
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
        tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
    }
    
    void push (ll id, ll sl, ll sr){
        tree[id] += delay[id];
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
        ll res = -LINF;
        if (mid >= ql){
            res = max(res, get(id * 2, sl, mid, ql, qr));
        }
        if (mid < qr){
            res = max(res, get(id * 2 + 1, mid + 1, sr, ql, qr));
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
    
    ll n, size, dlin;
    cin >> n >> size;
    vector<ll> v(n);
    
    char napr;
    
    for (ll i = 0; i < n; i++){
        cin >> dlin >> napr;
        if (napr == 'L'){
            v[i] = dlin;
        }
        else{
            v[i] = size - dlin;
        }
    }
    
    
    SegmantTree tree(v);
    
    cout << tree.get(0, n);
    
    
    return 0;
}