#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    queue<int> q;
    q.push(5);
    q.push(7);
    q.push(3);
    q.push(2);
    // Imprimimos el tamaño de la cola
    cout<<"El tamanio de la cola es "<<q.size()<<endl;
    // RECORRIDO
    while(not q.empty()){
        // Vemos quien esta al frente
        cout<<q.front()<<" ";
        // Sacar de la cola
        q.pop();
    }
    cout<<endl;
    return 0;
}