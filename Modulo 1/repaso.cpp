#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numero;
    cin>>numero;
    if(numero>0){
        cout<<"POSITIVO"<<endl;
    }
    if(numero<0){
        cout<<"NEGATIVO"<<endl;
    }
    if(numero==0){
        cout<<"CERO"<<endl;
    }
    bool x = numero>10;
    cout<<( numero>10? "El numero es mayor a 10" : "El numero no es mayor a 10")<<endl;
    // While para pedir hasta fin de archivo
    while(cin>>numero){
        cout<<numero<<endl;
    }
    // For 0 al 9
    for(int i=0;i<10;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    // For anidado
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<i<<" "<<j<<endl;
        }
    }
    return 0;
}