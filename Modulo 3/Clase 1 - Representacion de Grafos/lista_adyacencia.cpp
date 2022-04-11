#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodos,arcos;
    cin>>nodos>>arcos;
    vector<vi> G; // vector de vectores que almacenara el grafo
    G.assign(nodos,vi()); // Creamos nodos casillas cada una con un vector vacio vi()
    while(arcos--){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a); // Si es no dirigido
    }
    // Forma 1
    cout<<"------------------"<<"\n";
    for(auto lista: G){
        for(auto x: lista){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    // Forma 2
    cout<<"------------------"<<"\n";
    for(int i=0;i<G.size();i++){
        // G[i] es otro vector
        cout<<"Vecinos del nodo "<<i<<"\n";
        for(int j=0;j<G[i].size();j++){
            cout<<G[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}