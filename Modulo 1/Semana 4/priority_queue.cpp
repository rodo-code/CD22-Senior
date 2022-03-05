#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int> max_heap;
    max_heap.push(5);
    max_heap.push(7);
    max_heap.push(10);
    max_heap.push(2);
    max_heap.push(1);

    // RECORRIDO
    while(not max_heap.empty()){
        cout<<max_heap.top()<<" ";
        max_heap.pop();
    }
    cout<<endl;

    priority_queue<int, vector<int>, greater<int> > min_heap;
    min_heap.push(5);
    min_heap.push(7);
    min_heap.push(10);
    min_heap.push(2);
    min_heap.push(1);

    // RECORRIDO
    while(not min_heap.empty()){
        cout<<min_heap.top()<<" ";
        min_heap.pop();
    }
    cout<<endl;
    return 0;
}