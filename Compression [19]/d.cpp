#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> x;
 
int compr(int coord){
    return lower_bound(x.begin(), x.end(), coord) - x.begin();
}
 
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
        if (l[i] > r[i]){
            int tmp = l[i];
            l[i] = r[i];
            r[i] = tmp;
        }
        r[i] += 1;
        x.push_back(l[i]);
        x.push_back(r[i]);
    }
    
    
    vector<int> q(m);
    for (int i = 0; i < m; i++){
        cin >> q[i];
        x.push_back(q[i]);
    }
    
    
    
    sort(x.begin(), x.end());
    
    x.resize(unique(x.begin(), x.end()) - x.begin());
    
    
    vector<int> z(x.size()); 
    for (int i = 0; i < n; i++){
        
        z[compr(l[i])] += 1;
        z[compr(r[i])] -= 1;
    }
    
    
    for (int i = 1; i < z.size(); i++){
        z[i] += z[i-1];
    }
    
    for (int pt : q){
        cout <<z[compr(pt)] << ' ';
    }
    
    return 0;
}