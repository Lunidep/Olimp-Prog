#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
const int INF = 1e9 + 7;
 
struct Edge {
    int to, cost;
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    
	vector<vector<Edge>> G(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		G[a].push_back({ b,c });
		G[b].push_back({ a,c });
	}
	vector<int> d(n, -1);
	d[s] = INF;
	priority_queue <pair<int, int>> q;
	q.push(make_pair(0, s));
	while (!q.empty()) {
		int v = q.top().second, cur_d = q.top().first;
		q.pop();
		for (Edge e: G[v]) {
			int to = e.to, len = e.cost;
			if (min(d[v],len) > d[to]) {
				d[to] = min(d[v],len);
				q.push({ d[to], to });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (d[i] == INF) {
			cout << -1 << ' ';
		}else {
			if (i == s) {
				cout << -1 << " ";
				continue;
			}
			if (d[i] == -1) {
				cout << 0 << " ";
				continue;
			}
			cout << d[i] << ' ';
		}
	}
	cout << '\n';
	return 0;
}