#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> p;
    p.push(5);
    p.push(7);
    p.push(3);
    p.pop();
    p.push(2);
    // Imprimimos el tamaño de la cola
    cout<<"El tamanio de la cola es "<<p.size()<<endl;
    // RECORRIDO
    while(not p.empty()){
        // Vemos quien esta en la cima
        cout<<p.top()<<" ";
        // Sacar de la pila
        p.pop();
    }
    cout<<endl;
    return 0;
}