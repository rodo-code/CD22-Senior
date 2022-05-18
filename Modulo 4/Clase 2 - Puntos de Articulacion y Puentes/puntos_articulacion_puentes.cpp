#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

unordered_set<int> puntos_articulacion;
vector<vi> G;
vi visitado,padre,dfs_num,dfs_low;
int tiempo = 0;
int cont_hijos_raiz = 0;
void DFS(int nodo){
    visitado[nodo]=1;
    dfs_num[nodo]=tiempo;
    dfs_low[nodo]=dfs_num[nodo];
    tiempo++;
    for(auto vecino: G[nodo]){
        // nodo -> vecino, vecino NO visitado
        if(visitado[vecino]==0){
            padre[vecino]=nodo;
            if(nodo == 0) cont_hijos_raiz++;
            DFS(vecino);
            if(dfs_low[vecino]>=dfs_num[nodo] and nodo!=0){ // No se a encontrado otra ruta para llegar a vecino
                puntos_articulacion.insert(nodo);
            }
            if(dfs_low[vecino]>dfs_num[nodo]){
                cout<<"Hay un puente del nodo "<<nodo<<" al nodo "<<vecino<<"\n";
            }
            dfs_low[nodo]=min(dfs_low[nodo],dfs_low[vecino]);
        }
        // nodo -> vecino, vecino YA visitado
        else{
            // No considerando a su padre
            if(vecino!=padre[nodo]){
                dfs_low[nodo]=min(dfs_low[nodo],dfs_num[vecino]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodos,arcos;
    cin>>nodos>>arcos;
    G.assign(nodos,vi());
    visitado.assign(nodos,0);
    padre.assign(nodos,-1);
    dfs_num.assign(nodos,-1);
    dfs_low.assign(nodos,-1);
    while(arcos--){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // Algoritmo - DFS modificado
    DFS(0);
    if(cont_hijos_raiz>1) puntos_articulacion.insert(0);
    cout<<"Puntos de Articulacion: ";
    for(auto nodo: puntos_articulacion) cout<<nodo<<" ";
    cout<<"\n";
    return 0;
}