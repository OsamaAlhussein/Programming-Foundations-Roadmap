#include<iostream>
#include<cmath>
using namespace std ;





void PrintFibonacciUsingloop(int Num){
    int FebNumber = 0 ;
    int Priv2 = 0 , Priv1 = 1 ;
    cout << "1   ";
    for(int i=2 ; i<=Num ; i++){
        FebNumber = Priv1 + Priv2 ;
        cout << FebNumber << "   ";
        Priv2 = Priv1 ;
        Priv1 = FebNumber ;

    }
}




int main(){

   PrintFibonacciUsingloop(10);

    system("pause>0");

    return 0;
}