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
 
    bool join(int v, int u) {
        v = find(v);
        u = find(u);
        if (v == u) {
            return false;
        }
        if (size[v] < size[u]) {
            leaders[v] = find(u);
            size[u] = (size[u] + size[v]) % LINF;
        }
        else{
            leaders[u] = find(v);
            size[v] = (size[u] + size[v]) % LINF;
        }
        return true;
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
    vector<int> ans(m);
    /////////////////////////////////
    /*
    for (int i : ans){
        cout >> i >> ' ';
    }
    */
    //////////////////////////////////
    int k = n;
    for (int i = m - 1; i >= 0; i--) {
        Edge ed = graph[i];
        ans[i] = k;
        if (edges.join(ed.from, ed.to)) {
            k--;
        }
    }
    for (const int ed : ans) {
        cout << ed << "\n";
    }
    cout << "\n";
    return 0;
}