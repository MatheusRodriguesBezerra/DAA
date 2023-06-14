#include <iostream>
using namespace std;

#define MAX 25

int n;              // Numero de nos do grafo
bool adj[MAX][MAX]; // Matriz de adjacencias
bool visited[MAX];  // Que nos ja foram visitados?

void dfs(int v) {
    visited[v] = true;
    for (int i=1; i<=n; i++){
        if (adj[v][i] && !visited[i]){
            dfs(i);
        }
    }
}

int main() {
    int edges, a, b;
    int sum = 0;
    cin >> n;
    cin >> edges;

    for (int i = 0; i < MAX; i++){
        visited[i] = false;
    }

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            adj[i][j] = false;
        }
    }
    

    for (int i=0; i<edges; i++) {
        cin >> a >> b;
        adj[a][b] = adj[b][a] = true;
    }

    for (int i = 1; i < n; i++){
        if(edges == 0){
            sum = n;
            break;
        }
        if(!visited[i]){
            ++sum;
            dfs(i);
        }  
        
    }
    
    cout << sum << endl;
    
    return 0;
}