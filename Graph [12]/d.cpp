#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
 
using namespace std;
 
long long const INF = 1e14 + 7;
 
struct Edge {
    int to, c;
};
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> G(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    vector<long long> d(n, INF);
    vector<bool> used(n);
    vector<int> p(n);
    vector<int> path;
    d[0] = 0;
    set<pair<int, int>> st;
    st.insert({0, 0});
    while (!st.empty()) {
        auto [dist, u] = *st.begin();
        st.erase(st.begin());
        for (auto [to, cost]: G[u]) {
            if (d[to] > d[u] + cost) {
               st.erase({d[to], to});
               d[to] = d[u] + cost;
               p[to] = u; 
               st.insert({d[to], to});
            }
        }
    }
    if (d[n - 1] == INF) {
        cout << -1 << endl;
    } else {
        for (int v = n - 1; v != 0; v = p[v]) {
            path.push_back(v);
        }
        path.push_back(0);
        reverse(path.begin(), path.end());
        for (auto a: path) {
            cout << a + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}