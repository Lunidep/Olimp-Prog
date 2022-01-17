#include <iostream>
#include <vector>
#include <queue>
#include <set>
 
using namespace std;
 
const long long INF = 1e9 + 7;
 
int all_per(int v, int len, vector<vector<int>>& graph, vector<bool> used){
    int n = graph.size();
    used[v] = true;
    
    bool full = true;
    for (bool el: used){
        full = full && el;
    }
    if (full){
        return  len;
    }
    int res = INF;
    for(int to = 0; to < n; to++){
        if(used[to]){
            continue;
        }
        res = min(res, all_per(to, len+graph[v][to], graph, used));
    }
    return res;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<vector<int>> graph(n,vector<int>(n));
    vector<bool> used(n);
    
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    /*
    //--------------------------------------------
    
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j++){
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
    
    */
    //--------------------------------------------
    cout << all_per(0, 0, graph, used);
    
    return 0;
}