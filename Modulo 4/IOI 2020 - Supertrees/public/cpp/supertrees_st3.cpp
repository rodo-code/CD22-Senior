#include "supertrees.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> padre,rnk,tam;

void init(int n){
    padre.assign(n,0);
    rnk.assign(n,1);
    tam.assign(n,1);
    for(int i=0;i<n;i++){
        padre[i]=i; // Es su propio padre
    }
}

int buscar(int x){
    if(padre[x]==x) return x;
    else return padre[x]=buscar(padre[x]);
}

bool mismo_conjunto(int a,int b){
    return buscar(a)==buscar(b);
}

void unir(int a,int b){
    if(!mismo_conjunto(a,b)){
        a = buscar(a);
        b = buscar(b);
        if(rnk[a]>=rnk[b]){
            // B se una a A
            padre[b] = a;
            tam[a]+=tam[b];
            if(rnk[a]==rnk[b]) rnk[a]++;
        }
        else{
            // A se une a B
            padre[a] = b;
            tam[b] += tam[a];
        }
    }
}

int construct(vector<vector<int> > p) {
	int n = p.size();
    // Armamos el Union Find
    init(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(p[i][j]==2){
                unir(i,j);
            }
        }
    }
    // Prueba de Completitud
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(p[i][j]==0 and mismo_conjunto(i,j)){
                return 0;
            }
        }
    }
    // Intetamos generar el grafo
    vector<vector<int> > answer(n,vector<int>(n)); // Creamos la matriz de adyacencia
    unordered_map<int,vector<int> >conjuntos;
    for(int i=0;i<n;i++){
        int rep = buscar(i);
        if(tam[rep]==2) return 0; // No puede haber un ciclo de 2 elementos
        if(conjuntos.find(rep) == conjuntos.end()){
            // No existe aun esa llave
            conjuntos[rep] = vector<int>();            
        }
        conjuntos[rep].push_back(i);
    }
    // Construimos la matriz de adyacencia
    for(auto elem: conjuntos){
        vector<int> lista = elem.second;
        if(lista.size() == 1) continue;
        for(int i=0;i<lista.size();i++){
            int a = lista[i];
            int b = lista[(i+1)%lista.size()];
            answer[a][b] = 1;
            answer[b][a] = 1;
        }
    }
    build(answer);
	return 1;
}