#include <iostream>
#include <list>

using namespace std;

int diam;

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

    void addLink(int a, int b) {
        nodes[a].adj.push_back(b);
        nodes[b].adj.push_back(a);
    }
    
    void bfs(int v) {
        diam = 0;
        list<int> q;
        for (int i=1; i<=n; i++) nodes[i].visited = false;
        
        q.push_back(v);
        nodes[v].visited = true;
        nodes[v].distance = 0;

        while (q.size() > 0) {
        int u = q.front(); 
        q.pop_front();

        if(nodes[u].distance > diam){
            diam = nodes[u].distance;
        }
        for (auto w : nodes[u].adj)
            if (!nodes[w].visited) {
            q.push_back(w);
            nodes[w].visited  = true;
            nodes[w].distance = nodes[u].distance + 1; 	  
            }
        }
    }
};


int main() {
    int n, e, a, b, MaxDiam = 0, MinRaio = 1500;
    list<int> cent{};
    list<int> peri{};
    cin >> n;
    Graph g(n);
    cin >> e;
    for (int i=0; i<e; i++) {
        cin >> a >> b;
        g.addLink(a, b);
    }

    for (int i = 1; i <= n; i++){
        g.bfs(i);
        if (diam > MaxDiam){
            MaxDiam = diam;
        }
        if(MinRaio > diam){
            MinRaio = diam;
        }        
    }
    for (int i = 1; i <= n; i++){
        g.bfs(i);
        if(diam == MinRaio){
            cent.push_back(i);
        } 
        if(diam == MaxDiam){
            peri.push_back(i);
        }     
    }
    
    cout << MaxDiam << endl << MinRaio << endl;

    cout << cent.front();
    cent.pop_front();
    for (auto i : cent) {
        cout << ' ' << i;
    }
    cout << endl;
    cout << peri.front();
    peri.pop_front();
    for (auto i : peri) {
        cout << ' ' << i;
    }
    cout << endl;

    return 0;
}