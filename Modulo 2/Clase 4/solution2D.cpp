#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a;
    while(cin>>n>>a and not(n==0 and a==0)){
        int matriz[n+1][n+1]; // Arreglo Bidimensional
        memset(matriz,0,sizeof(matriz)); // Llena la matriz de 0
        int x,y;
        for(int i=0;i<a;i++){
            cin>>x>>y;
            if(y<0){
                matriz[x][-y]=-1;
            }
        }
        int c_conf = n;
        for(int i=1;i<=n;i++){
            int c_nega = 0;
            for(int j=1;j<=n;j++){
                if(matriz[j][i]==-1){c_nega++; break;}
            }
            if(c_nega!=0){ // En esa columna habia un negativo, entonces no es confiable
                c_conf--;
            }
        }
        cout<<c_conf<<"\n";
    }
    return 0;
}