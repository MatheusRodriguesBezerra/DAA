#include <iostream>
#include <list>
#include <vector>

using namespace std;

int charToInt(char l){
    return int(l)-65;
}

bool find(pair<int,int> valor, vector<pair<int,int>> list){
    for (auto it = list.begin(); it != list.end(); ++it){
        if((valor.first == it->first) && (valor.second == it->second)){
            return true;
        }
    }
    return false;
}

int main() {
    int n, qtde, intOrigem, intDestino;
    char origem, destino;
    bool rotas[26][26];  
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                rotas[i][j] = true;
            }else{            
                rotas[i][j] = false;
            }
        }      
    }   

    for (int i = 0; i < n; i++){
        cin >> origem >> qtde;
        intOrigem = charToInt(origem);
        for (int i = 0; i < qtde; i++){
            cin >> destino;
            intDestino = charToInt(destino);
            rotas[intOrigem][intDestino] = true;
        }        
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if((rotas[i][k] == true) && (rotas[k][j] == true)){
                    rotas[i][j] = true;
                } 
            }            
        }       
    }

    cout << ' ';
    for (int i = 0; i < n; i++){
        cout << ' ' << char(i+65);
    }
    cout << endl;
    

    for(int i = 0; i < n; i++){
        cout << char(i+65);
        for(int j = 0; j < n; j++){
            cout << ' ' << rotas[i][j];
        }      
        cout << endl;
    }
   
    return 0;
}