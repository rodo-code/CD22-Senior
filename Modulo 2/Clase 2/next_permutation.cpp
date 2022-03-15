#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {5,2,4,3,1};
    do{
        for(int x: v) cout<<x<<" ";
        cout<<endl;
    }while(next_permutation(v.begin(),v.end()));
    return 0;
}