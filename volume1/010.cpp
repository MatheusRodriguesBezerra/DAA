#include <iostream>
#include <algorithm>
using namespace std;

void bsearch(int v[1000000], int key, int size){
    int low = 0;
    int high = size - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if (v[mid] == key) {
            cout << v[mid];
            return;
        }
        else if (v[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    if(v[0] > key){
        cout << v[0];
        return;
    }
    if(v[size-1] < key){
        cout << v[size - 1];
        return;
    }

    int diff1 = abs(v[high] - key);
    int diff2 = abs(v[low] - key); 

    if(diff1 == diff2){
        cout << v[high] << ' ' << v[low];
        return;
    }
    else if(diff1 > diff2){
        cout << v[low];
        return;
    }
    else{
        cout << v[high];
        return;
    }
}

int main(){
    int n, x, novonum, q[2000], v[1000], somas[1000000], a = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            novonum = v[i] + v[j];
            somas[a] = novonum;
            a = a + 1;
        }       
    }

    sort(somas, somas + a);
    
    cin >> x;

    for(int i = 0; i < x; i++) {
        cin >> q[i];
    }

    for(int i = 0; i < x; i++) {
        bsearch(somas, q[i], a);
        cout << '\n';
    }
    return 0;
}