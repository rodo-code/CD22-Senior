#include <iostream>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    multiset<int> ms = {5, 8, 7, 6, 5, 1, 1, 2, 8};
    for(auto elemento: ms){
        cout<<elemento<<" ";
    }
    cout<<endl;
    // La funcion count ahora si tiene mas sentido
    cout<<ms.count(5)<<endl;
    // En busqueda solo encuentra el primero
    int pos = distance(ms.begin(),ms.find(120)); // O(N)
    cout<<pos<<endl;
    return 0;
}