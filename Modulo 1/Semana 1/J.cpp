#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cp;
    cin>>cp;
    while(cp--){
        string result;
        int conto = 0, res = 0;
        bool seguido = false;
        cin>>result;
        result = result + "X";
        for(int i=0;i<result.size();i++){
            if(result[i]=='O'){
                if(seguido){
                    conto++;
                }
                else{
                    conto=1;
                }
                seguido=true;
            }
            else{ // es una 'X'
                if(seguido){
                    res += (conto)*(conto+1)/2;
                }
                conto=0;
                seguido=false;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}