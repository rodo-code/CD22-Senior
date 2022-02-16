#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,x;
    int cont=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){ // n vueltas
        cin>>x;
        if(x%k==0){
            cont++;
        }
    }
    cout<<cont<<endl;
    return 0;
}