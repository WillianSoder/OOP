#include <iostream>
#include <math.h>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;

class Fracao {
    private:
        int numerador;
        int denominador;
    public:
        Fracao(int N, int D){
            numerador = N;
            denominador = D;
        }
        Fracao(int N){
            numerador = N;
            denominador = 1;
        }
        friend Fracao operator+(Fracao A, Fracao B){
            int denominador, numerador;

            if(A.denominador != B.denominador){ // se precisar calcular o mmc


             int mdc = min(A.denominador, B.denominador); // mdc para calcular o mmc (MDc de A e B)

            while (mdc > 1)
            {
                if(A.denominador%mdc==0 && B.denominador%mdc == 0)
                    break;
                else
                mdc--;
            }
            
            denominador = (A.denominador * B.denominador) / mdc;
            denominador = denominador / mdc;

            int a, b; 
            a = (denominador / A.denominador) * A.numerador;
            b = (denominador / B.denominador) * B.numerador;
            numerador = a + b;
            numerador = numerador / mdc;
            }else if(A.denominador == B.denominador){ // se os denominadores forem iguais
                denominador = (A.denominador); 
                numerador = (A.numerador + B.numerador);
            }

            int mdc = min(numerador, denominador); // mdc para simplificar (MDC entre numerador e denominador)

            while (mdc > 1)
            {
                if(numerador%mdc==0 && denominador%mdc == 0)
                    break;
                mdc--;
            }
            
            Fracao Resultado(numerador/mdc, denominador/mdc);
            return Resultado;
        }

        friend Fracao operator*(Fracao A, Fracao B){
            int numerador, denominador;
            numerador = A.numerador * B.numerador;
            denominador = B.denominador *A.denominador;

            int mdc = min(numerador, denominador); // mdc para simplificar (MDC entre numerador e denominador)

            while (mdc > 1)
            {
                if(numerador%mdc==0 && denominador%mdc == 0)
                    break;
                mdc--;
            }

            Fracao resultado(numerador/mdc, denominador/mdc);
            return resultado;
        }
        int getNumerador(){
            return numerador;
        }
        int getDenominador(){
            return denominador;
        }
};

ostream& operator<<(ostream &stream, Fracao Resultado){
    stream << Resultado.getNumerador();
    stream << "/";
    stream << Resultado.getDenominador();
    return stream;
}

int main(){
    Fracao A(4,6), B(3);
    cout << "Soma: " << A +B << endl;
    cout << "Produto: " << A * B << endl; 

    return 0;
}