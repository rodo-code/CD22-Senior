#include <iostream>
#include <cmath>
using namespace std;

double f(double x){
    return x*x+81*x-54;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double a=0, b=3;
    double med;
    double error = 0.000001;
    do{
        med = (a+b)/2;
        if(f(med)<0){
            a=med;
        }
        if(f(med)>0){
            b=med;
        }
        if(f(med)==0){
            cout<<"RESPUESTA EXACTA x="<<med<<endl;
            return 0;
        }
    }while(abs(f(med))>error);
     cout<<"RESPUESTA APROXIMADA x="<<med<<endl;
    return 0;
}