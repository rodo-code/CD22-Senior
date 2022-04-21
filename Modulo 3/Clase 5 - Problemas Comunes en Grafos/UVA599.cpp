#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cp;
    cin>>cp;
    while(cp--){
        int carcos=0,cnodos=0,cbellotas=0;
        vector<bool>existe(26,false);
        string arco;
        while(cin>>arco && arco[0]!='*'){
            int a = arco[1] - 'A';
            char b = arco[3] - 'A';
            existe[a] = true;
            existe[b] = true;        
            carcos++;
        }
        string nodos;
        cin>>nodos;
        // Procesar los nodos
        for(int i=0;i<nodos.size();i++){
            //if(nodos[i]==',' || nodos[i]==' ') continue;
            if(isalpha(nodos[i])){
                cnodos++;
                int c = nodos[i] - 'A';
                if(!existe[c]) cbellotas++;
            }
        }
        int trees = cnodos - carcos -cbellotas;
        cout<<"There are "<<trees<<" tree(s) and "<<cbellotas<<" acorn(s)."<<"\n";
    }
    return 0;
}