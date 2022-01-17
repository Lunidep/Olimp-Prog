#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int global = 0 ;
int g = 0;
 
bool dfs(int v, int par, const vector<vector<int>>& graph, vector<int>& color, vector<int>& ans) {
    if (color[v] == 1) {
        ans.push_back(v);
        global = 1;
        g = v;
        return true;
    }
    if (color[v] == 2) {
        return false;
    }
    color[v] = 1;
    for (int to: graph[v]) {
        if (to != par && dfs(to, v, graph, color, ans)) {
            if (v == g) {
                global = 0;
            }
            if (global == 1) {
                ans.push_back(v);
            }
            return true;
            
        }
    }
    color[v] = 2;
    return false;
}
 
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> color(n);
    vector<int> ans;
    dfs(0, 0, graph, color, ans);
    sort(ans.begin(), ans.end());
    for (auto t: ans) {
        cout << t + 1 << " ";
    }
    cout << endl;
    return 0;
}