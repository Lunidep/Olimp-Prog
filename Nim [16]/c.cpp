#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9 + 7;
const long long LINF = 1e17 + 7;
 
int mex(vector<int>& next) {
    sort(next.begin(), next.end());
    if ((next.empty()) || (next[0] != 0)) {
        return 0;
    }
    for (int i = 1; i < next.size(); i++) {
        if (next[i - 1] + 1 < next[i]) {
        return next[i - 1] + 1;
        }
    }
    return next.back() + 1;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> sg(n + 1);
    
    for (int i = 1; i <= n; i++) {
        vector<int> next;
        for (int j = 0; j <= i / 2; j++) {
            next.push_back(sg[max(0, j - 1)] ^ sg[max(0, i - j - 2)]);
        }
        sg[i] = mex(next);
    }
    /*
    cout << "\n";
    for (int i : sg){
        cout << i << " ";
    }
    cout << "\n";
    */
    cout << (sg[n] ? 1 : 2) << endl;
    return 0;
}