#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
const int INF = 1e9+7;
 
ll bin_pow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1)
            res = (res * a) % INF;
        a = (a * a) % INF;
        n /= 2;
    }
    return res % INF;
}
 
ll Hash(string s) {
    ll result = 0;
    for (ll i = 0; i < s.size(); ++i) {
        result = (result * 31 + s[i] - 'a' + 1) % INF;
    }
    return result % INF;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s, c;
    ll s_h, c_h;
    c_h = 0;
    ll cnt = 0;
    cin >> s >> c;
    s_h = Hash(s);
    for (int i = 0; i < c.size(); i++) {
        if (i >= s.size()) {
            c_h = ((c_h - bin_pow(31, s.size() - 1) * (c[i - s.size()] + 1 - 'a') ) % INF + INF) % INF;
        }
        c_h = (c_h * 31 + c[i] - 'a' + 1) % INF;
        if (i >= s.size() - 1) {
            if (s_h == c_h) {
                cnt++;
            }
        }
    }
    cout << cnt;
}