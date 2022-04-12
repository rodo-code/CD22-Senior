#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int m,n;
char tablero[110][110];
int cf[8] = {-1,-1,0,1,1,1,0,-1};
int cc[8] = {0,1,1,1,0,-1,-1,-1};

int cont_pockets = 0;

void flood_fill(int f,int c){
    cont_pockets++;
    tablero[f][c] = '#'; // EXPLORADO
    for(int i=0;i<8;i++){
        int nf = f + cf[i];
        int nc = c + cc[i];
        if(nf>=0 and nf<m and nc>=0 and nc<n){ // Si esta en el tablero
            if(tablero[nf][nc]=='@'){ // Si es un pocket y no esta explorado
                flood_fill(nf,nc);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin>>m>>n and !(m==0 and n==0)){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>tablero[i][j];
            }
        }
        // Contando los pozos
        int cont_pozos = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(tablero[i][j]=='@'){
                    cont_pockets = 0;
                    flood_fill(i,j);
                    cont_pozos++;
                }
            }
        }
        cout<<cont_pozos<<"\n";
    }
    return 0;
}