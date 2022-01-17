#include <iostream>
#include <vector>
#include <algorithm>
 
#define ull unsigned long long
using namespace std;
 
const int INF = 1e9 + 7;
 
int n;
 
ull dp(ull last, ull mask, vector<vector<int>>& mtx, vector<vector<ull>>& memo) {
	if (memo[last][mask] != INF) {
		return memo[last][mask];
	}
	ull prev_mask = mask ^ (1 << last);
	ull result = 0;
	if (prev_mask == 0) return memo[last][mask] = 1;
	for (int prev = 0; prev < n; prev++) {
		if ((prev_mask & (1 << prev)) && mtx[prev][last] == 1) {
			result += dp(prev, prev_mask, mtx, memo);
		}
	}
	return memo[last][mask] = result;
}
 
 
int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
	vector<vector<int>> mtx(n, vector<int>(n));
	vector<vector<ull>> memo(n, vector<ull>((1 << n), INF));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mtx[i][j];
		}
	}
	ull sum = 0;
	for (int i = 0; i < n; i++) {
		sum += dp(i, (1 << n) - 1, mtx, memo);
 
	}
	cout << sum;
 
	return 0;
}