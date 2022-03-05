#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<string,int> um;
    um["Pepe"]=3;
    um["Marcelo"]=4;
    um.insert(make_pair("Luka",7));
    um.insert(make_pair("Iker",1));
    um.insert(make_pair("Andres",9));
    for(auto elemento: um){
        cout<<elemento.first<<" "<<elemento.second<<endl;
    }
    // Find O(k)
    if(um.find("Rodolfo")!=um.end())
        cout<<"Rodolfo esta en el conjunto"<<endl;
    // Borrado
    um.erase("Pepe"); // O(k)
    unordered_map<string,int>::hasher fn = um.hash_function();
    cout<<fn("Rodolfo")<<endl;
    cout<<um.bucket_count()<<endl;
    return 0;
}