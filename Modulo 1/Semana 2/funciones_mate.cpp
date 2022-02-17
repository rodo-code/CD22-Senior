#include <bits/stdc++.h>

using namespace std;

long long pow_entero(long long a, long long b){
    long long res=1;
    for(long long i=0;i<b;i=i+1LL){
        res = res*a;
    }
    a=15;
    b=20;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a=5,b=10;
    cout<<pow(2,5)<<endl; // 2 elevado a la 5ta
    cout<<pow(27,0.333333333)<<endl; // raiz cubica de 27
    long long x = pow(5,23); // NO POW PARA ENTEROS
    cout<<x<<endl;
    x = pow_entero(5,23);
    cout<<x<<endl;
    cout<<pow_entero(8,14)<<endl;
    cout<<pow_entero(a,b)<<endl;
    cout<<a<<" "<<b<<endl;
    return 0;
}