#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Q;
    cin>>N;
    int a[N];
    int pico = -1,pos_pico = -1;
    for(int i=0;i<N;i++){
        cin>>a[i];
        if(a[i]>pico){
            pico=a[i];
            pos_pico=i;
        }
    }
    cin>>Q;
    while(Q--){
        int a,b;
        cin>>a>>b;
        if(pos_pico>=a && pos_pico<=b) cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}