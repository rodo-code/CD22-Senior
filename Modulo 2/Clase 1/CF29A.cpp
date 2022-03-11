#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>x(n);
    vector<int>d(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>d[i];
    }

    // Fuerza Bruta
    for(int i=0;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            // Probar si el camello i y j se escupen uno al otro
            if(x[i]+d[i]==x[j] and x[j]+d[j]==x[i]){
                cout<<"YES"<<"\n";
                return 0;
            }
        }
    }
    cout<<"NO"<<"\n";

    return 0;
}