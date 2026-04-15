#include<iostream>
using namespace std ;

// Minthly loan Installment 
float ReadPositiveNumber(string Message){

    float Num =0 ;
    do
    {
        cout << Message << endl ;
        cin >> Num ;
    }while(Num <=0 );

    return Num ;
}

float MonthlyInstallment(float LoanAmount , float HowManyMonth){

    return (float) LoanAmount / HowManyMonth ;
}


int main(){

       float LoanAmount = ReadPositiveNumber("Please enter loan Amount ?");
    float HowManyMonth = ReadPositiveNumber("How Many month ?");

    cout << "Month Installment = "<< MonthlyInstallment(LoanAmount , HowManyMonth);


    return 0;
}