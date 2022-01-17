#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 14;
 
#define endl '\n'
 
#define MOD 1e9 + 7
#define all(x) (x).begin(), (x).end()
 
struct SegmentTree{
    
    explicit SegmentTree(const vector<int>& v){
        this->n = v.size();
        this->tree.resize(4 * n);
        build(1, 0, n - 1, v);
    }
    
    int get(int l, int r){
        return get(1, 0, n - 1, l, r).first;
    }
    
private:
    vector<pair<int, int>> tree;
    int n;
    
    static pair<int, int> combine(pair<int, int> a, pair<int, int> b){
        if (a.first == b.first){
            return {a.first, a.second + b.second};
        }
        if (a.first == MOD){
            return b;
        }
        if (b.first == MOD){
            return a;
        }
        if (a.second > b.second){
            return {a.first, a.second - b.second};
        } else {
            return {b.first, b.second - a.second};
        }
    }
    
    void build(int id, int sl, int sr, const vector<int>& v){
        if (sl == sr){
            tree[id] = {v[sl], 1};
            return;
        }
        int mid = (sl + sr) / 2;
        build(id * 2, sl, mid, v);
        build(id * 2 + 1, mid + 1, sr, v);
        tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
    }
    
    pair<int, int> get(int id, int sl, int sr, int ql, int qr){
        if (ql <= sl && sr <= qr){
            return tree[id];
        }
        int mid = (sl + sr) / 2;
        int res = 0;
        pair<int, int> tmp1 = {MOD, 0};
        pair<int, int> tmp2 = {MOD, 0};
        if (mid >= ql){
            tmp1 = combine(tmp1, get(id * 2, sl, mid, ql, qr));
        }
        if (mid < qr){
            tmp2 = combine(tmp2, get(id * 2 + 1, mid + 1, sr, ql, qr));
        }
        return combine(tmp1, tmp2);
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    vector<vector<int>> pos(1e5 + 1);
    for (int i = 0; i < n; ++i){
        int e;
        cin >> e;
        v[i] = e;
        pos[e].push_back(i);
    }
 
    SegmentTree tree(v);
 
    for (int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        --l; --r;
        int res = tree.get(l, r);
        auto lb = lower_bound(all(pos[res]), l) - pos[res].begin();
        auto rb = lower_bound(all(pos[res]), r) - pos[res].begin();
        int cnt = 1;
        for (auto it = lb; it != rb; ++it){
            ++cnt;
        }
        if (pos[res][rb] != r){
            --cnt;
        }
        if (2 * cnt > r - l + 1){
            cout << res << endl;
        } else {
            cout << -1 << endl;
        }
    }
    cout << endl;
 
}