#include <iostream>
using namespace std;
#define MAX 200000

int main() {
    int n1, n2, energy, a, b;
    int l1[MAX];
    cin >> n1;
    l1[0] = 0;
    for(int i = 1; i < n1+1; i++){
        cin >> energy;
        l1[i] = l1[i-1] + energy;
    }
    
    cin >> n2;
    for (int i = 0; i < n2; i++){
        cin >> a >> b;
        cout << l1[b]-l1[a-1] << '\n';
    }
    return 0;
    
}