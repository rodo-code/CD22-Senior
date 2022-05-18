#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> G;
vector<vi> GT;
vi visitado;
vi TS;
void DFS(int nodo){
    visitado[nodo] = 1;
    for(auto vecino: G[nodo]){
        if(visitado[vecino]==0){
            DFS(vecino);
        }
    }
    TS.push_back(nodo);
}

void kosaraju(int nodo){
    visitado[nodo] = 1;
    for(auto vecino: GT[nodo]){ // Transpuesta del grafo
        if(visitado[vecino]==0){
            kosaraju(vecino);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodos, arcos;
    cin>>nodos>>arcos;
    G.assign(nodos,vi());
    GT.assign(nodos,vi());
    visitado.assign(nodos,0);
    while(arcos--){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        GT[b].push_back(a);
    }
    for(int i=0;i<nodos;i++){
        if(visitado[i]==0) DFS(i);
    }
    visitado.assign(nodos,0);
    int cont_scc = 0;
    for(int i=TS.size()-1;i>=0;i--){
        if(visitado[TS[i]]==0){
            kosaraju(TS[i]);
            cont_scc++;
        }
    }
    cout<<"Hay "<<cont_scc<<" componentes fuertemente conexas"<<"\n";
    return 0;
}