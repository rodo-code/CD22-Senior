#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a;
    while(cin>>n>>a and not(n==0 and a==0)){
        int x,y;
        unordered_set<int>no_confiables;
        for(int i=0;i<a;i++){
            cin>>x>>y;
            if(y<0) // No es confiable y
            no_confiables.insert(-y);
        }
        cout<<n - no_confiables.size() <<endl;
    }
    return 0;
}