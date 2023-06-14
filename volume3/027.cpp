#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 50; // Máximo número de nós
vector<int> graph[MAXN+1]; // Grafo, armazenado em lista de adjacência
int color[MAXN+1]; // Vetor de cores dos nós

bool isBipartite(int n) {
    memset(color, 0, sizeof(color)); // Reseta o vetor de cores
    queue<int> q; // Fila para a BFS
    for (int i = 1; i <= n; i++) {
        if (color[i] != 0) continue; // Se o nó já foi colorido, passa para o próximo
        color[i] = 1; // Define a cor do nó atual como 1
        q.push(i); // Adiciona o nó na fila
        while (!q.empty()) {
            int u = q.front(); q.pop(); // Remove o primeiro nó da fila
            for (int v : graph[u]) {
                if (color[v] == color[u]) return false; // Se o vizinho tem a mesma cor, retorna false
                if (color[v] == 0) { // Se o vizinho ainda não foi colorido
                    color[v] = -color[u]; // Define a cor do vizinho como a oposta ao do nó atual
                    q.push(v); // Adiciona o vizinho na fila
                }
            }
        }
    }
    return true;
}

int main() {
    int t; cin >> t; // Lê o número de casos de teste
    while (t--) {
        int n, m; cin >> n >> m; // Lê o número de nós e arestas do grafo
        for (int i = 1; i <= n; i++) graph[i].clear(); // Limpa o grafo anterior
        while (m--) {
            int u, v; cin >> u >> v; // Lê a aresta
            graph[u].push_back(v); // Adiciona a aresta à lista de adjacência
            graph[v].push_back(u); // O grafo é não-direcionado, então adiciona a aresta inversa também
        }
        if (isBipartite(n)) cout << "sim\n"; // Imprime "sim" se o grafo é bipartido
        else cout << "nao\n"; // Imprime "nao" se o grafo não é bipartido
    }
    return 0;
}
