#include <iostream>
using namespace std;

int main() {
    int n, di, mi;
    int list[1000][2];
    cin >> n;
    for(int x = 0; x < n; x++){
        cin >> di >> mi;
        list[x][0] = di;
        list[x][1] = mi;        
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
    

    return 0;
 
}