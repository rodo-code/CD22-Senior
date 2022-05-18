#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

vi A = {3,2,7,4,1,5,6};
vi st(4*7);

void crear(int l,int r, int nodo){
    // Caso Base
    if(l==r) st[nodo]=A[l];
    else{
        int mid = (r+l)/2;
        // Izquierda
        crear(l,mid,nodo*2);
        // Derecha
        crear(mid+1,r,nodo*2 + 1);
        // Union de los dos segmentos
        st[nodo] = min(st[nodo*2],st[nodo*2+1]);
    }
}

int consulta(int l,int r,int nodo, int a, int b){
    // Casos base
    if(r<a or b<l) return INF; // Retornamos el neutro
    if(a<=l and r<=b) return st[nodo];
    int mid = (l+r)/2;
    int izq = consulta(l,mid,nodo*2,a,b);
    int der = consulta(mid+1,r,nodo*2 + 1,a,b);
    return min(izq,der);
}

void actualizar(int l,int r,int nodo, int pos, int val){
    // Casos base
    // Si no esta en ese rango
    if(not (l<=pos and pos <=r)) return;
    // Si esta en el punto
    if(l==r and l==pos){
        st[nodo]=val;
        return;
    }
    int mid = (l+r)/2;
    actualizar(l,mid,nodo*2,pos,val);
    actualizar(mid+1,r,nodo*2+1,pos,val); 
    st[nodo]=min(st[nodo*2],st[nodo*2+1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    crear(0,6,1);
    for(int i=1;i<=13;i++) cout<<st[i]<<" ";
    cout<<"\n";
    cout<<"RMQ(1,5)="<<consulta(0,6,1,1,5)<<"\n";
    cout<<"RMQ(0,6)="<<consulta(0,6,1,0,6)<<"\n";
    cout<<"RMQ(4,4)="<<consulta(0,6,1,4,4)<<"\n";
    cout<<"RMQ(0,3)="<<consulta(0,6,1,0,3)<<"\n";
    cout<<"Actualizar A[2] = 0"<<"\n";
    actualizar(0,6,1,2,0);
    for(int i=1;i<=13;i++) cout<<st[i]<<" ";
    cout<<"\n";
    cout<<"RMQ(1,5)="<<consulta(0,6,1,1,5)<<"\n";
    cout<<"RMQ(0,6)="<<consulta(0,6,1,0,6)<<"\n";
    cout<<"RMQ(4,4)="<<consulta(0,6,1,4,4)<<"\n";
    cout<<"RMQ(0,3)="<<consulta(0,6,1,0,3)<<"\n";
    return 0;
}