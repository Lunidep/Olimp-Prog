#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
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
 
int main()
{
    int n;
    cin >> n;
    n+=1;
    vector<int> sg(n+1);
    
    for (int i = 1; i <= n; i++){
        vector<int> next;
        for (int j = 1; j < i/2; j++){
            next.push_back(sg[j+1] ^ sg[i - j]);
        }
        sg[i] = mex(next);
    }
    
    cout << (sg[n] ? 1 : 2) << endl;
    return 0;
}