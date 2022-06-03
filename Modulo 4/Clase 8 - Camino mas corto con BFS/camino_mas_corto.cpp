#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> G; // vector de vectores que almacenara el grafo
vector<bool> visitado; // 0 NO VISITADO - 1 VISITADO
vi dist,p;

void BFS(int nodo){
    dist[nodo]=0;
    visitado[nodo]=1;
    queue<int>q;
    q.push(nodo);
    while(!q.empty()){
        nodo = q.front();
        q.pop();
        for(auto vecino: G[nodo]){
            if(visitado[vecino]==0){
                q.push(vecino);
                visitado[vecino]=1;
                p[vecino] = nodo;
                dist[vecino] = dist[nodo] + 1;
            }
        }
    }
}

void imprimir_camino(int nodo){
    deque<int> camino;
    camino.push_front(nodo);
    while(p[nodo]!=-1){
        camino.push_front(p[nodo]);
        nodo = p[nodo];
    }
    cout<<"Camino: ";
    cout<<camino[0];
    for(int i=1;i<camino.size();i++){
        cout<<"->"<<camino[i];
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodos,arcos;
    cin>>nodos>>arcos;
    G.assign(nodos,vi()); // Creamos nodos casillas cada una con un vector vacio vi()
    visitado.assign(nodos,0); // Ningun nodo esta aun visitado
    dist.assign(nodos,-1); // No hay distancias
    p.assign(nodos,-1); // No hay padres
    // Creando el grafo
    while(arcos--){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a); // Si es no dirigido
    }
    BFS(0);
    for(int i=0;i<nodos;i++){
        cout<<"Distancia al nodo "<<i<<" es "<<dist[i]<<"\n";
        imprimir_camino(i);
    }
    return 0;
}