#include <iostream>
#include <math.h>

using namespace std;

class Ponto{
    private:
        double x, y;
    public:
        Ponto(int X, int Y){
            x = X;
            y = Y;
        }
        double getX(){
            return x;
        }
        double getY(){
            return y;
        }
        double distanciParaPonto(Ponto p){
            double dist = sqrt( ( (pow((p.getX()-x), 2)) + (pow((p.getY()-y), 2)) ) );
            return dist;
        }
};

class Reta{
    private:
        double A, B, C;
    public:
        Reta(Ponto p1, Ponto p2){
            A = p1.getY() - p2.getY();
            B = p2.getX() - p1.getX();
            C =( ( (-p1.getX()) * (p1.getY() - p2.getY()) ) + ( (-p1.getY()) * (p2.getX() - p1.getX()) ) );
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
            double numerador  = abs((A*p.getX())+(B*p.getY())+C);
            double denominador = sqrt (pow(A, 2) + pow(B, 2));
            return numerador/denominador;
        }
};
ostream& operator<<(ostream &stream, Reta R){
    if(R.getA() > 0){
        stream << "+ ";
    } else if(R.getA() < 0){
        stream << "- ";
    }
    stream << abs(R.getA()) << "x ";


    if(R.getB() > 0 ){
        stream << "+ ";
    }else if(R.getB()<0){
        stream << "- ";
    }
    stream << abs(R.getB()) << "y ";


    if(R.getC() > 0){
        stream << "+ ";
    }else if(R.getC() < 0){
        stream << "- ";
    }
    stream << abs(R.getC()) << endl;
    return stream;
}

int main(){
    Ponto A(1, 2);
    Ponto B(4, 4);
    Ponto C(4, 2);
    cout << "Distancia AB: " << A.distanciParaPonto(B) << endl;
    Reta R(A, B);
    cout << "R: " << R;
    cout << "distancia RC: " << R.distanciaParaPonto(C) << endl;
    return 0;
}