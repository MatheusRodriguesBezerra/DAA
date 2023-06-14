#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, d, ci, pi;
    int long mat[1000][1000];
    cin >> n;
    cin >> d;
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < n+1; j++){
            mat[j][i] = 1;
        }
    }

    for (int i = 0; i < d; i++){
        cin >> ci >> pi;
        mat[ci-1][pi-1] = 0;
    }

    for (int i = 1; i < n+1; i++) {
        for (int j = 0; j < (abs(i-n)); j++) {
            if (mat[i][j] == 0){
    
            }else{
                mat[i][j] = mat[i-1][j] + mat[i-1][j+1];
            }   
        }   
    }
    cout << mat[n-1][0] << '\n';

    return 0;
}