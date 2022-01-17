#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int i = 0;
 
void bfs(int st, const vector<vector<long long>>& graph, vector<int>& dist) {
    dist.assign(graph.size(), -1);
    queue<int> q;
    q.push(st);
    dist[st] = 0;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int to: graph[v]){
            if (dist[to] != -1){
                continue;
            }
            dist[to] = dist[v] + 1;
            q.push(to);
        }
    }
}
 
int main() {
	int n, m, v, a, b;
	cin >> n >> m >> v;
	v--;
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
	vector<int> dist(n);
	bfs(v, graph, dist);
	
	for (int u: dist) {
		cout << u << " ";
	}
	cout << "\n";
	return 0;
}