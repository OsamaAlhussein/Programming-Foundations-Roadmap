#include<iostream>
using namespace std ;


class clsA{

    public:
    static int Function1(){
        return 20 ;
    }

    int Function2(){
        return 10 ;
    }
    
};


int main(){

    clsA A1 , A2 , A3 ;

    cout <<clsA::Function1() << endl ;
    // cout << clsA::Function2() << endl   Error;
    
    cout << A1.Function1()<< endl ;
    cout << A1.Function2();

    

    return 0;
}
