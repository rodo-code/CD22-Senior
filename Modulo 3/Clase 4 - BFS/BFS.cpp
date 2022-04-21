#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> G; // vector de vectores que almacenara el grafo
vector<bool> visitado; // 0 NO VISITADO - 1 VISITADO
vi dist,padre;

void BFS(int nodo){
    queue<int> q;
    padre[nodo] = nodo;
    dist[nodo] = 0;
    q.push(nodo);
    while(!q.empty()){
        nodo = q.front();
        q.pop();
        for(auto vecino: G[nodo]){ // Para los vecinos del nodo
            if(padre[vecino]==-1){ // No ha sido visitado
                q.push(vecino);
                padre[vecino] = nodo;
                dist[vecino] = dist[nodo]+1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodos,arcos;
    cin>>nodos>>arcos;
    G.assign(nodos,vi()); // Creamos nodos casillas cada una con un vector vacio vi()
    visitado.assign(nodos,0); // Ningun nodo esta aun visitado
    dist.assign(nodos,-1); // No hay distancias
    padre.assign(nodos,-1); // No hay padres
    while(arcos--){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a); // Si es no dirigido
    }
    BFS(0); // Marcar todos los nodos a los que puede llegar desde el 2
    cout<<"PADRE = ";
    for(auto x: padre){
        cout<<x<<" ";
    }
    cout<<"\n";
    cout<<"DISTANCIA = ";
    for(auto x: dist){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}