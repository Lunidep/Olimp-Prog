#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
        ans ^= v[i];
    }
    if (ans == 0){
        cout << 2;
    }
    else{
        cout << 1;
    }
    return 0;
}