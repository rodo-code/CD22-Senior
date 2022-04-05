#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while(cin>>n>>m and !(n==0 and m==0)){
        vector<int>diam_cabeza(n);
        vector<int>alt_caballero(m);
        for(int i=0;i<n;i++) cin>>diam_cabeza[i];
        for(int i=0;i<m;i++) cin>>alt_caballero[i];
        sort(diam_cabeza.begin(),diam_cabeza.end());
        sort(alt_caballero.begin(),alt_caballero.end());
        int a=0,b=0;
        int cant_monedas = 0;
        while(a<n and b<m){
            if(alt_caballero[b]>=diam_cabeza[a]){
                // Puedo cortar esa cabeza
                cant_monedas += alt_caballero[b];
                a++;
                b++;
            }
            else{
                b++;
            }
        }
        if(a==n) cout<<cant_monedas<<endl;
        else cout<<"Loowater is doomed!"<<endl;
        
    }
    return 0;
}