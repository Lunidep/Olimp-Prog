#include <iostream>
#include <vector>
#include <algorithm>
 
int const INF = 1e9 + 7;
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int k = 0; k < q; k++) {
        int s;
        cin >> s;
        s--;
        vector<int> d(n, INF);
        vector<bool> used(n);
        int min_dist = 0;
        int index = s;
        d[s] = 0;
        while (min_dist < INF) {
            int i = index;
            used[i] = true;
            for (int j = 0; j < n; j++) {
                if (d[i] + a[i][j] < d[j]) {
                    d[j] = d[i] + a[i][j];    
                }
            }
            min_dist = INF;
            for (int j = 0; j < n; j++) {
                if (!used[j] && d[j] < min_dist) {
                    min_dist = d[j];
                    index = j;
                }
            }
        }
        for (int v: d) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
