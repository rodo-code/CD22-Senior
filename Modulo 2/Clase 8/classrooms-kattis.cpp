#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct evento{
    int inicio;
    int fin;
};

bool comparador(evento& a, evento& b){
    if(a.fin < b.fin){
        return true;
    }
    if(a.fin == b.fin){
        if(a.inicio>b.inicio) return true;
        else return false;
    }
    if(a.fin > b.fin){
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<evento> v;
    int n,k;
    int s,f;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>s>>f;
        evento x;
        x.inicio = s;
        x.fin = f;
        v.push_back(x);
    }
    
    sort(v.begin(),v.end(),comparador);
    // C++ 11
    multiset<int>salones;
    int ca = 0;
    for(evento x: v){
       multiset<int>::iterator it = salones.lower_bound(-(x.inicio));
       // Todos los salones estan ocupados
       if(it == salones.end()){
           if(salones.size()!=k){
               ca++; // Metimos un actividad
               salones.insert(-(x.fin+1));
           }
       }
       else{
            ca++;
            salones.erase(it);
            salones.insert(-(x.fin+1));
       }
    }
    cout<<ca<<"\n";
    return 0;
}