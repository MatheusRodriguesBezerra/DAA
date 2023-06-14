#include <iostream>
using namespace std;

int main() {
    int n,x;
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if(x == 42){
            count = count + 1;
        }       
    }
    cout << count << '\n';
}