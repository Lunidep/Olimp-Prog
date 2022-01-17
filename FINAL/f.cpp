#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;
const int INF = 1e9 + 7;
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n, a, b;
    cin >> n;
    if (n % 2 == 0){
        cout << n+1 << ' ' << n/2;
    }else{
        cout << (n+1)/2 << ' ' << n;
    }
}