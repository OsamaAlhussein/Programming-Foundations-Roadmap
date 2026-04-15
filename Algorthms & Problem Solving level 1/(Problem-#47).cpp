#include<iostream>
using namespace std ;

// Loan Installment Months 

float ReadPositiveNumber(string Message){

    float Num =0 ;
    do
    {
        cout << Message << endl ;
        cin >> Num ;
    }while(Num <=0 );

    return Num ;
}

float TotalMonth(float LoanAmount , float MonthlyInstallment){

    return (float) LoanAmount / MonthlyInstallment ;
}


int main(){

    float LoanAmount = ReadPositiveNumber("Please enter loan Amount ?");
    float MonthlyInstallment = ReadPositiveNumber("Please enter Monthly Installment ?");

    cout << "Total Months to pay = "<< TotalMonth(LoanAmount , MonthlyInstallment);

    return 0;
}