#include <iostream> 

using namespace std;

class Veiculo{
    protected:
        string marca;
        string modelo;
        double precoBasePorDia;
    public: 

        Veiculo(string mar, string mod, double preco){
            marca = mar;
            modelo = mod;
            precoBasePorDia = preco;
        }

        virtual void exibirDetalhes() = 0;

        int calcularCustoAluguel(int dias){
            return dias * precoBasePorDia;
        }

};

class Carro : public Veiculo{
    private:
        int numPortas;
    public:
        Carro(string marc, string mod, double preco, int num) : Veiculo(marc, mod, preco){
            numPortas = num;
        }
        void exibirDetalhes(){
            cout << *this;
        }
        int calcularCustoAluguel(int dias){
            if(dias > 7){
                return dias*precoBasePorDia+50;
            }
            else{
                return dias*precoBasePorDia;
            }
        }
        string getModelo() {
            return modelo;
        }
        string getMarca() {
            return marca;
        }
        double getPreco() {
            return precoBasePorDia;
        }
        int getPortas() {
            return numPortas;
        }
        // Declara a sobrecarga como 'friend' para permitir acesso direto aos atributos
        friend ostream& operator<<(ostream &stream, Carro& c);
};

class Moto : public Veiculo{
    private:
        int cilindradas;
    public:
        Moto(string marc, string mod, double preco, int cili) : Veiculo (marc, mod, preco){
            cilindradas = cili;
        }
        void exibirDetalhes(){
            cout << *this;
        }
        int calcularCustoAluguel(int dias){
            if(dias > 5){
                double valor = (dias*precoBasePorDia) - (dias*precoBasePorDia*0.1);
                return valor;
            }
            else{
                return dias*precoBasePorDia;
            }
        }
        string getModelo(){
            return modelo;
        }
        string getMarca(){
            return marca;
        }
        double getPreco(){
            return precoBasePorDia;
        }
        int getCilindradas(){
            return cilindradas;
        }
        // Declara a sobrecarga como 'friend' para permitir acesso direto aos atributos
        friend ostream& operator<<(ostream &stream, Moto &m);
};

ostream& operator<<(ostream &stream, Carro& c){
    stream << "Marca: " << c.getMarca() << endl;
    stream << "Modelo: " << c.getModelo() << endl;
    stream << "Numero de Portas: " << c.getPortas() << endl;
    stream << "Preco por dia: " << c.getPreco() << endl;
    return stream;
}

ostream& operator<<(ostream &stream, Moto &m){
    stream << "Marca: " << m.getMarca() << endl;
    stream << "Modelo: " << m.getModelo() << endl;
    stream << "Numero de Portas: " << m.getCilindradas() << endl;
    stream << "Preco por dia: " << m.getPreco() << endl;
    return stream;
}

int main(){
    Veiculo* v = new Carro("Chevrolet", "Cruze", 300, 4);
    Carro* c = dynamic_cast<Carro*>(v);
    cout << "Aluguel de 8 dias(CARRO): " << c->calcularCustoAluguel(8) << "\n\n";
    c->exibirDetalhes();

    Moto m("Yamaha", "MT-09", 100, 900);
    cout << "\n\nAluguel de 6 dias(MOTO)" << m.calcularCustoAluguel(6) << "\n\n";
    m.exibirDetalhes();
    return 0;
}
