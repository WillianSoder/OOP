#include <iostream>

using namespace std;

class Funcionario{
    private:
        string nome;
        int id;
        double salarioBase;
    public:
        Funcionario(string n, int Id, double s){
            nome = n;
            id = Id;
            salarioBase = s;
        }
        void exibirDados(){
            cout << "\nDados: " << endl;
            cout << "Nome: " << nome << endl;
            cout << "Id: " << id << endl;
            cout << "Salario: " << salarioBase << "\n\n";
        }
        double calcularBonus(){
            double bonus = salarioBase * 0.1;
            return bonus;
        }
        double getSalario(){
            return salarioBase;
        }
};

class Gerente : public Funcionario{
    public:
        Gerente (string n, int Id, double s) : Funcionario (n, Id, s){}
        double calcularBonus(){
            double bonus = getSalario() * 0.2;
            return bonus;
        }
};
class Diretor : public Gerente{
    public:
        Diretor (string n, int Id, double s) : Gerente (n, Id, s){}
        double calcularBonus(){
            return getSalario() * 0.3;
        }
};

int main(){
    Funcionario f1("Willian", 1, 2500);
    Funcionario f2("Veronica", 2, 1500);

    f1.exibirDados();
    cout << "Bonus de f1: " << f1.calcularBonus() << endl;

    f2.exibirDados();
    cout << "Bonus de f2: " << f2.calcularBonus() << endl;

    Gerente g1("teste", 77, 3500);
    g1.exibirDados();
    cout << "Bonus g1: " << g1.calcularBonus() << endl;

    Diretor d1("teste", 77, 3500);
    d1.exibirDados();
    cout << "Bonus g1: " << d1.calcularBonus() << endl;
    return 0;
}