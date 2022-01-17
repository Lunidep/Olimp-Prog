#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
const int INF = 1e9 + 7;
 
struct Edge {
    int to, from, cost;
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    
    vector<Edge> E(2*m);
    int i = 0;
    int to, from, cost;
    for (Edge& e : E) {
        if (i == 0) {
            cin >> to >> from >> cost;
            e.to = to;
            e.from = from;
            e.cost = cost;
            i = 1;
        }
        else {
            e.to = from;
            e.from = to;
            e.cost = cost;
            i = 0;
        }
        e.to--; e.from--;
    }
    //______________________________________________________________________________
    vector<int> d(n, INF);
    d[s] = 0;
    
    for (int i = 0; i < n; i++){
        bool ok = false;
        for (Edge& e: E){
            if (d[e.to] == INF) {
                continue;
            }
            if (d[e.from] > d[e.to] + e.cost) {
                ok = true;
                d[e.from] = d[e.to] + e.cost;
            }
        }
        if (ok == false){
            break;
        }
    }
    //______________________________________________________________________________
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