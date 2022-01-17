#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
using ll = long long;
 
bool dfs(int u, int v, const vector<vector<int>>& graph, vector<int>& used, vector<int>& ans)
{
    if (used[u] == 1) {
        return false;
    }
    used[u] = 1;
    if (u == v) {
        ans.push_back(v + 1);
        return true;
    }
    for (int to: graph[u]) {
        if (dfs(to, v, graph, used, ans)) {
            ans.push_back(u + 1);
            return true;
        }
    }
    return false;
}
 
int main()
{
    int n, m, u, v;
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
    vector<int> used(n, 0);
    vector<int> ans;
    dfs(u, v, graph, used, ans);
    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        reverse(ans.begin(), ans.end());
        for (auto t: ans) {
            cout << t << " ";
        }
        cout << endl;
    }
    return 0;
}