#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodos,arcos;
    cin>>nodos>>arcos;
    int MA[nodos][nodos];
    memset(MA,0,sizeof(MA));
    while(arcos--){
        int a,b;
        cin>>a>>b;
        MA[a][b]=1;
        MA[b][a]=1; // Si es no dirigido
    }
    for(int i=0;i<nodos;i++){
        for(int j=0;j<nodos;j++){
            cout<<MA[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}