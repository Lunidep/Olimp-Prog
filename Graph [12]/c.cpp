#include <iostream>
#include <vector>
#include <queue>
#include <set>
 
using namespace std;
 
const long long INF = 1e20 + 7;
 
struct Edge {
    int to, cost;
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    
    using Graph = vector<vector<Edge>>;
    Graph graph(n);
    for (int i = 0; i < m; i ++){
        long long a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        graph[a].push_back(Edge{b, c});
        graph[b].push_back(Edge{a, c});
    }
    //----------------------------------------------------------
    vector<long long> d(n, INF);
    d[s] = 0;
    
    set<pair<long long, long long>> st;
    st.insert({0,s});
    
    while (!st.empty()){
        auto [dist, u] = *st.begin();
        st.erase(st.begin());
        
        for (auto [to, cost]: graph[u]){
            if (d[to] > d[u] + cost){
                st.erase({d[to], to});
                d[to] = d[u] + cost;
                st.insert({d[to], to});
            }
        }
    }
    //----------------------------------------------------------  
    for (int i = 0; i < n; i++){
        if (d[i] == INF){
            cout << -1 << ' ';
        }
        else{
            cout << d[i] << ' ';
        }
    }
    cout << '\n';
    return 0;
}