#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    string bebida,bebida1,bebida2;
    int cc=0;
    while(cin>>N){
        cc++;
        // N es la cantidad de nodos
        vector<vi> G;
        G.assign(N,vi());
        vi grado(N,0);
        vector<bool> visitado(N,false);
        unordered_map<string,int> codificar;
        unordered_map<int,string> decodificar;
        for(int i=0;i<N;i++){
            cin>>bebida;
            codificar[bebida] = i;
            decodificar[i] = bebida;
        }
        cin>>M;
        for(int i=0;i<M;i++){
            cin>>bebida1>>bebida2;
            int codigo_bebida1 = codificar[bebida1];
            int codigo_bebida2 = codificar[bebida2]; 
            G[codigo_bebida1].push_back(codigo_bebida2);
            grado[codigo_bebida2]++;
        }
        // Algoritmo de Khan
        vector<int> ts;
        priority_queue< int, vi,greater<int> > pq;
        // Buscamos los nodos con grado 0
        for(int i=0;i<N;i++){
            if(grado[i]==0) pq.push(i);
        }
        while(!pq.empty()){
            int nodo = pq.top();
            pq.pop();
            ts.push_back(nodo);
            visitado[nodo] = true;
            // Recorro los veciones de nodo
            for(auto vecino: G[nodo]){
                grado[vecino]--;
                if(grado[vecino]==0){ // Si ya cumplimos los requisitos
                    visitado[vecino] = true; // visito
                    pq.push(vecino); // coloco en la cola
                }
            }
        }
        cout<<"Case #"<<cc<<": Dilbert should drink beverages in this order:";
        for(auto x: ts) cout<<" "<<decodificar[x];
        cout<<".\n\n";
    }
    return 0;
}