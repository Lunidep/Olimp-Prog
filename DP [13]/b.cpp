#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
const int INF = 1e9 + 8;
const int INFX = 1e9 + 7;
 
int n = 0;
 
int dp(int last, int mask, vector<vector<int>>& mtx, vector<vector<int>>* memo) {
    if ((*memo)[last][mask] < INF)
        return (*memo)[last][mask];
    for (int i = 0; i < n; i++){
        if ((1 << i) & mask){
            (*memo)[last][mask] = min((*memo)[last][mask], dp(i, mask - (1 << i), mtx, memo) + mtx[last][i]);
        }
    }
    if ((*memo)[last][mask] >= INF)
        (*memo)[last][mask] = INFX;
    return (*memo)[last][mask];
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<vector<int>> mtx(n, vector<int>(n));
    vector<vector<int>> *memo = new vector<vector <int>>(n, vector<int>((1 << n), INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mtx[i][j];
        }
    }
    (*memo)[0][0] = 0;
    cout << dp(0, (1 << n) - 1, mtx, memo);
    return 0;
}