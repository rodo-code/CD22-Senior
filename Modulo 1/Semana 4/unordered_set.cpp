#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_set<string> us = {"Lucas","Raul","Andrea","Juan","Maria"};
    for(string elemento: us){
        cout<<elemento<<" ";
    }
    cout<<endl; // Maria Lucas Raul Juan Andrea
    // Find O(k)
    if(us.find("Rodolfo")!=us.end())
        cout<<"Rodolfo esta en el conjunto"<<endl;
    // Borrado
    us.erase("Juan"); // O(k)
    unordered_set<string>::hasher fn = us.hash_function();
    cout<<fn("Rodolfo")<<endl;
    cout<<us.bucket_count()<<endl;
    return 0;
}