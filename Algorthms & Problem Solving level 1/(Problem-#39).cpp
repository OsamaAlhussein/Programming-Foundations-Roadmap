#include<iostream>
using namespace std ;

// Pay Remainder

float ReadPositiveNumber(string Message){

    float Num =0 ;
    do
    {
        cout << Message << endl ;
        cin >> Num ;
    }while(Num <=0 );

    return Num ;
}


float CalculatRemainder(float TotalBill ,float TotalCashPaid){
    return TotalCashPaid - TotalBill ;
}


int main(){

    float TotalBill = ReadPositiveNumber("Please enter Total Bill ?");
    float TotalCashPaid = ReadPositiveNumber("Please enter Total Cash Paid ?");
    cout << endl;

    cout << "Total Bill = "<< TotalBill << endl ;
    cout << "Total Cash Paid = " << TotalCashPaid << endl ;

    cout << "\n********************************\n\n";
    cout << "Remainder = " << CalculatRemainder(TotalBill,TotalCashPaid) ;


    return 0;
}