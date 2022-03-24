#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N;
    string s;
    cin>>N>>s;
    long long res = (N-1LL)*(N-1LL)*N/2LL;
    cout<<res<<"\n";
    return 0;
}