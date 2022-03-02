#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while(getline(cin,s)){
        s+=" ";
        string p="";
        stack<char>pila;
        int falla=0;
        for(int i=0;i<s.size()-1;i++){
            // Buscamos el simbolo (*
            if(s[i]=='(' and s[i+1]=='*'){
                p+="/"; // Concatenar
                i++;
            }
            // Buscamos el simbolo *)
            else if(s[i]=='*' and s[i+1]==')'){
                p+=char(92);
                i++;
            }
            else{
                p+=s[i];
            }
        }
        //cout<<s.size()<<endl;
        //cout<<p<<endl;
        for(int i=0;i<p.size() and falla==0;i++){
            if(p[i]=='(' or p[i]=='[' or p[i]=='{' or p[i]=='<' or p[i]=='/'){
                pila.push(p[i]);
            }  
            if(p[i]==')'){
                if(not pila.empty()){
                    if(pila.top()=='(') pila.pop();
                    else falla=i+1;
                }
                else falla=i+1;
            }
            if(p[i]==']'){
                if(not pila.empty()){
                    if(pila.top()=='[') pila.pop();
                    else falla=i+1;
                }
                else falla=i+1;
            }
            if(p[i]=='}'){
                if(not pila.empty()){
                    if(pila.top()=='{') pila.pop();
                    else falla=i+1;
                }
                else falla=i+1;
            }
            if(p[i]=='>'){
                if(not pila.empty()){
                    if(pila.top()=='<') pila.pop();
                    else falla=i+1;
                }
                else falla=i+1;
            }
            if(p[i]==char(92)){
                if(not pila.empty()){
                    if(pila.top()=='/') pila.pop();
                    else falla=i+1;
                }
                else falla=i+1;
            }
        }
        if(pila.empty() and falla==0) {
            cout<<"YES"<<endl;
        }
        else{
            if(falla!=0) cout<<"NO "<<falla<<endl;
            else cout<<"NO "<<p.size()+1<<endl;
        }
    }
    return 0;
}