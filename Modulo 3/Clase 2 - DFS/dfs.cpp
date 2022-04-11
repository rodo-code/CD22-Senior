#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> G; // vector de vectores que almacenara el grafo
vector<bool> visitado; // 0 NO VISITADO - 1 VISITADO

void DFS(int nodo){
    visitado[nodo] = 1; // Marcamos como visitado el nodo
    for(auto vecino: G[nodo]){ // Recorremos la lista de visitados
        if(!visitado[vecino]){ // Si no esta visitado el vecino
            DFS(vecino); // Lo visito
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
    while(arcos--){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a); // Si es no dirigido
    }
    DFS(6); // Marcar todos los nodos a los que puede llegar desde el 2
    for(int i=0;i<nodos;i++){
        if(visitado[i]) cout<<"Puedo llegar al nodo "<<i<<"\n";
        else cout<<"NO puedo llegar al nodo "<<i<<"\n";
    }
    return 0;
}