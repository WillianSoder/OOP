#include <iostream>
#include<vector>

using namespace std;

int verificaIgualdade(vector <string> v, int n){
    int igual = 1;
    for(int i = 0; i < n-1; i++){
        if(v[i] != v[i+1]){
            igual = 0;
            break;
        }
    }
    return igual;
}

void imprimeStr(vector <string> v, int n, int igual){
    int tamanho = 0;
    for(int i = 0; i < n; i++){
        tamanho += v[i].size();
    }
    if(igual == 1){
        cout << "Todas strings sao iguais!" << endl;
        cout << "Tamanho total: " << tamanho << endl;
    }
    else if(igual == 0){
        cout << "As strings sao diferentes." << endl;
        for(int i = n-1; i >= 0; i--){
            cout << i << ": " << v[i] << endl;
        }
        cout << "Tamanho total: " << tamanho << endl;
    }
}
int main(){
    vector <string> v;
    int n;

    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }
    
    imprimeStr(v, n, verificaIgualdade(v, n));

    return 0;
}