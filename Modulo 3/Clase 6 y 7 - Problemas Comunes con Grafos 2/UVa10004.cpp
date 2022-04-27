#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodos,arcos;
    while(cin>>nodos and nodos!=0){
        cin>>arcos;
        vector<vi> G;
        G.assign(nodos,vi());
        vi color(nodos,-1); // -1 NO PINTADO
        while(arcos--){
            int a,b;
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        // COLOREAR
        // COLOR 1 -> 0, COLOR 2 -> 1
        // BFS modificado
        bool bicoloreable = true;
        queue<int> q;
        q.push(0);
        color[0] = 0;
        while(!q.empty() and bicoloreable){
            int nodo = q.front();
            q.pop();
            for(auto vecino: G[nodo]){
                if(color[vecino]==-1){ // No ha sido pintado
                    color[vecino] = (color[nodo] + 1)%2;
                    q.push(vecino);
                }
                else{ // Esta pintado
                    if(color[vecino] == color[nodo]){
                        bicoloreable = false;
                        break;
                    }
                }
            }
        }
        if(bicoloreable) cout<<"BICOLORABLE.\n";
        else cout<<"NOT BICOLORABLE.\n";
    }
    return 0;
}