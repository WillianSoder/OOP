#include <iostream>
#include <string>

using namespace std;

// criando a classe pessoa
class Pessoa{ 
    protected:
        int Id;
        int Idade;
        string Nome;
        string DataNascimento;
    public:
        // construtor (com valores padrão)
        Pessoa (int id = 0, int idade = 0, string nome = "Nao definido", string data = "Nao Definido" ){
            cout << "Objeto pessoa criado" << endl;
            Id = id; 
            Nome = nome; 
            Idade = idade; 
            DataNascimento = data;
        }

        int getId(){
            return Id;
        }
        void setId(int id){
            Id = id;
        } 

        int getIdade(){
            return Idade;
        }
        void setIdade(int idade){
            Idade = idade;
        } 

        string getNome(){
            return Nome;
        }
        void setNome(string nome){
            Nome = nome;
        } 

        string getNascimento(){
            return DataNascimento;
        }
        void setNascimento(string data){
            DataNascimento = data;
        } 

        void ImprimePessoa(){
            cout << "Id:" << Id << "\nmeu nome eh " << Nome << " Tenho " << Idade << " anos " << "\nNasci dia: " << DataNascimento << endl;
        }

        ~Pessoa(){
            cout << "Pessoa destruida" << endl;
        }
};

// Herança e sobrecarga
 class Juridica : public Pessoa{
    private: 
        string cnpj;
    public:
    Juridica (string doc = "XX.XXX.XXX/0001-XX") : Pessoa(){
        cnpj = doc;
    }
    void setCnpj (string doc){
        cnpj = doc;
    }
    string getCnpj(){
        return cnpj;
    }
void ImprimePessoa(){
        cout << "Sobrecarga de 'imprime pessoa': " << endl;
            cout << "Id:" << Id << "\nMeu nome eh " << Nome << ". Sou pessoa JURIDICA e Tenho " << Idade << " anos "
             << "\nNasci dia: " << DataNascimento << "\nCnpj: " << cnpj <<endl;
        }
 };

  class Fisica : public Pessoa{
    private: 
        string cpf;
    public:
    Fisica (string doc = "XXX.XXX.XXX-XX") : Pessoa(){
        cpf = doc;
    }
    void setCpf (string doc){
        cpf = doc;
    }
    string getcpf(){
        return cpf;
    }
void ImprimePessoa(){
        cout << "Sobrecarga de 'imprime pessoa': " << endl;
            cout << "Id:" << Id << "\nMeu nome eh " << Nome << ". Sou pessoa FISICA e Tenho " << Idade << " anos "
             << "\nNasci dia: " << DataNascimento << "\nCpf: " << cpf <<endl;
        }
 };

int main(){
    // testando classes 
   /*
    Pessoa willian;
    cout << "Antes de definir: \n";
    willian.ImprimePessoa();
    willian.setId(01);
    willian.setIdade(22);
    willian.setNascimento("21/10/2002");
    willian.setNome("Willian Soder");
    cout << "Apos  definir: " << endl;
    willian.ImprimePessoa();

    system("pause");
    cout << "\nImprimindo pessoa pela main:\n" << "Nome: " << willian.getNome() << "\nId: " << willian.getId() << "\nIdade: " << willian.getIdade() << "\nNasciemnto: " << willian.getNascimento() << endl;
   

    system ("pause");
    // testando contrutor e destrutor
    system ("cls");
    Pessoa indefinido;
    indefinido.ImprimePessoa(); 
    */

   // Herança
   Juridica willian("77.777.777/0001-77");
    willian.setId(01);
    willian.setIdade(22);
    willian.setNascimento("21/10/2002");
    willian.setNome("Willian Soder");
    willian.ImprimePessoa();

    cout << endl; 
    system("pause");
    Fisica veronica;
    veronica.setId(02);
    veronica.setIdade(19);
    veronica.setNascimento("24/09/2005");
    veronica.setNome("Veronica Demetrio");
    veronica.ImprimePessoa();


    return 0;
}
