#include <iostream>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,x;
    map<long long,int>freq;
    cin>>N;
    while(N--){
        cin>>x;
        freq[x]++;
        // Imprimir el mapa
        /*cout<<"Con el "<<x<<endl;
        cout<<"El mapa queda como:"<<endl;
        for(auto elemento: freq){
            cout<<elemento.first<<" se repite "<<elemento.second<<endl;
        }*/
    }
    // Obtenemos el que mas se repite
    long long mas_repetido;
    int max_repeticion=-1;
    for(auto elemento: freq){
        int frecuencia = elemento.second;
        long long num = elemento.first;
        if(frecuencia>=max_repeticion){
            max_repeticion = frecuencia;
            mas_repetido = num;
        }
    }
    cout<<"El numero mas repetido es "<<mas_repetido<<endl;
    return 0;
}