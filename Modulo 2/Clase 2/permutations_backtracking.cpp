#include <iostream>
#include <vector>
using namespace std;

vector<int> v = {5,3,1,2,4};

void permutate(int l,int r){
    if(l==r){
        // Encontramos una permutacion
        for(int x: v) cout<<x<<" ";
        cout<<endl;
        return;
    }
    for(int i=l;i<=r;i++){
        swap(v[i],v[l]);
        permutate(l+1,r);
        swap(v[i],v[l]); 
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    permutate(0,4);
    return 0;
}