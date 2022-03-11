#include "extremos.h"

using namespace std;
// Main
//	bool esMenor(int i, int j)
//	void respuesta(int posMenor, int posMayor)

void buscaExtremos(int n) {
	if(n==1) respuesta(1,1);
	else{
		// Menor
		int pos_menor = 1;
		for(int i=2;i<=n;i++){
			if(esMenor(i,pos_menor)) pos_menor = i;
		}
		// Mayor
		int pos_mayor = 1;
		for(int i=2;i<=n;i++){
			if(not esMenor(i,pos_mayor)) pos_mayor = i;
		}
		respuesta(pos_menor,pos_mayor);
	}
}