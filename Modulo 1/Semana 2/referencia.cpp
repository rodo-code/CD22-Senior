#include <iostream>

using namespace std;

int a = 7;

void imprimirHora(){
    cout<<"Holi"<<endl;
    cout<<a<<endl;
}

void aumentarMinuto(int &h,int &m){
    m++;
    if(m==60){
        m = 0;
        h++;
    }
    if(h==24){
        h=0;
    }
    imprimirHora();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h=17,m=59;
    aumentarMinuto(h,m);
    cout<<h<<":"<<m<<endl;
    return 0;
}

