#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Q;
    cin>>N;
    int a[N];
    vector<int>v;
    for(int i=0;i<N;i++){
        cin>>a[i];
        if(i>=2){
            if(a[i-1]>a[i-2] and a[i-1]>a[i]){
                v.push_back(i-1);
            }
        }
    }
    cin>>Q;
    while(Q--){
        int a,b;
        cin>>a>>b;
        int posa = lower_bound(v.begin(),v.end(),a)-v.begin();
        int posb = lower_bound(v.begin(),v.end(),b)-v.begin();
        int cont = posb-posa;
        if(v[posb]==b) cont++;
        cout<<cont<<endl;
    }
    return 0;
}