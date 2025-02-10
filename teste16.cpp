#include <iostream>

using namespace std;

class Funcionario{
    protected: 
        string nome;
        int id;
        double salarioBase;
    public:
        Funcionario(string n, int ID, double salario){
            nome = n;
            id = ID;
            salarioBase = salario;
        }
        virtual void exibirDados() = 0;
        virtual double calcularSalario() = 0;
};

class FuncionarioHorista : public Funcionario{
    private: 
        int horasTrabalhadas;
        double valorPorHora;
    public: 
        FuncionarioHorista(string nome, int id, double salario, int horas, double valor) : Funcionario (nome, id, salario){
            horasTrabalhadas = horas;
            valorPorHora = valor;
        }
        void exibirDados(){
            cout << *this;
        }
        double calcularSalario(){
            double salarioHoras = horasTrabalhadas * valorPorHora;
            if (salarioHoras > salarioBase){
            return salarioHoras;
            }
            else{
                return salarioBase;
            }
        }
        string getNome(){
            return nome;
        }
        int getId(){
            return id;
        }
        double getSalario(){
            return salarioBase;
        }
        double getValorHoras(){
            return valorPorHora;
        }
        int getHoras(){
            return horasTrabalhadas;
        }
        // Declara a sobrecarga como 'friend' para permitir acesso direto aos atributos
        friend ostream& operator<<(ostream &stream, FuncionarioHorista &fo);
};


ostream& operator<<(ostream &stream, FuncionarioHorista &fo){
    stream << "Nome: " << fo.getNome() << endl;
    stream << "Id: " << fo.getId() << endl;
    stream << "Salario Base: " << fo.getSalario() << endl;
    stream << "Salario Horas -> Horas trabalhadas: " << fo.getHoras() << " X " << "Valor por hora: " << fo.getValorHoras() << " = " << fo.getHoras()*fo.getValorHoras() << endl;
    stream << "\n\nSalario deste mes: " << fo.calcularSalario() << endl;
    return stream;
}


class FuncionarioAssalariado : public Funcionario{
    private:
        double bonus;
    public:
        FuncionarioAssalariado(string nome, int id, double salario, double bon) : Funcionario(nome, id, salario){
            bonus = bon;
        }
        void exibirDados(){
            cout << *this;
        }
        double calcularSalario(){
            return salarioBase + bonus;
        }
        string getNome(){
            return nome;
        }
        int getId(){
            return id;
        }
        double getSalario(){
            return salarioBase;
        }
        double getBonus(){
            return bonus;
        }
        // Declara a sobrecarga como 'friend' para permitir acesso direto aos atributos
        friend ostream& operator<<(ostream &stream, FuncionarioAssalariado &fa);
};
ostream& operator<<(ostream &stream, FuncionarioAssalariado &fa){
    stream << "Nome: " << fa.getNome() << endl;
    stream << "Id: " << fa.getId() << endl;
    stream << "Salario base: " << fa.getSalario() << endl;
    stream << "Bonificacao: " << fa.getBonus() << endl;
    stream << "\n\nSalrio deste mes: " << fa.calcularSalario();
    return stream;
}

int main(){
    Funcionario *f = new FuncionarioHorista("Willian", 97, 250000, 160, 2000);
    FuncionarioHorista* will = dynamic_cast<FuncionarioHorista*>(f);
    will->exibirDados();
    cout << "\n\n ASSALARIADO \n\n";
    FuncionarioAssalariado joao("Joao", 96, 10000, 2500);
    joao.exibirDados();
    return 0;
}