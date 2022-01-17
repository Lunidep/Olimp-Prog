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
 
    int get(int l, int r, int x){
        return get(1, 0, n - 1, l, r, x);
    }
 
private:
    vector<vector<int>> tree;
    int n;
 
    void build(int id, int sl, int sr, const vector<int>& v){
        if (sl == sr){
            tree[id] = {v[sl]};
            return;
        }
        int mid = (sl + sr) / 2;
        build(id * 2, sl, mid, v);
        build(id * 2 + 1, mid + 1, sr, v);
        merge(all(tree[id * 2]), all(tree[id * 2 + 1]), back_inserter(tree[id]));
    }
 
 
    int get(int id, int sl, int sr, int ql, int qr, int x){
        if (ql <= sl && sr <= qr){
            int idx = lower_bound(all(tree[id]), x) - tree[id].begin();
            return (idx < tree[id].size()) ? tree[id][idx] : MOD;
        }
        int mid = (sl + sr) / 2;
        int res = MOD;
        if (mid >= qr){
            return min(res, get(id * 2, sl, mid, ql, qr, x));
        } else if (mid < ql){
            return min(res, get(id * 2 + 1, mid + 1, sr, ql, qr, x));
        } else {
            return min(get(id * 2, sl, mid, ql, qr, x), get(id * 2 + 1, mid + 1, sr, ql, qr, x));
        }
    }
 
};
 
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& e : v){
        cin >> e;
    }
 
    SegmentTree tree(v);
 
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i){
        int l, r, x;
        cin >> l >> r >> x;
        --l; --r;
        int res = tree.get(l, r, x);
        if (res == MOD){
            cout << "None\n";
        } else {
            cout << res << endl;
        }
    }
 
    cout << endl;
    
    return 0;
}