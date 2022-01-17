#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
 
using namespace std;
 
bool dfs(vector<vector<int>>& g, vector<int>& match,vector<bool>& used, int cur){
    if (used[cur]){
        return false;
    }
    used[cur] = true;
    for (int to: g[cur]){
        if (match[to] == -1 || dfs(g, match, used, match[to])){
            match[to] = cur;
            return true;
        }
    }
    return false;
}
 
int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    
    /*
    for (int i = 0; i < n+1; i++){
        for (int j : g[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
    */
    
    int ans = 0;
    vector<int> match(n+1, -1);
    vector<bool> used(n+1);
    for (int i = 0; i < n+1; i++){
        used.assign(n+1, false);
        if (dfs(g, match, used, i)){
            ans++;
        }
    }
    cout << ans << "\n";
    /*
    for (int i : match){
        cout << i<< " ";
    }
    cout << "\n";
    */
    
    for (int i = 0; i < n+1; i++){
        if (match[i] != -1){
            cout << match[i] << " " << i << "\n";
        }
    }
    
    return 0;
}