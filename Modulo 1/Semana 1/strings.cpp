#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<256;i++){
        cout<<i<<": "<<(char)i<<endl;
    }
    string palabra;
    cin>>palabra;
    // 65 al 90 son mayusculas
    // 97 al 122 son minusculas
    for(int i=0;i<palabra.size();i++){
        int ascii = int(palabra[i]);
        if(ascii>=65 && ascii<=90){// Pregunta para saber si es mayuscula
            palabra[i]=char(palabra[i]+32);
        }
    }
    cout<<palabra<<endl;
    return 0;
}