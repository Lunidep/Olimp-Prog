#include <iostream>
#include <vector>
 
using namespace std;
#define endl '\n'
 
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
 
string rev (string str){
    char temp;
    int len;
 
    len = str.size() - 1;
 
    for (int i = 0; i <= len / 2; i++)
    {
        temp = str[i];
        str[i] = str[len - i];
        str[len - i] = temp;
    }
    return str;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    string s, m, t;
    cin >> s;
    
    int ans = 0, per;
    
    for (int i = 0; i < s.size(); i++){
        
        per = 0;
        
        m = m + s[i];
        t = rev(m);
        //cout << t << endl;
        
        vector<int> zf = z_function(t);
        for (int j = 1; j < zf.size(); j++){
            //cout << zf[j] << ' ';
            
            if (zf[j] > per){
                per = zf[j];
                
            }
            
        }
        //cout << endl << per << endl;
        //cout << endl;
        ans += i - per + 1;
        
    }
    cout << ans << endl;
    
    
    
    return 0;
}