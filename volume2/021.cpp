#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

#define MAX 100000

int main(){
    int A, R, E;
    string li;
    multiset<int> v;
    cin >> A >> R;
    for(int i = 0; i < (A+R); i++){
        cin >> li;
        if(li == "BAK"){
            cin >> E;
            v.insert(E);
        }else if(li == "MIN"){
            // cout << "ELEMENT\n";
            // for (auto itr = v.begin(); itr != v.end(); ++itr) {
            //     cout << *itr << '\n';
            // }
            // first = *v.begin();
            cout << *v.begin() << '\n';
            v.erase(v.begin());
        }else{
            // cout << "ELEMENT\n";
            // for (auto itr = v.begin(); itr != v.end(); ++itr) {
            //     cout << *itr << '\n';
            // }
            cout << *v.rbegin() << '\n';
            v.erase(--v.end());
        }
        
    }
    return 0;
    
}