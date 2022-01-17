#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
 
const int INF = 1e9 + 7;
 
vector<ll> pr;
vector<ll> sg;
 
void preparation(ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if(n % i != 0){
            continue;
        }
        pr.push_back(i);
        sg.push_back(0);
        while (n % i == 0) {
            sg.back() += 1;
            n /= i;
        }
    }
    if (n > 1) {
        pr.push_back(n);
        sg.push_back(1);
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    ll n, res = 0;
    cin >> n;
    preparation(n);
    /*
    for (ll i : pr){
        cout << i;
    }*/
    //cout << endl;
    for (ll i : sg) {
        res ^= i;
        //cout << i;
    }
    //cout << endl;
    cout << (res ? 1 : 2) << endl;
    return 0;
}