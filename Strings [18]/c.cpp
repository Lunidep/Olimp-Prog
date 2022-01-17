#include <iostream>
#include <vector>
 
using namespace std;
 
vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> p(n);
    for (int i = 1; i < n; i++){
        int tmp = p[i - 1];
        while (tmp > 0 && s[tmp] != s[i]){
            tmp = p[tmp - 1];
        }
        if (s[tmp] == s[i]){
            p[i] = tmp + 1;
        }
    }
    
    return p;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    string s, m;
    cin >> m >> s;
    
    int count = 0, n = s.size();
    
    vector<int> pf = prefix_function(s + '#' + m);
    
    for (int a: pf){
        
        if (a == n){
            count++;
        }
    }
    
    if (count){
        cout << "TAK" << "\n" << count;
    }
    else{
        cout << "NIE";
    }
    
    
    return 0;
}
