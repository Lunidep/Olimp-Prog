#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
//const int INF = 1e20 + 7;
 
struct Data {
	ll el, pos, cnt;
};
 
struct SegmentTree {
	SegmentTree(const vector<ll>& v) {
		n = v.size();
		tree.resize(4 * n);
		build(1, 0, n - 1, v);
	}
	Data get(ll l ,ll r) {
		return get(1, 0, n - 1, l , r);
	}
 
private:
	void build(ll id, ll sl, ll sr, const vector<ll>& v) {
		if (sl == sr) {
			tree[id] = { v[sl], sl, 1 };
			return;
		}
		ll mid = (sl + sr) / 2;
		build(id * 2, sl, mid, v);
		build(id * 2 + 1, mid + 1, sr, v);
		Data left = tree[id * 2];
		Data right = tree[id * 2 + 1];
		if (left.el == right.el) {
			tree[id] = { left.el, left.pos, left.cnt + right.cnt };
		}
		else {
			if (left.el < right.el) {
				swap(left, right);
			}
			tree[id] = left;
		}
	}
 
	Data get(ll id, ll sl, ll sr, ll ql , ll qr) {
		if (ql <= sl && sr <= qr) {
			return tree[id];
		}
		ll mid = (sl + sr) / 2;
		if (mid >= qr) {
			return get(id * 2, sl, mid, ql, qr);
		}
		if (mid < ql) {
			return get(id * 2 + 1, mid + 1, sr, ql, qr);
		}
		Data tmp1 = get(id * 2, sl, mid, ql, qr);
		Data tmp2 = get(id * 2 + 1, mid + 1, sr, ql, qr);
		if (tmp1.el == tmp2.el) {
			return { tmp1.el, tmp1.pos, tmp1.cnt + tmp2.cnt };
		}
		else {
			if (tmp1.el < tmp2.el) {
				swap(tmp1, tmp2);
			}
			return tmp1;
		}
	}
 
	vector<Data> tree;
	ll n;
};
 
 
int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
	ll n;
	cin >> n;
	vector<ll> v(n);
	for (ll& i : v) {
		cin >> i;
	}
	SegmentTree tree(v);
	ll q;
	cin >> q;
	while (q--) {
		ll l, r;
		cin >> l >> r;
		l--; r--;
		Data tmp = tree.get(l, r);
		cout << tmp.el << " " << tmp.pos + 1 << " " << tmp.cnt << "\n";
	}
	return 0;
}