#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int a, b;
	cin >> a >> b;
	vector<ll> count(a + 2);
	count[0] = 1;
	ll ans = 0;
	ll end = 0;
	for (int j = 1; j <= a; j++) {
		for (int i = 1; i <= j; i++) {
			ans += (count[i - 1] * count[j - i]) % b;
		}
		count[j] = ans % b;
		ans = 0;
	}
	cout << count[a] % b;
	cout << '\n';
	return 0;
}