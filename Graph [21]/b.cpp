#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;
using ll = long long;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 14;
 
struct DSU {
    vector<ll> leaders;
    vector<ll> min_id;
    vector<ll> max_id;
    vector<ll> sum_id;
    vector<ll> size;
 
    DSU(ll n) {
        leaders.resize(n);
        min_id.resize(n);
        max_id.resize(n);
        sum_id.resize(n);
        size.assign(n, 1);
        iota(leaders.begin(), leaders.end(), 0);
        for (ll i = 0; i < n; i++) {
            min_id[i] = i + 1;
            max_id[i] = i + 1;
            sum_id[i] = i + 1;
        }
    }
 
    ll find(ll v) {
        if (leaders[v] == v) {
            return leaders[v];
        }
        return leaders[v] = find(leaders[v]);
    }
 
    void join(ll v, ll u) {
        v = find(v);
        u = find(u);
        if (v == u) {
            cout << sum_id[v] << " " << min_id[v] << " " << max_id[v] << endl;
            return;
        }
        if (size[v] >= size[u]) {
            ll tmp = u;
            u = v;
            v = tmp;
        }
        //cout << sum_id[u] << " " << min_id[u] << " " << max_id[u] << endl;////////////////////
        leaders[v] = find(u);
        size[u] = (size[u] + size[v]) % LINF;
        sum_id[u] = (sum_id[u] + sum_id[v]) % LINF;
        min_id[u] = min(min_id[u], min_id[v]);
        max_id[u] = max(max_id[u], max_id[v]);
        cout << sum_id[u] << " " << min_id[u] << " " << max_id[u] << endl;
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
        edges.join(ed.from, ed.to);
    }
    cout << "\n";
    return 0;
}