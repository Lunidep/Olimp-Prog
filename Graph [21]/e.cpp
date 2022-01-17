#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;
using ll = long long;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 14;
 
void bfs(vector<vector<char>>& graph, int i, int j, int n, int m, char t) {
    if ((i < 0) || (j < 0) || (i >= n) || (j >= m)) {
        return;
    }
    if (graph[i][j] == '#') {
        return;
    }
    if (graph[i][j] != '#' && graph[i][j] != '.') {
        return;
    }
    if (graph[i][j] == '.') {
        graph[i][j] = t;
    }
    bfs(graph, i - 1, j, n, m, graph[i][j]);
    bfs(graph, i + 1, j, n, m, graph[i][j]);
    bfs(graph, i, j - 1, n, m, graph[i][j]);
    bfs(graph, i, j + 1, n, m, graph[i][j]);
}
 
struct s{
    char a;
    bool b;
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> graph(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] != '#' && graph[i][j] != '.') {
                bfs(graph, i - 1, j, n, m, graph[i][j]);
                bfs(graph, i + 1, j, n, m, graph[i][j]);
                bfs(graph, i, j - 1, n, m, graph[i][j]);
                bfs(graph, i, j + 1, n, m, graph[i][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }
    cout << "\n";
    return 0;
}