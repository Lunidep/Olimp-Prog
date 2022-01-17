#include <iostream>
#include <vector>
using namespace std;
 
void dfs(int v, vector<vector<int>>& G, vector<bool>& used, vector<int>& dist, vector<int>& path){
    if (used[v])
        return;
    used[v] = 1;
    for (int to: G[v]){
        dfs(to, G, used, dist, path);
        
        if (dist[to] >= dist[v]){
            dist[v] = dist[to] + 1;
            path[v] = to;
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
    }
    
    vector<bool> used(n);
    vector<int> dist(n);
    vector<int> path(n, -1);
    
    for (int i = 0; i < n; i ++){
        if (!used[i]){
            dfs(i, G, used, dist, path);
        }
    }
    
    int mx = -1;
    int ind = 0;
    for (int i = 0; i < n; i++){
        if (dist[i] > mx){
            mx = dist[i];
            ind = i;
        }
    }
    
    cout << mx + 1 << endl;
    for (int i = ind; i != -1; i = path[i]){
        cout << i + 1 << ' ';
    }
    
    return 0;
}