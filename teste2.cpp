# include <iostream> 
#include <math.h>
#include <cmath>
using namespace std;

class Formas {
    private:
    int Alt, Lar, Raio, Comp;
    public: 

    void setAlt(int H){
        Alt = H;
    } 
    int getAlt(){
        
        return Alt;
    }

    void setLar(int L){
        Lar = L;
    }

    int getLar(){
        return Lar;
    }


    void setRaio(int R){
        Raio = R;
    } 
    int getRaio(){
        return Raio;
    }


    void setComp(int C){
        Comp = C;
    } 
    int getComp(){
        return Comp;
    }
};

class Quadrado : public Formas {
    public:
    Quadrado (int L){
        setLar(L);
    }
    int Area(){
        return getLar() * getLar();
    }
};

class Cubo : public Formas {
    public: 
    Cubo (int L, int H = 0, int C = 0) {
        setLar(L);
        if(H == 0){
            setAlt(L);
        }else{
            setAlt(H);
        }

        if(C == 0){
            setComp(L);
        }else{
            setComp(C);
        }

    }
    int Volume(){
        return getLar() * getAlt() * getComp();
    }
};

class Circulo : public Formas {
    public:
    Circulo (int R){
        setRaio(R);
    }
    int Area(){
        return M_PI * getRaio() * getRaio();    
    }
};

class Cilindro : public Formas {
    public:
    Cilindro (int R, int H ){
        setRaio(R);
        setAlt(H);
    }
    int Volume(){
        return M_PI * getRaio() * getRaio() * getAlt();
    }
};

int main(){
    Quadrado Q(10);
    cout << "Area Quadrado: " << Q.Area() << endl;
    Cubo C(10,20,30);
    cout << "Area Cubo: " << C.Volume() << endl;
    Circulo Cir(10);
    cout << "Area Circulo: " << Cir.Area() << endl;
    Cilindro Cil(10,10);
    cout << "Area Cilindro: " << Cil.Volume() << endl;
    return 0;
}