#include<iostream>
using namespace std ;


// Service fee and Sales tax

float ReadPositiveNumber(string Message){

    float Num =0 ;
    do
    {
        cout << Message << endl ;
        cin >> Num ;
    }while(Num <=0 );

    return Num ;
}

float TotalBillAfterSeviceAndTax(float TotalBill){

    return TotalBill * 1.1 * 1.16 ;
}

int main(){

    float TotalBill = ReadPositiveNumber("Please enter Total Bill ?");
    cout << endl ;
    cout << "Total Bill = " << TotalBill << endl ;
    cout << "Total Bill After Service Fee and Sales Tax = "
    << TotalBillAfterSeviceAndTax(TotalBill);

    return 0;
}