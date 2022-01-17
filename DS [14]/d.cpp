#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
//const int INF = 1e20 + 7;
 
ll n = 0, sum = 0, i = 0;
 
struct SegmentTree {
	SegmentTree(const vector<ll>& v) {
		n = v.size();
		tree.resize(4 * n, 0);
	}
	ll get(ll l, ll r) {
		return get(1, 0, n - 1, l, r);
	}
	void add(ll pos, ll x) {
		return add(1, 0, n - 1, pos, x);
	}
 
private:
	ll get(ll id, ll sl, ll sr, ll ql, ll qr) {
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
		return get(id * 2, sl, mid, ql, qr) + get(id * 2 + 1, mid + 1, sr, ql, qr);
	}
 
	void add(ll id, ll sl, ll sr, ll pos, ll x) {
		if (sl == sr) {
			tree[id] += x;
			return;
		}
		ll mid = (sl + sr) / 2;
		if (mid >= pos) {
			add(id * 2, sl, mid, pos, x);
		}
		else {
			add(id * 2 + 1, mid + 1, sr, pos, x);
		}
		tree[id] = tree[id * 2] + tree[id * 2 + 1];
	}
	vector<ll> tree;
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
	for (int i = 0; i < n; i++) {
		tree.add(v[i] - 1, 1);
		if (v[i] == n) {
			sum += 0;
			continue;
		}
		sum += tree.get(v[i], n - 1);
	}
	cout << sum;
	cout << "\n";
	return 0;
}
