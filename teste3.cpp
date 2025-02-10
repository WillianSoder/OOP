#include <iostream>
# include <math.h>

using namespace std;

class Figura {
    public: 
        virtual double calcArea() = 0;
};

class Retangulo : public Figura {
    protected: 
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
        // quando construir um quadrado construa um retanagulo com o lado A e B igual L (quadrado é um retangulo especial)
        Quadrado (double L) : Retangulo (L, L){}
};

class Circulo : public Figura {
    private:
        double raio;
    public:
        Circulo (double r){
            raio = r; 
        }
        double calcArea(){
            return M_PI * raio * raio;
        }
};

int main(){

    Retangulo R(2,3);
    Quadrado Q(7);
    Circulo C(2);
    cout << "Area R: " << R.calcArea() << endl;
    cout << "Area Q: " << Q.calcArea() << endl;
    cout << "Area C: " << C.calcArea() << endl;

    return 0;
}