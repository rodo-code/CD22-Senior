#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int N = 10;
vi A = {0,2,7,4,5,1,9,3,6,8,10};
vi ft;

int LSOne(int S){
    return (S & -(S));
}

void crear(){
    ft.assign(N+1,0);
    for(int i=1;i<=N;i++){
        ft[i]+=A[i];
        int padre = i + LSOne(i);
        if(padre<=N){
            ft[padre]+=ft[i];
        }
    }
}

int consulta(int a,int b){
    if(a==1){
        int res = 0; // Nulo
        while(b>0){
            res += ft[b];
            b = b - LSOne(b);
        }
        return res;
    }
    else{
        return consulta(1,b)-consulta(1,a-1);
    }
}

void actualizacion(int pos, int incr){
    while(pos<=N){
        ft[pos]+=incr;
        pos = pos + LSOne(pos);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    crear();
    for(auto x: ft) cout<<x<<" ";
    cout<<"\n";
    cout<<"RSQ(1,2)="<<consulta(1,2)<<"\n";
    cout<<"RSQ(1,7)="<<consulta(1,7)<<"\n";
    cout<<"RSQ(3,7)="<<consulta(3,7)<<"\n";
    cout<<"RSQ(2,2)="<<consulta(2,2)<<"\n";
    actualizacion(2,2);
    cout<<"RSQ(1,2)="<<consulta(1,2)<<"\n";
    cout<<"RSQ(1,7)="<<consulta(1,7)<<"\n";
    cout<<"RSQ(3,7)="<<consulta(3,7)<<"\n";
    cout<<"RSQ(2,2)="<<consulta(2,2)<<"\n";
    return 0;
}