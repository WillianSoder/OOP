#include <iostream>

using namespace std;

class contaCliente
{
private:
    int Id, Idade, Saldo;
    string Nome, DataNascimento;

public:
    contaCliente(int id, int idade, string nome, string data, int saldo = 0)
    {
        Id = id;
        Idade = idade;
        Nome = nome;
        DataNascimento = data;
        Saldo = saldo;
    }
    virtual void debitar(int valor) = 0; // metodo virtual puro (apenas declaração)

    int getId()
    {
        return Id;
    }
    int getIdade()
    {
        return Idade;
    }
    int getSaldo()
    {
        return Saldo;
    }
    string getNome()
    {
        return Nome;
    }
    string getData()
    {
        return DataNascimento;
    }
    void setSaldo(int X)
    {
        Saldo = X;
    }
    ~contaCliente()
    {
        cout << "FIM!" << endl;
    }
};

class Corrente : public contaCliente
{
private:
    string cpf; // XXX.XXX.XXX-XX
public:
    Corrente(string CPF, int id, int idade, string nome, string data, int saldo = 0) : contaCliente(id, idade, nome, data, saldo)
    {
        cpf = CPF;
    }

    void debitar(int valor)
    {
        // saldo antigo mais valor a ser debitado (taxa de 1%)
        int SaldoNovo = (valor - (valor * 0.01)) + getSaldo();
        setSaldo(SaldoNovo);
    }
    // anuidade de 25 reais
    void PagarAnuidade()
    {
        int Saldo = getSaldo() - 25;
        setSaldo(Saldo);
    }
    string getCpf(){
        return cpf;
    }
    ~Corrente()
    {
        system("cls");
        cout << "Conta Corrente encerrada!!" << endl;
    }
};

class Empresarial : public contaCliente
{
private:
    string cnpj; // XX.XXX.XXX/0001-XX
public:
    Empresarial(string CNPJ, int id, int idade, string nome, string data, int saldo = 0) : contaCliente(id, idade, nome, data, saldo)
    {
        cnpj = CNPJ;
    }
    void debitar(int valor)
    {
        // saldo antigo mais valor a ser debitado (taxa de 0,1%)
        int novoSaldo = getSaldo() + (valor - (valor * 0.001));
        setSaldo(novoSaldo);
    }
    // anuidade de 200 reais
    void PagarAnuidade()
    {
        int novoSaldo = getSaldo() - 200;
        setSaldo(novoSaldo);
    }
    string getCnpj(){
        return cnpj;
    }
    ~Empresarial()
    {
        system("cls");
        cout << "Conta Empresarial encerrada!!" << endl;
    }
};

ostream& operator<<(ostream &stream, Corrente &x){
    stream << "Nome: " << x.getNome() << endl;
    stream << "CNPJ: " << x.getCpf() << endl;
    stream << "Id: " << x.getId() << endl;
    stream << "Data de nascimento: " << x.getData() << endl;
    stream << "Idade: " << x.getIdade() << endl;
    stream << "\nSALDO ATUAL: " << x.getSaldo() << "R$\n" << endl;
    return stream;
} 

ostream& operator<<(ostream &stream, Empresarial &x){
    stream << "Nome: " << x.getNome() << endl;
    stream << "CNPJ: " << x.getCnpj() << endl;
    stream << "Id: " << x.getId() << endl;
    stream << "Data de nascimento: " << x.getData() << endl;
    stream << "Idade: " << x.getIdade() << endl;
    stream << "\nSALDO ATUAL: " << x.getSaldo() << "R$\n" << endl;
    return stream;
} 

int main()
{
    int op = 1;
    while (op == 1)
    {
        int menu1 = 0;
        cout << "Escolha seu tipo de conta: \n"
             << "1 - Corrente\n"
             << "2 - Empresarial\n"
             << "3 - sair\n"
             << endl;
        cin >> menu1;

        if (menu1 == 1)
        {
            cout << "\nDigite seu nome: ";
            string nome;
            cin >> nome;
            cout << "\nDigite seu cpf(XXX.XXX.XXX-XX): ";
            string cpf;
            cin >> cpf;
            cout << "\nDigite sua data de nascimento(XX/XX/XXXX): ";
            string data;
            cin >> data;
            cout << "\nDigite sua idade: ";
            int idade;
            cin >> idade;
            cout << "\nDigite seu id: ";
            int id;
            cin >> id;
            Corrente contaC(cpf, id, idade, nome, data);

        system("cls");
        int ope = 1;
        while(ope = 1){
            int menu;
            cout << "Menu de usuario: \n" << "1 - Debitar (taxa 1%) \n" << "2 - Pagar anuidade(25R$) \n" << "3 - Informacoes: \n" << "4 - Sair \n";
            cin >> menu;
            if(menu == 1){ // debitar
                int x = 0;
                system("cls");
                cout << "Digite o valor a debitar: ";
                cin >> x;
                contaC.debitar(x);
                cout << "Debitado" << (x - (x*0.01)) << "R$\n" << endl;
            }
            else if(menu == 2){ // pagar
                if(contaC.getSaldo() < 25){
                    system("cls");
                    cout << "Saldo insuficiente!!\n" << endl;
                }
                else {
                    system("cls");
                    contaC.PagarAnuidade();
                    cout << "Anuidade paga com sucesso!\n" << "Saldo atual: " << contaC.getSaldo() << endl;
                }
            }
            else if(menu == 3){ // informacoes
                system("cls");
                cout << "INFORMACOES: \n\n" << contaC << endl;
            }
            else if(menu == 4){ // sair
                system("cls");
                cout << "Obrigado" << endl;
                op = 0;
                ope = 0;
                return 0;
            }
            else{
                system("cls");
                cout << "Opcao invalida, digite novamente: " << endl;
            }
        }
        }
        else if (menu1 == 2)
        {
            cout << "\nDigite seu nome: ";
            string nome;
            cin >> nome;
            cout << "\nDigite seu cnpj(XX.XXX.XXX/0001-XX): ";
            string cnpj;
            cin >> cnpj;
            cout << "\nDigite sua data de nascimento(XX/XX/XXXX): ";
            string data;
            cin >> data;
            cout << "\nDigite sua idade: ";
            int idade;
            cin >> idade;
            cout << "\nDigite seu id: ";
            int id;
            cin >> id;
            Empresarial contaE(cnpj, id, idade, nome, data);
            op = 3;

            system("cls");
        int ope = 1;
        while(ope = 1){
            int menu;
            cout << "Menu de usuario: \n" << "1 - Debitar (taxa 0,1%) \n" << "2 - Pagar anuidade(25R$) \n" << "3 - Informacoes: \n" << "4 - Sair \n";
            cin >> menu;
            if(menu == 1){ // debitar
                int x = 0;
                system("cls");
                cout << "Digite o valor a debitar: ";
                cin >> x;
                contaE.debitar(x);
                cout << "Debitado" << (x - (x*0.001)) << "R$\n\n" << endl;
            }
            else if(menu == 2){ // pagar
                if(contaE.getSaldo() < 200){
                    system("cls");
                    cout << "Saldo insuficiente!!\n\n" << endl;
                }
                else {
                    system("cls");
                    contaE.PagarAnuidade();
                    cout << "Anuidade paga com sucesso!\n" << "Saldo atual: " << contaE.getSaldo() << "\n" << endl;
                }
            }
            else if(menu == 3){ // informacoes
                system("cls");
                cout << "INFORMACOES: \n\n" << contaE;
            }
            else if(menu == 4){ // sair
                system("cls");
                cout << "Obrigado" << endl;
                op = 0;
                ope = 0;
                return 0;
            }
            else{
                system("cls");
                cout << "Opcao invalida, digite novamente: " << endl;
            }
        }
        }
        else if (menu1 == 3)
        {
            cout << "\n\nObrigado por usar!" << endl;
            op = 0;
        }
        else
        {
            system("cls");
            cout << "\n!!OPCAO INVALIDA!!\n\n";
            op = 1;
        }
    }
    return 0;
}
