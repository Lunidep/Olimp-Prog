#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const int INF = 1e9 + 7;
int g = 0;
 
bool check(int a) {
	return !(a & (a << 1));
}
 
bool kok(int a, int b) {
	return check(a & b) && check(((~a) & ((1 << g) - 1)) & ((~b) & ((1 << g) - 1)));
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	g = m;
	vector<int> cur(1 << m, 1), prev(1 << m);
	for (int i = 0; i < n - 1; i++) {
		swap(prev, cur);
		fill(cur.begin(), cur.end(), 0);
		for (int mask = 0; mask < (1 << m) ; mask++) {
			for (int prev_mask = 0; prev_mask < (1 << m) ; prev_mask++) {
				if (kok(mask, prev_mask)) {
					cur[mask] = ((cur[mask] % INF) + (prev[prev_mask] % INF)) % INF;
				}
			}
		}
	}
	int res = 0;
	for (int i = 0; i < (1 << m); i++) {
		res = ((res % INF) + (cur[i] % INF)) % INF;
	}
	cout << res << '\n';
	return 0;
}