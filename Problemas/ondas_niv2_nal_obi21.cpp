#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Q,x;
    vector<int>A;
    cin>>N;
    vector<int>P(N); // vector de tamaño n
    for(int i=0;i<N;i++){
        cin>>x;
        A.push_back(x);
    }
    // Construyamos la acumulada
    P[0]=0;
    for(int i=1;i<N-1;i++){
        // Si es pico
        if(A[i]>A[i-1] and A[i]>A[i+1]){
            P[i]=P[i-1]+1;
        }
        else{
            P[i]=P[i-1];
        }
    }
    P[N-1]=P[N-2];
    // Respondemos las consultas
    cin>>Q;
    for(int i=0;i<Q;i++){
        int l,r;
        cin>>l>>r;
        if(l>0) cout<<P[r]-P[l-1]<<"\n";
        if(l==0) cout<<P[r]<<"\n";
    }
    return 0;
}