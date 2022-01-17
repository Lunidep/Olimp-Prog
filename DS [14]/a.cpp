#include <iostream>
#include <vector>
 
using namespace std;
 
long long gcd (long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
 
struct SegmentTree {
    SegmentTree(const vector<long long>& v) {
    n = v.size();
    tree.resize(4 * n);
    build(1, 0, n - 1, v);
    }
    long long get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
    
private:
    void build(int id, int sl, int sr, const vector<long long>& v) {
        if (sl == sr) {
            tree[id] = v[sl];
            return;
        }
        int mid = (sl + sr) / 2;
        build(id * 2, sl, mid, v);
        build(id * 2 + 1, mid + 1, sr, v);
        tree[id] = gcd(tree[id * 2] , tree[id * 2 + 1]);
    }
    
    long long get(int id, int sl, int sr, int ql, int qr) {
        if (ql <= sl && sr <= qr) {
            return tree[id];
        }
        int mid = (sl + sr) / 2;
        if (mid >= qr) {
            return get(id * 2, sl, mid, ql, qr);
        }
        if (mid < ql) {
            return get(id * 2 + 1, mid + 1, sr, ql, qr);
        }
        return gcd(get(id * 2, sl, mid, ql, qr), get(id * 2 + 1, mid + 1, sr, ql, qr));
    }
    
    vector<long long> tree;
    int n;
};
 
 
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (long long& i : v) {
        cin >> i;
    }
    
    SegmentTree tree(v);
    int q;
    cin >> q;
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << tree.get(l, r) << "\n";
    }
}