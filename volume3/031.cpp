#include <iostream>
#include <list>
#include <vector>

using namespace std;

char tabela[250][250];
int altura, largura;

// Classe que representa um no
class Node {
public:
  list<int> adj;  // Lista de adjacencias
  bool visited;   // Valor booleano que indica se foi visitado numa pesquisa
  int distance;   // Distancia ao no origem da pesquisa

  Node() {        // Nao e preciso mais nada porque adj ja foi criada
  };              // mas queria mostrar que em C++ tambem existem construtores
};

// Classe que representa um grafo
class Graph {
    public:
    int n;          // Numero de nos do grafo
    Node *nodes;    // Array para conter os nos

    Graph(int n) { // Constructor: chamado quando um objeto Graph for criado
        this->n = n;
        nodes = new Node[n+1];  // +1 se os comecam em 1 ao inves de 0
    }

    ~Graph() { // Destructor: chamado quando um objeto Graph for destruido
        delete[] nodes;
    }

    void addLink(pair<int,int> coordenadas, int altura, int largura) {
        int atual = (coordenadas.first-1)*largura + coordenadas.second;
        if(coordenadas.first > 1){
            int a = coordenadas.first-1;
            int b = coordenadas.second;
            int n = (a-1)*largura + b;
            nodes[atual].adj.push_back(n);
        }
        if(coordenadas.first < altura-2){
            int a = coordenadas.first+1;
            int b = coordenadas.second;
            int n = (a-1)*largura + b;
            nodes[atual].adj.push_back(n);
        }
        if(coordenadas.second > 1){
            int a = coordenadas.first;
            int b = coordenadas.second-1;
            int n = (a-1)*largura + b;
            nodes[atual].adj.push_back(n);
        }
        if(coordenadas.second < largura-2){
            int a = coordenadas.first;
            int b = coordenadas.second+1;
            int n = (a-1)*largura + b;
            nodes[atual].adj.push_back(n);
        }
    }
    
    int bfs(int v, int largura) {
        list<int> q;
        for (int i=1; i<=n; i++){
            nodes[i].visited = false;
        }
        
        q.push_back(v);
        nodes[v].visited = true;
        nodes[v].distance = 0;

        while (q.size() > 0) {
            int u = q.front(); q.pop_front();
            for (auto w : nodes[u].adj){
                int linha = (w-1) / largura;
                int coluna = (w-1) % largura;
                if(tabela[linha][coluna] == '#'){
                    return nodes[u].distance;
                }
                
                if (!nodes[w].visited) {
                    q.push_back(w);
                    nodes[w].visited  = true;
                    nodes[w].distance = nodes[u].distance + 1; 	  
                }
            }
        }
        return -1;
    }
};

int main() {
    char item;

    cin >> altura >> largura;
    Graph g(altura * largura);
    vector<pair<int,int>> aeroportos{};

    for (int i = 1; i <= altura; i++){
        for (int j = 1; j <= largura; j++){
            cin >> item;
            tabela[i][j] = item;
            if(item == 'A'){
                aeroportos.push_back(make_pair(i,j));
            }
            g.addLink(make_pair(i,j), altura, largura);           
        }      
    }


    

    // Pesquisa em largura a partir do no 1
     for (auto it = aeroportos.begin(); it != aeroportos.end(); it++){
        int aeroporto1 = it->first;
        int aeroporto2 = it->second;
        int n = (aeroporto1-1)*largura + aeroporto2;
        cout << g.bfs(n, largura);
    }
    

    return 0;
}