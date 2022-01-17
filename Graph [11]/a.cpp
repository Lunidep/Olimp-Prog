#include <iostream>
#include <vector>
using namespace std;
 
int i = 0;
 
void bfs(int v, const vector<vector<long long>>& graph, vector<int>& used) {
	if (used[v] != -1) {
		return;
	}
	used[v] = i;
	i++;
	for (int to : graph[v]) {
		bfs(to, graph, used);
	}
}
 
int main() {
	int n, m, k, a, b;
	cin >> n >> m >> k;
	k--;
	//_____________________________________________________
	vector<vector<long long>> graph(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	//_____________________________________________________
	vector<int> used(n, -1);
	bfs(k, graph, used);
	for (int i = 0; i < n; i++) {
		cout << used[i] << " ";
	}
	cout << "\n";
	return 0;
}