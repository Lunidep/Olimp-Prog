#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
 
const long long MOD = 1e9+7;
using namespace std;
 
bool even_one(long long a, long long b) {
	long long sdv = a & b;
	long long cnt = 0;
	while (sdv > 0){
		if (sdv & 1){
			cnt++;
		}
		else{
			if (cnt & 1){
				return false;
			}
			cnt = 0;
		}
		sdv /= 2;
	}
	return !(cnt & 1);
}
 
bool ok(long long a, long long b) {
	return !(a & b);
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	long long n, m;
	cin >> n >> m;
	long long masks = 1 << m;
	vector<vector<long long>> mtx(1 << 8, vector<long long>(1 << 8));
	for (long long mask = 0; mask < masks; mask++){
		for(long long prev_mask = 0; prev_mask < masks; prev_mask++){
			mtx[prev_mask][mask] = ok(prev_mask,mask) && even_one((~prev_mask) & (masks - 1), (~mask) & (masks - 1));
		}
	}
	vector<long long> prev(masks), cur(masks);
	cur[0] = 1;
	for (long long i = 1; i < n + 1; i++){
		swap(cur, prev);
		fill(cur.begin(), cur.end(), 0);
		for (long long mask = 0; mask < masks; mask++){
			for (long long prev_mask = 0; prev_mask < masks; prev_mask++){
				if (mtx[prev_mask][mask]){
					cur[mask] = (cur[mask] + prev[prev_mask]) % MOD;
				}
			}
		}
	}
	cout << cur[0] << "\n";
	return 0;
}