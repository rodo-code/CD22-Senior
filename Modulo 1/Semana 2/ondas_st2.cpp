#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Q;
    cin>>N;
    int arr[N];
    int pico = -1,pos_pico = -1;
    for(int i=0;i<N;i++){
        cin>>arr[i];
        if(arr[i]>pico){
            pico=arr[i];
            pos_pico=i;
        }
    }
    cin>>Q;
    while(Q--){
        int a,b,cont=0;
        cin>>a>>b;
        for(int i=a;i<=b;i++){
            if(arr[i-1]<arr[i] && arr[i+1]<arr[i]){ // Pregunta para saber si es pico
                cont++;
            }
        }
        cout<<cont<<endl;
    }
    return 0;
}