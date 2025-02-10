#include <iostream>

using namespace std;

class ContaBancaria{
    private:
        int numeroConta;
        int senha;
        string titular;
        double saldo;
    public:
        ContaBancaria(int num, string nome, int sald = 0){
            numeroConta = num;
            titular = nome;
            saldo = sald;
        }
        void depositar(double valor){
            saldo += valor;
        }
        void setSenha(int s){
            senha = s;
        }
        void sacar(double valor){
            int s, op = 0;
            while (op == 0)
            {
            cout << "Digite a senha: ";
            cin >> s;
            cout << endl;
            if(senha == s){
            saldo -= valor;
            op = 1;
            break;
            } else {
                cout << "\nSenha Incorreta!!\n";
            }
            }
        }
        double getSaldo(){
            return saldo;
        }
        void exibirDados(){
            cout << "\nDados: \n" << "Titular da conta: " << titular << "\n" << "Numero da conta: " << numeroConta << "\n" << "Saldo atual: " << saldo << "R$" << endl;
        }
};

class contaPoupanca : public ContaBancaria {
    public:
        contaPoupanca(int num, string nome, double sald = 0) : ContaBancaria (num, nome, sald){}
        void calcJuros(){
            cout << "\n\nSeu saldo eh de: " << getSaldo() << "R$" << endl;
            cout << "Nossa taxa mensal de juros e de 1,3%" << endl;
            cout << "Portanto sua conta rende " << getSaldo()*0.013 << "R$ ao mes! \n\n"; 
        }
};


int main(){
    ContaBancaria c1(1001, "Joao Silva", 500);
    c1.setSenha(1234);
    ContaBancaria c2(1002, "Willian Soder", 10000);
    c2.setSenha(5678);

    c1.exibirDados();
    c1.depositar(2000);
    c1.sacar(100);
    c1.exibirDados();
    cout << "\n\nCONTA 2 \n\n";
    c2.exibirDados();
    c2.depositar(2000);
    c2.sacar(100);
    c2.exibirDados();

    contaPoupanca c3(97, "Veronica demetrio", 5000);
    cout << "\n\nCONTA 3 \n\n";
    c3.exibirDados();
    c3.calcJuros();
    return 0;
}