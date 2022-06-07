#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vi p,r;
int comp;

void init(int N){
    comp = N;
    p.clear();
    r.clear();
    for(int i=0;i<N;i++){
        p.push_back(i);
        r.push_back(1);
    }
}

int buscar(int n){
    if(p[n]==n) return n; // Representantes
    return p[n]=buscar(p[n]); // Actualizacion de representante
}

bool mismo_conjunto(int a,int b){
    return buscar(a)==buscar(b);
}

void unir(int a,int b){
    int ra = buscar(a);
    int rb = buscar(b); 
     // Si no estan en el mismo conjunto
    if(ra!=rb){
        // Unir
        comp--; // Numero de componentes bajas
        if(r[ra]>=r[rb]){
            p[rb]=ra;
            if(r[ra]==r[rb]) r[ra]++;
        }
        else{
            p[ra]=rb;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n;
    init(n+1);
    set< pair<int,ii> > s; 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>x;
            if(j>i){
                s.insert(make_pair(x,ii(i,j)));
            }
        }
    }
    set< pair<int,ii> >::iterator it;
    for(it=s.begin();it!=s.end();it++){
        ii nodos = it->second;
        int a = nodos.first;
        int b = nodos.second;
        if(!mismo_conjunto(a,b)){
            unir(a,b);
            cout<<a<<" "<<b<<endl;
        }
    }
    /*
    for(auto elem: s){
        ii nodos = elem.second;
        int a = nodos.first;
        int b = nodos.second;
    }*/
    return 0;
}