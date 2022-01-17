#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int n, m;
    cin >> n >> m;
    if (n % 2 == 1 && m % 2 == 1){
        cout << 2;
    }
    else {
        cout << 1;
    }
}