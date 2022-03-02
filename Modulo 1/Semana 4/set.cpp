#include <iostream>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<long long> conj;
    int N;
    long long x;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x;
        conj.insert(x);
    }
    cout<<conj.size()<<endl;
    // Impresion en C++11
    for(auto elemento: conj){
        cout<<elemento<<" ";
    }
    cout<<endl;
    return 0;
}