#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b,c;
    cin>>a>>b>>c;
    int initial_pos = 0;
    int encontrado_pos = a.find(b,initial_pos);
    string res = "";
    while(encontrado_pos!=-1){
        //cout<<"Encontrado"<<endl;
        //cout<<"Initial pos="<<initial_pos<<endl;
        //cout<<"Encontrado pos="<<encontrado_pos<<endl;
        string parte = a.substr(initial_pos,(encontrado_pos-initial_pos));
        //cout<<parte<<endl;
        res = res + parte + c;
        initial_pos = encontrado_pos + b.size();
        encontrado_pos = a.find(b,initial_pos);
    }
    cout<<res<<endl;
    return 0;
}