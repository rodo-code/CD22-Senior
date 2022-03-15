#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<int> elegidos;
vector< vector<int> > opciones= {
    {0},
    {1,2,3,4,5,6,7,8,9,0},
    {2,3,5,6,8,9,0},
    {3,6,9},
    {4,5,6,7,8,9,0},
    {5,6,8,9,0},
    {6,9},
    {7,8,9,0},
    {8,9,0},
    {9}
};
void buscar(int valor){
    // Caso base
    if(valor>200) return;
    elegidos.insert(valor);
    // Búsqueda basada en el último digito del valor
    int ud = valor%10;
    for(int opcion: opciones[ud]){
        int nv = valor*10 + opcion;
        buscar(nv);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    elegidos.insert(0);
    for(int i=1;i<=9;i++){
        buscar(i);
    }
    for(auto valor: elegidos){
        cout<<valor<<",";
    }
    cout<<endl;
    return 0;
}