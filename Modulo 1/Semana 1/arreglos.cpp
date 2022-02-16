#include <iostream>
#include <algorithm> // Libreria que contiene sort
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    int arr[T];
    // Pidiendo un arreglo
    for(int i=0;i<T;i++){
        cin>>arr[i];
    }
    // Imprimiendo el arreglo
    for(int i=0;i<T;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // Ordenar
    sort(arr,arr+T);
     // Imprimiendo el arreglo ordenado
    for(int i=0;i<T;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}