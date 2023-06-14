#include <iostream>
using namespace std;

int main() {
    int m, n, li, ri;
    cin >> m;
    cin >> n;
    int y = 0, resposta = 0;
    int list[1000][2];
    for(int x = 0; x < n; x++){
        cin >> li >> ri;
        list[x][y] = li;
        list[x][y+1] = ri;        
    }
 
    // ordenar
    for (int y = 0; y < n-1; y++){
        int posMin = y;
        for (int z = y + 1; z < n; z++){
            if(list[z][0] < list[posMin][0]){
                posMin = z;
            }
        }
        // trade
        int temp0 = list[y][0];
        int temp1 = list[y][1];
        list[y][0] = list[posMin][0];
        list[y][1] = list[posMin][1];
        list[posMin][0] = temp0;
        list[posMin][1] = temp1;
    }
    
    int maior = list[0][1], end = 0;
    while(end < m){
        for (int i = 0; i < n; i++){
            if(list[i][0] <= end && list[i][1] > maior){
                maior = list[i][1];
            }
            
        }
        end = maior;
        resposta++;
    }
    cout << resposta << '\n';  
}