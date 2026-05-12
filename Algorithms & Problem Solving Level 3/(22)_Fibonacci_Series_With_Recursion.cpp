#include<iostream>
using namespace std ;


void PrintFibonacciUsingRecursion(int Num, int Priv1 , int Priv2){
    int FebNumber = 0 ;
    
    if(Num > 0){
        FebNumber = Priv1+Priv2 ;
        Priv2 = Priv1 ;
        Priv1 = FebNumber ;
         cout << FebNumber << "   " ;

    

    PrintFibonacciUsingRecursion(Num-1,Priv1,Priv2);


    }
   
    
}

int main(){

    PrintFibonacciUsingRecursion(10,0,1);

    return 0;
}