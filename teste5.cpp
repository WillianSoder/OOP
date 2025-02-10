#include <iostream> 
#include <cmath>
using namespace std;

class Ponto {
    private:
        double x;
        double y;
    public: 
        Ponto(double X, double Y){
            x = X;
            y = Y;
        }
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
        double distanciaParaPonto(Ponto p){
            double distancia = sqrt( (pow((p.getX() - x), 2)) + (pow((p.getY() - y), 2)));
            return distancia;
        }
};

class Reta {
    private:
        double A;
        double B;
        double C;
    public: 
        Reta(Ponto p1, Ponto p2){
            A = p1.getY() - p2.getY(); // y1 - y2
            B = p2.getX() - p1.getX(); // x2 - x1
            C = (-p1.getX() * (p1.getY() - p2.getY())) + (-p1.getY() * (p2.getX() - p1.getX())); // -x1(y1 - y2) -y1(x2 - x1)
        }
        double getA(){
            return A;
        }
        double getB(){
            return B;
        }
        double getC(){
            return C;
        }
        double distanciaParaPonto(Ponto p){
            double numerador = fabs( ((A * p.getX()) + (B * p.getY()) + C) ) ; 
            double denominador = sqrt( ((pow(A, 2)) + (pow(B, 2)) ) );
            double distancia = numerador / denominador;
            return distancia;
        }

};

ostream& operator<<(ostream &stream, Reta R){
    stream << R.getA();
    stream << "x";
    if (R.getB() >= 0)
        stream << " +";
    else stream << " ";
    stream << R.getB();
    stream << "y";
    if (R.getC() >= 0)
        stream << " +";
    else stream << " ";
    stream << R.getC();
    return stream;
} 

int main(){
    Ponto A(1, 2);
    Ponto B(4, 4);
    Ponto C(4, 2);

   cout << "distancia AB = " << A.distanciaParaPonto(B) << endl;
   Reta R(A, B);
   cout << "R: " << R << endl;
   cout << "Distancia RC: " << R.distanciaParaPonto(C) << endl;

    return 0;
}
