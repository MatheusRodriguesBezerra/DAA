#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define MAX 10

class msg{
    public:
        string txt;
        int len;
};

bool isIn(string m, char l){
    for (int k = 0; k < (int)m.length(); k++){
        if (m[k] == l){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    string pi, result = "";
    msg mensage[MAX]; 
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> pi;
        mensage[i].txt = pi;
        mensage[i].len = pi.length();
    }

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < n; j++){
            if(i > mensage[j].len){
                break;
            }
            if((!(isIn(result, mensage[j].txt[i]))) && (mensage[j].txt[i] >= 'A') && (mensage[j].txt[i] <= 'Z')){
                result = result + mensage[j].txt[i];
            }           
        }
    }

    cout << result << endl;
    return 0;
}