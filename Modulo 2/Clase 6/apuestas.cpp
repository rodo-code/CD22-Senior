#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N;
    string s;
    cin>>N>>s;
    long long res = 0LL;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]) res+=((N-1)*N/2);
        else res+=N;
    }
    cout<<res<<"\n";
    return 0;
}