#include <iostream>

using namespace std;

class Fracao{
    private:
        int numerador;
        int denominador;
    public:
        Fracao(int n, int d){
            numerador = n;
            denominador = d;   
        }
        Fracao(int n){
            numerador = n;
            denominador = 1;
        }
        friend Fracao operator+(Fracao A, Fracao B){
            int novoNumerador, novoDenominador;
            if(A.denominador != 1 && B.denominador != 1){// denominadores diferente de 1 (precisa de mmc)
                int mdc = min(A.denominador, B.denominador);
                while (mdc > 1)
                {
                    if(A.denominador % mdc == 0 && B.denominador % mdc == 0){
                        break;
                    }
                    mdc--;
                }

                novoDenominador = (abs(A.denominador * B.denominador)) / mdc;
                novoNumerador = ( ((novoDenominador / A.denominador)*A.numerador) + ((novoDenominador/B.denominador)*B.numerador) );
            }
            else if (A.denominador == 1){ // denominador de "A" é 1, logo o denominador resultante é o denominador de "B"
                novoDenominador = B.denominador;
                novoNumerador = ((novoDenominador * A.numerador) + B.numerador);
            }
            else if(B.denominador == 1){ // denominador de "B" é 1, logo o denominador resultante é o denominador de "A"
                novoDenominador = A.denominador;
                novoNumerador = (A.numerador + (novoDenominador * B.numerador));
            }
            // mdc para simplificar 
            int  MDC = min(novoNumerador, novoDenominador);
            while (MDC > 1)
            {
                if(novoNumerador % MDC == 0 && novoDenominador % MDC == 0){
                    break;
                }
                MDC--;
            }
            Fracao C(novoNumerador/MDC, novoDenominador/MDC);
            return C;
            
        }
        friend Fracao operator*(Fracao A, Fracao B){
            int novoNumerador = A.numerador * B.numerador;
            int novoDenominador = A.denominador * B.denominador;

            // MDC PARA SIMPLIFICAR
            int mdc = min(novoNumerador, novoDenominador);
            while (mdc > 1)
            {
                if (novoNumerador % mdc == 0 && novoDenominador % mdc == 0){
                    break;
                }
                mdc--;
            }
            
            Fracao C(novoNumerador/mdc, novoDenominador/mdc);
            return C;
        }
        int getNumerador(){
            return numerador;
        }
        int getDenominador(){
            return denominador;
        }
};


ostream& operator<<(ostream &stream, Fracao A){
    stream << A.getNumerador();
    stream << "/";
    stream << A.getDenominador() << endl;
    return stream;
}

int main(){
    Fracao A(255, 178), B(1879, 97);

    cout << "Soma: " << A + B << endl;
    cout << "Produto: " << A * B << endl;

    return 0;
}