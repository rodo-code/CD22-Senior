#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {8,3,7,2,10,3};
    vector< pair<int,int> > a;
    for(int i=0;i<v.size();i++){
        a.push_back({v[i],i});
        //a.push_bac(make_pair(v[i],i))
    }
    sort(a.begin(),a.end());
    int x = 5;
    int pos_a = lower_bound(a.begin(),a.end(),make_pair(x,-1))-a.begin();
    pair<int,int> datos = a[pos_a];
    cout<<"Encontre al elemento "<<datos.first<<" en la posicion "<<datos.second<<endl;
    return 0;
}