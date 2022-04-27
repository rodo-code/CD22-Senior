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

void unir(int a,int b){
    int ra = buscar(a);
    int rb = buscar(b); 
     // Si no estan en el mismo conjunto
    if(ra!=rb){
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
// ADORNO PARA DEBUGGING
void imprimir_datos(){
    cout<<"Cantidad de Componentes "<<comp<<"\n";
    cout<<"Representantes \t";
    for(auto x: p) cout<<x<<" ";
    cout<<"\n";
    cout<<"Rank \t\t";
    for(auto x: r) cout<<x<<" ";
    cout<<"\n";
    cout<<"Tamanios \t";
    for(auto x: tam) cout<<x<<" ";
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init(7);
    imprimir_datos();
    unir(1,0);
    imprimir_datos();
    unir(6,4);
    imprimir_datos();
    unir(3,2);
    imprimir_datos();
    unir(1,3);
    imprimir_datos();
    unir(2,0);
    imprimir_datos();
    return 0;
}