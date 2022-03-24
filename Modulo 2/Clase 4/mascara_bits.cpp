#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>v = {1,2,3,4,5,6,7,8,9,10};
    int n = v.size();
    for(int x=0;x<(1<<n);x++){
        for(int pos=n-1;pos>=0;pos--){
            if(x&(1<<pos)){ // Esta prendido el bit en la posicion pos
                cout<<v[pos]<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}