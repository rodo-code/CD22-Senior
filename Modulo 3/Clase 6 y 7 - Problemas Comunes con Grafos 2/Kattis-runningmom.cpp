#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool hay_ciclo = false;
vector<vi> G;
vi estado;
void dfs(int nodo){
    if(hay_ciclo) return;
    estado[nodo] = 1; // EXPLORADO
    for(auto vecino: G[nodo]){
        if(estado[vecino]==0){ // Tree Edge
            dfs(vecino);
        }
        if(estado[vecino]==1){ // Back Edge
            hay_ciclo = true;
            break;
        }
        if(estado[vecino]==2){ // Cross Edge

        }
            
    }
    estado[nodo] = 2; // VISITADO
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<string,int> codificar;
    int arcos;
    cin>>arcos;
    int ind=0;
    while(arcos--){
        string o,d;
        cin>>o>>d;
        // Para la ciudad o
        if(codificar.find(o)==codificar.end()){ // No existe el codigo de la ciudad o
            codificar[o]=ind;
            ind++;
            G.push_back(vi());
        }
        if(codificar.find(d)==codificar.end()){ // No existe el codigo de la ciudad d
            codificar[d]=ind;
            ind++;
            G.push_back(vi());
        }
        G[codificar[o]].push_back(codificar[d]);
    }
    
    // CONSULTAS
    string ciudad;
    while(cin>>ciudad){
        estado.assign(codificar.size(),0);
        hay_ciclo = false;
        int nodo = codificar[ciudad];
        // Test de ciclo
        dfs(nodo);
        if(hay_ciclo) cout<<ciudad<<" safe\n";
        else cout<<ciudad<<" trapped\n";
    }
    return 0;
}