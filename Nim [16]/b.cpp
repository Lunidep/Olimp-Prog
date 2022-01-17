#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int m, n, k, ans = 0;
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> n >> k;
        ans ^= n % (k + 1);
    }
    //cout << ans;
    if (ans == 0){
        cout << 2;
    }
    else{
        cout << 1;
    }
    return 0;
}