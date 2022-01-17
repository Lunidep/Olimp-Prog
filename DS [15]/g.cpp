#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 14;
 
#define endl '\n'
 
#define MOD 1e9 + 7
#define all(x) (x).begin(), (x).end()
 
#define int long long
 
struct SegmentTree{
 
    explicit SegmentTree(const vector<int>& v){
        this->n = v.size();
        this->tree.resize(4 * n);
        build(1, 0, n - 1, v);
    }
 
    void add(int l, int r, int x){
        add(1, 0, n - 1, l, r, x);
    }
 
    int get(int pos){
        return get(1, 0, n - 1, pos);
    }
 
private:
    vector<int> tree;
    int n;
 
    void build(int id, int sl, int sr, const vector<int>& v){
        if (sl == sr){
            tree[id] = v[sl];
            return;
        }
        int mid = (sl + sr) / 2;
        build(id * 2, sl, mid, v);
        build(id * 2 + 1, mid + 1, sr, v);
    }
 
    void add(int id, int sl, int sr, int ql, int qr, int x){
        if (ql <= sl && sr <= qr){
            tree[id] = x;
            return;
        }
        push(id, sl, sr);
        int mid = (sl + sr) / 2;
        if (mid >= ql){
            add(id * 2, sl, mid, ql, qr, x);
        }
        if (mid < qr){
            add(2 * id + 1, mid + 1, sr, ql, qr, x);
        }
    }
 
    void push(int id, int sl, int sr){
        if (sl != sr && tree[id] != 0){
            tree[id * 2] = tree[id];
            tree[id * 2 +1] = tree[id];
            tree[id] = 0;
        }
    }
 
    int get(int id, int sl, int sr, int pos){
        push(id, sl, sr);
        if (sl == sr){
            return tree[id];
        }
        int res = 0;
        int mid = (sl + sr) / 2;
        if (pos <= mid){
            res = get(id * 2, sl, mid, pos);
        } else {
            res = get(id * 2 + 1, mid + 1, sr, pos);
        }
        return res;
    }
 
};
 
signed main(){
 
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
        int q;
        cin >> q;
        if (q == 0){
            int l, r, c;
            cin >> l >> r >> c;
            --l; --r;
            tree.add(l, r, c);
        } else {
            int pos;
            cin >> pos;
            --pos;
            cout << tree.get(pos) << endl;
        }
    }
 
    cout << endl;
 
}