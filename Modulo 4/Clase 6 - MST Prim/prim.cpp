#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> G;
vi marcado;

struct info {
    int distancia;
    int llegada;
    int origen;
};

struct comparador{
    bool operator()(info const& inf1, info const& inf2){
        if(inf1.distancia<inf2.distancia) return false;
        if(inf1.distancia>inf2.distancia) return true;
        if(inf1.distancia==inf2.distancia){
            if(inf1.llegada<inf2.llegada) return true;
            else return false;
        }
    }
};

void prim(int nodo){
    int vecino;
    int peso;
    int cmst = 0;
    marcado[nodo] = 1; // Marcamos el nodo
    priority_queue<info,vector<info>,comparador> pq;
    for(auto elem: G[nodo]){
        vecino = elem.first;
        peso = elem.second;
        info x;
        x.distancia = peso;
        x.llegada = vecino;
        x.origen = nodo;
        pq.push(x);
    }
    while(!pq.empty()){
        info elegido = pq.top();
        pq.pop();
        if(!marcado[elegido.llegada]){
            cmst += elegido.distancia;
            cout<<"El MST tiene al arco "<<elegido.origen<<"->"<<elegido.llegada<<"\n";
            marcado[elegido.llegada]=1;
            for(auto elem: G[elegido.llegada]){
                vecino = elem.first;
                peso = elem.second;
                if(!marcado[vecino]){
                    info x;
                    x.distancia = peso;
                    x.llegada = vecino;
                    x.origen = elegido.llegada;
                    pq.push(x);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodos,arcos;
    cin>>nodos>>arcos;
    G.assign(nodos,vii());
    marcado.assign(nodos,0);
    while(arcos--){
        int a,b,peso;
        cin>>a>>b>>peso;
        G[a].push_back(ii(b,peso));
        G[b].push_back(ii(a,peso));
    }
    prim(0);
    return 0;
}
