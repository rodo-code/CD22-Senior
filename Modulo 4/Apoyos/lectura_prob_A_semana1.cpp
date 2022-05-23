#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> G;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodos;
    while(cin>>nodos and nodos!=0){
        G.assign(nodos,vi());
        string linea;
        cin.ignore();
        int nodo;
        do{
            getline(cin,linea);
            istringstream in(linea);
            in>>nodo;
            int vecino;
            while(in>>vecino){
                cout<<vecino<<"\n";
                G[nodo-1].push_back(vecino-1);
                G[vecino-1].push_back(nodo-1);
            }
        }while(nodo!=0);
        // Aqui el codigo ya se leyo el grafo
    }
    return 0;
}