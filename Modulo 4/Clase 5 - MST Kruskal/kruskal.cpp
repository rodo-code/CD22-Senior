#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vi p,r,tam;
int comp;

void init(int N){
    comp = N;
    p.clear();
    r.clear();
    tam.clear();
    for(int i=0;i<N;i++){
        p.push_back(i);
        r.push_back(1);
        tam.push_back(1);
    }
}

int buscar(int n){
    if(p[n]==n) return n; // Representante
    return p[n]=buscar(p[n]); // Actualizacion de representante
}

bool mismoConjunto(int a,int b){
    int ra = buscar(a);
    int rb = buscar(b);
    return ra==rb;
}

void unir(int a,int b){
     // Si no estan en el mismo conjunto
    int ra = buscar(a);
    int rb = buscar(b);
    if(!mismoConjunto(a,b)){
        // Unir
        comp--;
        if(r[ra]>=r[rb]){
            p[rb]=ra;
            tam[ra]+=tam[rb];
            if(r[ra]==r[rb]) r[ra]++;
        }
        else{
            p[ra]=rb;
            tam[rb]+=tam[ra];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector< pair<int, ii> > lista_arcos;
    int nodos,arcos;
    cin>>nodos>>arcos;
    while(arcos--){
        int a,b,peso;
        cin>>a>>b>>peso;
        lista_arcos.push_back(make_pair(peso,ii(a,b)));
    }
    sort(lista_arcos.begin(),lista_arcos.end());
    init(nodos);
    int peso_total = 0;
    for(auto x: lista_arcos){
        int peso = x.first;
        int a = x.second.first;
        int b = x.second.second;
        if(!mismoConjunto(a,b)){
            unir(a,b);
            cout<<"El arco de "<<a<<" a "<<b<<" con peso "<<peso<<" esta en el MST.\n";
            peso_total+=peso;
        }
    }
    cout<<"Peso Total = "<<peso_total<<"\n";
    return 0;
}
