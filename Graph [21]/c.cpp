#include <iostream>
#include <string>
#include <vector>
#include <set>
 
using namespace std;
using ll = long long;
 
const ll LINF = 1e18 + 14;
#define endl '\n'
 
struct Edge {
    ll to;
    ll weight;
};
 
bool operator<(const Edge& a, const Edge& b){
    if (a.weight != b.weight){
        return a.weight < b.weight;
    }
    return a.to < b.to;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    ll n, m;
    cin >> n >> m;
    
    vector<vector<Edge>> graph(n);
    
    for (ll  i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back(Edge{b, c});
        graph[b].push_back(Edge{a, c});
    }
    
    ll total = 0;
    vector<ll> used(n);
    used[0] = 1;
    set<Edge> edges(graph[0].begin(), graph[0].end());
    
    while (!edges.empty()){
        Edge v = *edges.begin();
        edges.erase(edges.begin());
        
        if (used[v.to]){
            continue;
        }
        used[v.to] = 1;
        total += v.weight;
        
        for (const Edge& next: graph[v.to]){
            if (!used[next.to]){
                edges.insert(next);
            }
        }
    }
    
    cout << total;
    
    return 0;
}