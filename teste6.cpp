#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int tamanhoTotalStrings(vector <string> V, int N){
    int tamanho = 0;
    for(int i = 0; i < N; i++){
        tamanho += V[i].size();
    }
    return tamanho;
}

void verificaIgualdade (vector <string> V, int N){
    int igual = 1;
    for (int i = 0; i < N; i++){
        if((i< N-1) && (V[i] != V[i+1])){
            igual = 0;
            break;
        }
    }
    int tam =  tamanhoTotalStrings(V, N);
    if(igual == 1){
        cout << "Todas as strings sao iguais!\n" << "tamanho total: " << tam << endl; 
    }else if(igual == 0){
        cout << "As strings sao diferentes. \n" << endl;
        for(int i = N-1; i >= 0; i--){
            cout << i << ": " << V[i] << endl;
        }
        cout << "tamanho total: " << tam << endl; 
    }

}

int main(){
    vector <string> v;
    int n;
    string s;
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> s;
        v.push_back(s);
    }
    /*int tam =  tamanhoTotalStrings(v, n);
    int igual = verificaIgualdade(v, n);
    if(igual == 1){
        cout << "Todas as strings sao iguais!\n" << "tamanho total: " << endl; 
    }else if(igual == 0){
        cout << "As strings sao diferentes. \n" << endl;
        for(int i = n-1; i >= 0; i--){
            cout << i << ": " << v[i] << endl;
        }
        cout << "tamanho total: " << endl; 
    }*/
   verificaIgualdade(v, n);
    return 0;
}