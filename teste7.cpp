#include <iostream>

using namespace std;

class Operacoes{
    private:
        int Oper1;
        int Oper2;
    public:
        Operacoes(int a, int b){
            Oper1 = a;
            Oper2 = b;
        }
        int multiplicacao(){
            return Oper1 * Oper2;
        }
        int getOp1(){
            return Oper1;
        }
        int getOp2(){
            return Oper2;
        }
};

class Operacoes2 : public Operacoes{
    public:
        Operacoes2 (int a, int b) : Operacoes (a, b){};

        int adicao(){
            return getOp1() + getOp2();
        }
        int multiplicacao(){
            int resultado = 0;
            for(int i = 0; i < getOp1(); i++){
                resultado += getOp2();
            }
            return resultado;
        }
};


int main(){
    int a, b;
    cin >> a >> b;
    Operacoes op(a, b);
    cout << "\nResultado: " << op.multiplicacao() << endl;

    Operacoes2 op2(a, b);
    cout << "\nResultado: " << op2.adicao() << endl;

    cout << "\nResultado: " << op2.multiplicacao() << endl;
    return 0;
}