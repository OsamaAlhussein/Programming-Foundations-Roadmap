#include<iostream>
#include<string>
#include<cmath>
using namespace std ;

//Prime Number 

enum enPrimNotPrime{Prime = 1 , NotPrime = 2};

float ReadPositiveNumber(string Message){

    float Num =0 ;
    do
    {
        cout << Message << endl ;
        cin >> Num ;
    }while(Num <=0 );

    return Num ;
}


enPrimNotPrime CheckPrime(int Number){

    int M = round(Number/2);
    for(int counter=2 ; counter<=M; counter++){

        if(Number % counter == 0)
         return enPrimNotPrime::NotPrime;
    }
     return enPrimNotPrime::Prime;
}

void PrintNumberType(int Num){

    switch(CheckPrime(Num)){

        case enPrimNotPrime::Prime :
            cout << "The Number is Prime \n";
            break;

        case enPrimNotPrime::NotPrime:
            cout << "The Number is Not Prime\n";
            break;
    }
     
}


int main(){

    PrintNumberType(ReadPositiveNumber("Please enter a positive number?"));


    return 0;
}