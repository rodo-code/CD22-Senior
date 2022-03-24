#include <bits/stdc++.h>

using namespace std;

int matriz[22][22]; // Arreglo Bidimensional

vector<int> elegidos;
vector<bool> contradictorios;

int contar_confiables(){
    int c_conf = 0;
    for(int i=0;i<elegidos.size();i++){
        int c_nega = 0;
        int c_posi = 0;
        for(int j=0;j<elegidos.size();j++){
            if(matriz[elegidos[j]][elegidos[i]]==-1){c_nega++;}
            if(matriz[elegidos[j]][elegidos[i]]==1){c_posi++;}
        }
        if(c_nega==0 and c_posi>=0){ // En esa columna habia un negativo, entonces no es confiable
            c_conf++;
        }
    }
    return c_conf;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a;
    while(cin>>n>>a and n!=0 and a!=0){
        int res = -1;
        contradictorios.assign(n+1,0);
        elegidos.clear();
        memset(matriz,0,sizeof(matriz)); // Llena la matriz de 0
        int x,y;
        for(int i=0;i<a;i++){
            cin>>x>>y;
            if(y>0){
                if(matriz[x][y]!=0)  contradictorios[x]=1;
                matriz[x][y]=1;
            }
            else{
                if(matriz[x][y]!=0)  contradictorios[x]=1;
                matriz[x][-y]=-1;
            }
        }
        // Solo no contradictorios
        vector<int>posibles;
        for(int i=1;i<contradictorios.size();i++){
            if(!contradictorios[i]) posibles.push_back(i);
        }
        //cout<<"ELEGIDOS"<<endl;
        //for(int i=0;i<posibles.size();i++) cout<<posibles[i]<<" ";
        //cout<<endl;

        // Mascara de bits
        int candidatos = posibles.size();
        for(int i=0;i<(1<<candidatos);i++){
            elegidos.clear();
            for(int j=0;j<candidatos;j++){
                if(i&(1<<j)) elegidos.push_back(posibles[j]);
            }
            //cout<<"POSIBLE "<<i<<endl;
            //for(auto elem: elegidos) cout<<elem<<" ";
            res = max(res,contar_confiables());
            //cout<<endl<<"res="<<res<<endl;
        }       
        cout<<res<<"\n";
    }
    return 0;
}