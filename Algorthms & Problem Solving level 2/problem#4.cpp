#include<iostream>
using namespace std ;

// Perfect Number from 1 To N 

int ReadPositiveNumber(string Message){

    int Num=0;
    do{
        cout << Message << endl ;
        cin >> Num ;

    }while(Num <= 0);

    return Num ;
}

bool isPerfactNumber(int Num){

    int sum =0;
    for(int i=1 ;i<Num ; i++){

        if(Num%i==0){
            sum+=i ;
        }
    }

    return   Num==sum;
}


void PrintPerfectNumbersFrom1ToN(int Num){

    for(int i=1 ; i<=Num ;i++){

        if(isPerfactNumber(i)){

            cout << i << endl ;
        }
    }
}

int main(){

  PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number?"));

    return 0;
}