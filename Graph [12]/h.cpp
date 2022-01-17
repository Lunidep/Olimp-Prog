#include <iostream>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    int mat[1000][1000];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>mat[i][j];
        }
    }
    //--------------------------------------
    
    int k;
    for (int i=0; i<n; i++){
        mat[i][i]=0;
    } 
    for (int k=0; k<n; k++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
    
    //-------------------------------------- 
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<mat[i][j]<<' ';
        }
        cout << '\n';
    }
    cout<<endl;
    return 0;
}