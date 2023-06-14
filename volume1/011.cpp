#include <iostream>
#include <algorithm>
using namespace std;

// i = 8
// m = 7
// sum = 10

int isPossible(int max, int v[], int size, int limit){
    int sum = 0, m = 0;
    for (int i = 0; i < size; i++){
        sum = sum + v[i];
        if (sum > max){
            sum = 0;
            m++;
            i--;
        }
        if (m > limit){
            return 0;
        }
    }
    if (m >= limit){
        return 0;
    }
    return 1;
}

int bsearch(int high, int v[], int size, int limit){
    int low = 0;
    while (low < high){
        int mid = low + (high - low)/2;
        if(isPossible(mid, v, size, limit) == 1){
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    if (isPossible(low, v, size, limit) == 0){
        return -1;
    }
    return low;
    
}

int main(){
    int n, d[1000], p, k[1000], sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> d[i];
        sum = sum + d[i];
    }
    cin >> p;
    for(int i = 0; i < p; i++){
        cin >> k[i];
        cout << bsearch(sum, d, n, k[i]) << '\n';
    }
}