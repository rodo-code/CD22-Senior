#include <iostream>

using namespace std;

int f(int n){
    // Suma de digitos
    int suma=0;
    while(n>0){
        int digito = n%10;
        suma += digito;
        n/=10;
    }
    return suma;
}

int g(int n){
    // CASO BASE
    if(n>=0 and n<=9){// ya es un solo digito
        return n;
    }
    return g(f(n)); // Paso recursivo
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n and n!=0){
        cout<<g(n)<<endl;
    }
    return 0;
}