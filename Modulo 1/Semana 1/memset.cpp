#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[5];
    memset(a,5,sizeof(a));
    for(int i=0;i<(sizeof(a)/sizeof(int));i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    // sizeof es el tamaño en bytes
    cout<<sizeof(char)<<endl;
    cout<<sizeof(int)<<endl;
    cout<<sizeof(long long)<<endl;
    cout<<sizeof(double)<<endl;
    cout<<sizeof(bool)<<endl;
    cout<<sizeof(a)/4<<endl;
    return 0;
}