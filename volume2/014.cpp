#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(pair<int, float> a, pair<int, float> b) {
    if (a.second != b.second) {
        return a.second > b.second; // Ordena por valor (decrescente)
    }
    return a.first < b.first; // Se houver empate, ordena por índice (crescente)
}

int main() {
    int n;
    float result, mi , di;
    cin >> n; // Tamanho da matriz
    vector<pair<int, float>> Sapatos(n);

    // Leitura da matriz
    for (int i = 0; i < n; i++) {
        cin >> mi >> di;
        Sapatos[i].first = i + 1;
        result = di / mi;
        Sapatos[i].second = result;
    }

    // Ordenação
    sort(Sapatos.begin(), Sapatos.end(), compare);

    // Impressão da matriz ordenada
    for (int i = 0; i < n-1; i++) {
        cout << Sapatos[i].first << ' ';
    }
    cout << Sapatos[n-1].first << '\n';

    return 0;
}







// int main() {
//     int n;
//     float di, mi, result;
//     Sapatos list[1000];
//     cin >> n;
//     for(int x = 0; x < n; x++){
//         cin >> di >> mi;
//         result = mi / di;
//         list[x].index = x + 1;
//         list[x].value = result;
//     }

    
//     for (int y = 0; y < n-1; y++){
//         int posMin = y;
//         for (int z = y + 1; z < n; z++){
//             if(list[z].value < list[posMin].value){
//                 posMin = z;
//             }
//         }
//         // trade
//         Sapatos temp = list[y];
//         list[y] = list[posMin];
//         list[posMin] = temp;
//     }
    
//     for (int i = 0; i < n; i++){
//         cout << list[i].index << '\n';
//         cout << list[i].value << '\n';
//     }
//     // ordenar
//     // for (int y = 0; y < n-1; y++){
//     //     int posMin = y;
//     //     for (int z = y + 1; z < n; z++){
//     //         if(list[z][0] < list[posMin][0]){
//     //             posMin = z;
//     //         }
//     //     }
//     //     // trade
//     //     int temp0 = list[y][0];
//     //     int temp1 = list[y][1];
//     //     list[y][0] = list[posMin][0];
//     //     list[y][1] = list[posMin][1];
//     //     list[posMin][0] = temp0;
//     //     list[posMin][1] = temp1;
//     // }
    

//     return 0;
 
// }