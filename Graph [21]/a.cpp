#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;
using ll = long long;
const int INF = 1e9 + 7;
 
struct DSU {
    vector<int> leaders;
    vector<ll> size;
 
    DSU(ll n) {
        leaders.resize(n);
        iota(leaders.begin(), leaders.end(), 0);
        size.assign(n, 1);
    }
 
    int find(int v) {
        if (leaders[v] == v) {
            return leaders[v];
        }
        return leaders[v] = find(leaders[v]);
    }
 
    ll join(int v, int u) {
        v = find(v);
        u = find(u);
        if (v == u) {
            return size[v];
        }
        if (size[v] < size[u]) {
            leaders[v] = u;
            size[u] += size[v];
            return size[u];
        }
        else{
            leaders[u] = v;
            size[v] += size[u];
            return size[v];
        }
    }
};
 
struct Edge {
    ll from;
    ll to;
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<Edge> graph(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b;
        a--; b--;
        graph[i] = Edge{ a,b };
    }
    DSU edges(n);
    for (const Edge& ed : graph) {
        cout << edges.join(ed.from, ed.to) << endl;
    }
    cout << "\n";
    return 0;
}