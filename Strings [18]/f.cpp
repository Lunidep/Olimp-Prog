#include <iostream>
#include <vector>
 
using namespace std;
 
vector<int> z_function(string s){
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; i++){
        if (i <= r){    
            z[i] = min(r - i + 1, z[i - l]);
        }
        
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        
        if (i + z[i] - l > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    
    return z;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    string s;
    cin >> s;
    
    vector<int> z = z_function(s);
    
    for (int i = 1; i < z.size(); i++){
        //cout << z[i] << " ";
        
        if (z[i] + i == s.size() && s.size() % i == 0){
            cout << i;
            return 0;
        }
        
    }
    cout << s.size();
    return 0;
}