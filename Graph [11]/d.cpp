#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
     
    using namespace std;
     
void bfs(int st, const vector<vector<int>>& graph, vector<int>& dist, vector<int>& ans) {
    dist.assign(graph.size(), -1);
    queue<int> q;
    q.push(st);
    dist[st] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to: graph[v]) {
            if (dist[to] != -1) {
                continue;
            }
            ans[to] = v;
            dist[to] = dist[v] + 1;
            q.push(to);
        }
    }
}
     
int main()
{
    int n, m, v, u;
    cin >> n >> m >> u >> v;
    u--;
    v--;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
 
    }
    for (auto t: graph) {
        sort(t.begin(), t.end());
    }
    vector<int> dist(n);
    vector<int> ans(n, -1);
    bfs(v, graph, dist, ans);
    if (dist[u] == -1) {
        cout << "-1" << endl;
        return 0;
    }
    for (int cur = u; cur != -1; cur = ans[cur]) {
        cout << cur + 1 << " ";
    }
    cout << endl;
    return 0;
}