#include <iostream>
using namespace std;

int sum(int x){
    int soma = 0;
    while (x>=10){
        soma += x % 10;
        x = x / 10;
    }
    soma = soma + x;
    return soma;
}

int main() {
    int n,k,t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        n = n + 1;
        while (sum(n) != k){
            n++;
        }  
        cout << n << '\n';      
    }
}

