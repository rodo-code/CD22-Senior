#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_filas, num_columnas;
    // PETICION DE UNA MATRIZ
    cin>>num_filas>>num_columnas;
    int matriz[num_filas][num_columnas];
    for(int i=0;i<num_filas;i++){ // Recorrer filas
        for(int j=0;j<num_columnas;j++){ // Recorrer columnas
            cin>>matriz[i][j];
        }
    }
    // IMPRIMIR UNA MATRIZ
    for(int i=0;i<num_filas;i++){ // Recorrer filas
        for(int j=0;j<num_columnas;j++){ // Recorrer columnas
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}