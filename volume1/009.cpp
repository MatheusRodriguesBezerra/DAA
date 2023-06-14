#include <iostream>
#include <algorithm>
using namespace std;

// typedef struct{
//     int letter;
//     int value;
//     int index;
// } Tuplo;

class Tuplo{
    public:
        int letter;
        int value;
        int index; 
};

bool compare(Tuplo x, Tuplo y){
    if(x.value != y.value){
        return x.value < y.value;
    }
    return x.index > y.index;
}

int main() {
    string str;
    cin >> str;
    int sum[26], n, add;
    n = str.length();
    Tuplo sum2[26];
    int a=65;
    for (int j = 0; j < 26; j++){
        sum2[j].letter = 0;
        sum2[j].value = 0;
        sum2[j].index = -1;
        sum[j] = 0;
    }
    
    for (int i = 0; i < n; i++){
        add = int(str[i]) - 65;
        sum[add]++;
        if(sum2[add].index == -1){
            sum2[add].index = i;
        }
    }

    for(int i = 0; i < 26; i++){
        sum2[i].letter = a+i;
        sum2[i].value = sum[i];
    }
    
    sort(sum2, sum2+26, compare);
    // for (int y = 0; y < 25; y++){
    //     int posMin = y;
    //     for (int z = y + 1; z < 26; z++){
    //         if(sum2[z][1] < sum2[posMin][1]){
    //             posMin = z;
    //         }
    //     }
    //     // trade
    //     int temp0 = sum2[y][0];
    //     int temp1 = sum2[y][1];
    //     sum2[y][0] = sum2[posMin][0];
    //     sum2[y][1] = sum2[posMin][1];
    //     sum2[posMin][0] = temp0;
    //     sum2[posMin][1] = temp1;
    // }

    for (int i = 25; i >= 0; i--){
        if(sum2[i].value > 0){ 
            cout << char(sum2[i].letter) << ' ' << sum2[i].value << '\n';
        }
    }
    

    // for (int i = 0; i < 26; i++){
    //     cout << sum2[i][0] << ' ' << sum2[i][1] << '\n';
    // }
    
    
    
    
    
    return 0; 
}