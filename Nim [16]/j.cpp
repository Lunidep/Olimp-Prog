
#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int n, m, l, r, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i ++){
        cin >> l >> r;
        ans ^= (r - l - 1);
    }
    
    if (ans == 0){
        cout << 2 << ' ' << 2;
    }
    else{
        cout << 1 << ' ' << 1;
    }
    
    return 0;
}