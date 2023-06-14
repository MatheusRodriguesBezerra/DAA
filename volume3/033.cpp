#include <iostream>
#include <climits>
#include <list>
#include <set>
#include <vector>
#include <string>

using namespace std;

// Classe que representa um no
class Node {
    public:
        list<pair<int, float>> adj;  // Lista de adjacencias
        bool visited;              // No ja foi visitado?
        float distance;              // Distancia ao no origem da pesquisa
};

// Classe que representa um grafo
class Graph {
public:
    int n;          // Numero de nos do grafo
    Node *nodes;    // Array para conter os nos

    Graph(int n) { // Constructor: chamado quando um objeto Graph for criado
        this->n = n;
        nodes = new Node[n+1];  // +1 se os nos comecam em 1 ao inves de 0
    }
    
    ~Graph() { // Destructor: chamado quando um objeto Graph for destruido
        delete[] nodes;
    }
    
    void addLink(int a, int b, float c) {
        nodes[a].adj.push_back({b,(float)c});
    }

    // Algoritmo de Dijkstra
    void dijkstra(int s, int obj) {
        
        //Inicializar nos como nao visitados e com distancia infinita
        for (int i=1; i<=n; i++) {
            nodes[i].distance = INT_MAX;
            nodes[i].visited  = false;
        }
        
        // Inicializar "fila" com no origem
        nodes[s].distance = 0.0;
        set<pair<float, int>> q; // By "default" um par e comparado pelo primeiro elemento 
        q.insert({0.0, s});      // Criar um par (dist=0, no=s)

        // Ciclo principal do Dijkstra
        while (!q.empty()) {
        
            // Retirar no com menor distancia (o "primeiro" do set, que e uma BST)
            int u = q.begin()->second;
            q.erase(q.begin());
            nodes[u].visited = true;

            // Relaxar arestas do no retirado
            for (auto edge : nodes[u].adj) {
                float v = edge.first;
                float cost = edge.second;
                if (!nodes[(int)v].visited && nodes[u].distance + cost < nodes[(int)v].distance) {
                    q.erase({nodes[(int)v].distance, v});  // Apagar do set
                    nodes[(int)v].distance = nodes[u].distance + cost;
                    q.insert({nodes[(int)v].distance, v}); // Inserir com nova (e menor) distancia
                }
            }
        }
        cout << nodes[obj].distance << endl;
    }
};

int find(const vector<pair<int, string>>& vec, const string& target) {
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i].second == target) {
            return i;
        }
    }
    return -1;  // Retorna -1 se a string não for encontrada no vetor
}


int main() {
    int n, e;
    float c;
    string inicio, fim, a, b;
    vector<pair<int, string>> names{};
    
    cin >> n >> e;
    Graph g(n);
    cin >> inicio >> fim;
    for (int i=0; i<e; i++) {
        cin >> a >> b >> c;
        if(find(names, a) == -1){
            names.push_back(make_pair((int)names.size()+1, a));
        }
        if(find(names, b) == -1){
            names.push_back(make_pair((int)names.size()+1, b));
        }

        g.addLink(find(names, a)+1, find(names, b)+1, c);
        g.addLink(find(names, b)+1, find(names, a)+1, c);
    }

    // Execucao exemplo a partir do no 1
    g.dijkstra(find(names, inicio)+1, find(names, fim)+1);

    return 0;
}
