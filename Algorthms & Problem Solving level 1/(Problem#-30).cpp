#include<iostream>
using namespace std ;

// Factorial 

int ReadPositveNumber(string massge){
    int N ;
    do{

           cout << massge << endl;
            cin >> N ;

    }while(N<0);
 

    return N ; 
}

int Factorial(int N){
    
    int Factoria = 1;
    for (int i=N ; i>=1 ; i--){

        Factoria*=i ;
    } 
    return Factoria ;
}




int main(){

cout << Factorial(ReadPositveNumber("Enter N ?"))<< endl ;
    return 0;
}