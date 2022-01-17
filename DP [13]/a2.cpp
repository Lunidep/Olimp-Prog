#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
const int INF = 1e9 + 8;
using namespace std;
 
int dp(int last, int mask, vector<vector<int>>& mtx, vector<vector<int>>& memo, int n){
    if (memo[last][mask] != -1){
        return memo[last][mask];
    }
 
    int prev_mask = mask ^ (1 << last);
    if (prev_mask == 0) return 0;
 
    int result = INF;
 
    for (int prev = 0; prev < n; prev++){
        if (prev_mask & (1 << prev)){
            result = min(result, dp(prev, prev_mask, mtx, memo, n) + mtx[last][prev]);
        }
    }
    if (result == INF) return memo[last][mask] = 0;
    return memo[last][mask] = result;
}
 
int main(){
 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
    int n;
    cin >> n;
 
    vector<vector<int>> memo(n, vector<int>(((1 << n)), -1));
    vector<vector<int>> mtx(n, vector<int> (n));
 
    for (int i = 0; i < n; i++){
        memo[i][1 << i] = 0;
    }
 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mtx[i][j];
        }
    }
 
    cout << dp(0, (1 << n) - 1, mtx, memo, n) << '\n';
	return 0;
}
