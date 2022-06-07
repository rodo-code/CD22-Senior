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
    vector<vector<int> > answer(n,vector<int>(n)); // Creamos la matriz de adyacencia
    init(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(p[i][j]==1){
                if(!mismo_conjunto(i,j)){
                    unir(i,j);
                    answer[i][j]=1;
                    answer[j][i]=1;
                }
            }
        }
    }
    // Prueba de Completitutd del Primer Union Find
    // Verificar si p es correcto, si existe un grafo que lo satisfaga
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(mismo_conjunto(i,j) and p[i][j]==0){
				return 0;
			}
		}
	}
    // Ponemos a todos los representantes de los grafos linea en mapas de codificacion y decodificacion
    unordered_map <int,int> code,decode;
    int ind = 0;
    for(int i=0;i<int(padre.size());i++){
        int pi = buscar(i);
        if(pi==i){
            code[i]=ind;
            decode[ind]=i;
            ind++;
        }
    }
    int c_rep = code.size();
    //cout<<"Hay "<<c_rep<<" representantes\n";
    init(c_rep);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(p[i][j]==2){
                if(code.find(i)!=code.end() and code.find(j)!=code.end()){
                    unir(code[i],code[j]);
                }
            }
            
        }
    }
    // Prueba de Completitud del 2do Union Find
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(p[i][j]!=2 and mismo_conjunto(code[i],code[j])){
                return 0;
            }
        }
    }
    // Creamos los "conjuntos"
    unordered_map<int,vector<int> >conjuntos;
    for(int i=0;i<c_rep;i++){
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
        for(int i=0;i<int(lista.size());i++){
            int a = lista[i];
            int b = lista[(i+1)%lista.size()];
            answer[decode[a]][decode[b]] = 1;
            answer[decode[b]][decode[a]] = 1;
        }
    }
    build(answer);
    return 1;
}