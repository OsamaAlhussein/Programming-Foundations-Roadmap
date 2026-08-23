#include<iostream>
using namespace std ;


class clsA{

    public:
    int var ;
    static int counter ;

    clsA(){
        counter++;
    }

    void Print(){
        cout << "\nVar : " << var ;
        cout << "\n Counter : " << counter ;

    }

};

int clsA::counter = 0 ; //Static Variable initialisation outside the class 

int main(){

    clsA A1 , A2 , A3 ;

    A1.var=10;
    A2.var =20 ;
    A3.var = 30 ;

    A1.Print();
    A2.Print();
    A3.Print();

    A1.counter=500 ;
    cout << "\n\nAfter chaning the static member counter in one object :\n";
    A1.Print();
    A2.Print();
    A3.Print();

    

    return 0;
}
