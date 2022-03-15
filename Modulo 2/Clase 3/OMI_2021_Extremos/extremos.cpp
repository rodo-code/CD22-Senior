#include "extremos.h"
#include <vector>
#include <iostream>

using namespace std;
// Main
//	bool esMenor(int i, int j)
//	void respuesta(int posMenor, int posMayor)

void buscaExtremos(int n) {
	if(n==1) respuesta(1,1);
	else{
        vector<int>menores;
        vector<int>mayores;
		for(int i=1;i<n;i+=2){
            if(esMenor(i,i+1)){
                menores.push_back(i);
                mayores.push_back(i+1);
            }
            else{
                menores.push_back(i+1);
                mayores.push_back(i);
            }
		}
		/*for(auto x: menores){
            cout<<x<<" ";
		}
		cout<<endl;
		for(auto x: mayores){
            cout<<x<<" ";
		}
		cout<<endl;*/
		if(n%2==1){
            menores.push_back(n);
            mayores.push_back(n);
		}
		// Encontremos el menor
		int pos_menor = menores[0];
		for(int i=1;i<menores.size();i++){
            if(esMenor(menores[i],pos_menor))
                pos_menor = menores[i];
		}
		// Encontremos el mayor
		int pos_mayor = mayores[0];
		for(int i=1;i<menores.size();i++){
            if(not esMenor(mayores[i],pos_mayor))
                pos_mayor = mayores[i];
		}
		respuesta(pos_menor,pos_mayor);
	}
}
