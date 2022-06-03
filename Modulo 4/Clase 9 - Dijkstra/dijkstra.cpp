#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int INF=1000000000;
int nodos,arcos;
vector<vii> G;
vi d,p;

void dijkstra(int nodo){
    d[nodo] = 0;
    set<ii> pq;
    for(int i=0;i<nodos;i++)
        pq.insert(ii(d[i],i));
    while(!pq.empty()){
        // Obtenemos el primero de la cola
        int dist = pq.begin()->first;
        int dest = pq.begin()->second; 
        pq.erase(pq.begin()); // Sacando de la cola al primero
        for(auto elem: G[dest]){
            int vecino = elem.first;
            int peso = elem.second;
            // Greedy
            if(d[dest]+peso < d[vecino]){ // Actualizar
                pq.erase(ii(d[vecino],vecino));
                d[vecino] = d[dest] + peso;
                p[vecino] = dest;
                pq.insert(ii(d[vecino],vecino));
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
    cin>>nodos>>arcos;
    G.assign(nodos,vii());
    d.assign(nodos,INF);
    p.assign(nodos,-1);
    while(arcos--){
        int a,b,peso;
        cin>>a>>b>>peso;
        G[a].push_back(ii(b,peso));
        G[b].push_back(ii(a,peso));
    }
    dijkstra(3);
    cout<<"Distancias:\n";
    for(int i=0;i<nodos;i++){
        cout<<"La distancia al nodo "<<i<<" es "<<d[i]<<"\n";
    }
    cout<<"Padres:\n";
    for(int i=0;i<nodos;i++){
        cout<<"El padre del nodo "<<i<<" es "<<p[i]<<"\n";
    }
    cout<<"Caminos:\n";
    for(int i=0;i<nodos;i++){
        imprimir_camino(i);
    }
    return 0;
}