#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class Punto{
    private:
        T x, y;
    public:
        Punto(const T u, const T v) : x(u), y(v){}
        T getX(){return x;}
        T getY(){return y;}
        void imprimir(){
         cout<<"("<<x<< " , " <<y<<")"<<endl;
        }
};

template <typename T>
class Cambios{

    private:
        int size;
        Punto * punto;

    public:
        Cambios(){
            this -> size = 0;
            this -> punto = new Punto[0];
        }

        Cambios(Punto arr[], int size){
            this -> size = size;
            this -> punto = new Punto[size];
            for (Punto i = 0; i < size; i++){
                punto[i] = arr[i];
            }
        }

        void resize(int &size, int n){
            size += n;
            T *arr = new Punto[size];
            for (int i = 0; i < size; i++){
                arr[i] = punto[i];
            }
            delete[] punto;
            punto = arr;
        }

        void insertLast(Punto punto1){
            resize(size, 1);
            punto[size-1] = punto;
        }

        void insert(Punto punto1, int pos){
            resize(size, 1);
            for(int i = size-1; i > pos; i--){
                punto[i] = punto[i-1];
            }
            punto[pos] = punto1;
        }

        void remove(int pos){
            if(pos >= 0 && pos < size){
                for(int i = pos; i < size; i++){
                    punto[i] = punto[i+1];
                }
            }
            resize(size, -1);
        }
};

int main(){
    Punto<int> p0(11,10);
    p0.imprimir();
    Punto p1,p2,p3,p4;
    int x1,x2,x3,x4;
    int y1,y2,y3,y4;

    Punto arr[] = {per1, per2};
    Cambios P(arr, 2);

    cout<<"Comenzaremos este array con 2 Puntos: "<<endl;

    cout<<"Ingrese los datos del primer Punto: "<<endl;
    cout<<"X: ";cin>>x1;
    cout<<"Y: ";cin>>y1;
    cout<<"Punto creado!!!"<<endl;

    cout<<"Ingrese los datos del segundo Punto: "<<endl;
    cout<<"X: ";cin>>x2;
    cout<<"Y: ";cin>>y2;
    cout<<"Punto creado!!!"<<endl;

    p1.getX(x1);
    p1.getY(y1);

    p2.getX(x2);
    p2.getY(y2);


    cout<<"Mostrando lista de Puntos: " << endl;
    P.imprimir();

    cout<<"Agregamos un Punto con nuestra funcion insertLast: ";
    cout<<"Ingrese los datos del tercer Punto: "<<endl;
    cout<<"X: ";cin>>x3;
    cout<<"Y: ";cin>>y3;
    cout<<"Punto creado!!!"<<endl;

    p3.getX(x3);
    p3.getY(y3);
    P.insertLast(p3);
    cout<<"Imprimiendo el nuevo arreglo: " << endl;
    P.imprimir();

    int pos;
    cout<<"Ahora usaremos el remove, escoga la posicion: ";
    cin>>pos;
    P.remove(pos-1);
    cout<<"Arreglo actualizado: " << endl;
    P.imprimir();

    int pos1;
    cout<<"Agregamos un Punto con nuestra funcion insert: ";
    cout<<"Ingrese los datos del cuarto Punto: "<<endl;
    cout<<"X: ";cin>>x4;
    cout<<"Y: ";cin>>y4;
    cout<<"Punto creado!!!"<<endl;
    cout<<"Ingrese la posicion para colocar al Punto: ";
    cin>> pos1;

    p4.getX(x4);
    p4.getY(y4);
    P.insert(p4,pos1-1);
    cout<<"Imprimiendo arreglo final: " << endl;
    P.imprimir();

    return 0;
}
