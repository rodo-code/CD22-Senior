#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vi botones,cb;

void bfs(int tiempo){
    queue<int> q;
    q.push(tiempo);
    cb[tiempo] = 0;
    while(!q.empty()){
        tiempo = q.front();
        q.pop();
        // Recorrer su lista de adyacencia
        for(int i=0;i<botones.size();i++){
            int t_futuro = tiempo + botones[i];
            if(t_futuro<0) t_futuro = 0;
            if(t_futuro>3600) t_futuro = 3600;
            if(cb[t_futuro]==-1){ // No ha sido visitado
                cb[t_futuro] = cb[tiempo] + 1;
                q.push(t_futuro);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cp;
    cin>>cp;
    while(cp--){
        int n,t,x;
        botones.clear();
        cb.assign(3601,-1);
        cin>>n>>t;
        while(n--){
            cin>>x;
            botones.push_back(x);
        }
        bfs(0);
        if(cb[t]!=-1) cout<<cb[t]<<" 0\n";
        else{
            int ct = t;
            while(cb[t]==-1){
                t++;
            }
            cout<<cb[t]<<" "<<t-ct<<"\n";
        }
    }

    return 0;
}