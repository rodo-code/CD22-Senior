#include "supertrees.h"
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
 
vector<int> rep,rnk;
 
void init(int N){
	rep.assign(N,0);
	for(int i=0;i<N;i++){
		rep[i]=i;
	}
	rnk.assign(N,1);
}
 
int buscar(int a){
	if(rep[a]==a) return a;
	return rep[a]=buscar(rep[a]);
}
 
bool mismo_conjunto(int a,int b){
	return buscar(a)==buscar(b);
}
 
void unir(int a,int b){
	int ra=buscar(a);
	int rb=buscar(b);
	if(ra != rb){
		if(rnk[ra]>rnk[rb]){
			rep[rb]=ra;
		}
		else{
			rep[ra]=rb;
		}
	}
}
 
int construct(vector<vector<int> > p) {
	int n = p.size();
	vector<vector<int> > answer;
	answer.assign(n,vector<int>(n));
	// Creamos el Union Find
	init(n);
	// Recorremos p
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(p[i][j]==1){
				unir(i,j);
			}
		}
	}
	// Verificar si p es correcto, si existe un grafo que lo satisfaga
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(mismo_conjunto(i,j) and p[i][j]==0){
				return 0;
			}
		}
	}
	// Si p es valido
	unordered_map<int,vector<int> >conjuntos;
	for(int i=0;i<rep.size();i++){
		int ri = buscar(i);
		if(conjuntos.find(ri)!=conjuntos.end()){
			conjuntos[ri].push_back(i);
		}
		else{
			conjuntos[ri] = vector<int>();
			conjuntos[ri].push_back(i);
		}
	}
	for(auto elem: conjuntos){
		vector<int> cont = elem.second;
		for(int i=0;i<cont.size()-1;i++){
			int na = cont[i];
			int nb = cont[i+1];
			answer[na][nb]=1;
			answer[nb][na]=1;
		}
	}
	build(answer);
	return 1;
}