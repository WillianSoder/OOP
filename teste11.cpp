#include <iostream> 
#include <math.h>

using namespace std;

class Figura{
    public:
        virtual double calcArea() = 0; // metodo virtual puro
};

class Retangulo : public Figura{
    private:
        double ladoA;
        double ladoB;
    public: 
    Retangulo(double A, double B){
        ladoA = A;
        ladoB = B;
    }
    double calcArea(){
        return ladoA * ladoB;
    }
};

class Quadrado : public Retangulo{
    public:
        Quadrado(double L) : Retangulo (L, L){} // ambos lados são iguais
};

class Circulo : public Figura{
    private:
        double raio;
    public:
        Circulo(double r){
            raio = r;
        }
        double calcArea(){
            return M_PI * pow(raio, 2);
        }
};

int main(){
    Retangulo R(2, 3);
    Quadrado Q(7);
    Circulo C(2);

    cout << "Area R: " << R.calcArea() << endl;
    cout << "Area Q: " << Q.calcArea() << endl;
    cout << "Area C: " << C.calcArea() << endl;

    return 0;
}