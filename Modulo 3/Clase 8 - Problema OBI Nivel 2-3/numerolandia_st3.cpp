#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vi p,r;

void init(int N){
    p.clear();
    r.clear();
    for(int i=0;i<N;i++){
        p.push_back(i);
        r.push_back(1);
    }
}

int buscar(int n){
    if(p[n]==n) return n; // Representante
    return p[n]=buscar(p[n]); // Actualizacion de representante
}

void unir(int a,int b){
    int ra = buscar(a);
    int rb = buscar(b); 
     // Si no estan en el mismo conjunto
    if(ra!=rb){
        // Unir
        if(r[ra]>=r[rb]){
            p[rb]=ra;
            if(r[ra]==r[rb]) r[ra]++;
        }
        else{
            p[ra]=rb;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi numeros;
    int N,x;
    cin>>N;
    init(10000010);
    while(N--){
        cin>>x;
        numeros.push_back(x);
    }
    for(int i=0;i<numeros.size();i++){
        for(int j=i+1;j<numeros.size();j++){
            // MCD(numeros[i],numeros[j])>1
            if(__gcd(numeros[i],numeros[j])>1){
                //cout<<"Uni "<<numeros[i]<<" con "<<numeros[j]<<"\n";
                unir(numeros[i],numeros[j]);
            }
            if(numeros[i]==1 or numeros[j]==1)
                unir(numeros[i],numeros[j]);
        }
    }
    int Q;
    cin>>Q;
    while(Q--){
        int a,b;
        cin>>a>>b;
        if(buscar(numeros[a])==buscar(numeros[b])) cout<<"SI"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}