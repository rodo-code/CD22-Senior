#include <iostream>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    multimap<string,int> mm;
    mm.insert(make_pair("Maria",5));
    mm.insert(make_pair("Juan",10));
    mm.insert(make_pair("Maria",7));
    mm.insert(make_pair("Juan",15));
    mm.insert(make_pair("Juan",10));
    for(auto elemento: mm){
        cout<<elemento.first<<"-> "<<elemento.second<<endl;
    }
    cout<<endl;
    return 0;
}