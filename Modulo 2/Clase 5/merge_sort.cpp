#include <iostream>
#include <vector>
using namespace std;

vector<int> v = {-2,3,7,1,2,0,9,5,10};

vector<int> merge_sort(int l,int r){
    vector<int> aux;
    if(l==r){ // Caso base
        aux.push_back(v[l]);
    } 
    else{
        int mid = (l+r)/2;
        vector<int> izq = merge_sort(l,mid);
        vector<int> der =merge_sort(mid+1,r);
        cout<<"Caso "<<l<<", "<<r<<endl;
        cout<<"izq"<<endl;
        for(auto elem:izq) cout<<elem<<" ";
        cout<<endl;
        cout<<"der"<<endl;
        for(auto elem:der) cout<<elem<<" ";
        cout<<endl;
        // Combinar
        int x=0,y=0;
        while(x<izq.size() and y<der.size()){
            if(izq[x]<der[y]){
                aux.push_back(izq[x]);
                x++;
            }
            else{
                aux.push_back(der[y]);
                y++;
            }
        }
        // Llenar con el saldo
        for(int i=x;i<izq.size();i++) aux.push_back(izq[i]);
        for(int i=y;i<der.size();i++) aux.push_back(der[i]);
        cout<<"mezcla"<<endl;
        for(auto elem:aux) cout<<elem<<" ";
        cout<<endl;
    }    
    return aux;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    v = merge_sort(0,v.size()-1);
    for(auto x:v) cout<<x<<" ";
    cout<<endl;
    return 0;
}