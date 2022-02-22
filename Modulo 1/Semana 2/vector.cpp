#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {8,4,-1,2,3};
    vector<int> v2 = {8,4,-1,2,3};
    v2.push_back(10);
    v2.insert(v2.begin()+2,5);
    int x = 3;
    vector<int>::iterator it=v2.begin()+x;
    v2.erase(it);
    v.resize(10,100);
    // for con posiciones
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    // for con iteradores
    //vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //vector<int>::iterator it;
    for(it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    // C++ 11
    for(auto x: v){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}