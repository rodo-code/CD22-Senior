#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct evento{
    long long tiempo;
    int tipo;
    long long angela,nicole;
    int orden;
};

// Cuando el evento a es menor al evento b
bool comp(evento& a, evento& b){
    if(a.tiempo < b.tiempo){
        return true;
    }
    if(a.tiempo == b.tiempo){
        if(a.tipo < b.tipo) return true;
        // else return false;
    }
    return false;
    /*if(a.tiempo > b.tiempo){
        return false;
    }*/
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long A,B;
    int P,Q;
    long long x,y,t;
    vector<evento> v;
    cin>>A>>B>>P>>Q;
    vector<string> salida(Q);
    while(P--){
        cin>>x>>y>>t;
        evento e;
        e.tiempo = t;
        e.tipo = 0;
        e.angela = x;
        e.nicole = y;
        v.push_back(e);
    }
    for(int i=0;i<Q;i++){
        cin>>t;
        evento e;
        e.tiempo = t;
        e.tipo = 1;
        e.orden = i;
        v.push_back(e);
    }
    sort(v.begin(),v.end(),comp);
    for(evento temp: v){
        if(temp.tipo == 0){
            A = A - temp.angela;
            B = B - temp.nicole;
        }
        else{
            string resp;
            if(A<B) resp = "Angela";
            if(A==B) resp = "SPIDER-VERSE CONFIRMADO";
            if(B<A) resp = "Nicole";
            salida[temp.orden] = resp;
        }
    }
    for(string r: salida) cout<<r<<"\n";
    return 0;
}