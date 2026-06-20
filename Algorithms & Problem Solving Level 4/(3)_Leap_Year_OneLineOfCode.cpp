#include<iostream>
using namespace std ;

// Write a program to check if year is a leap year or not
// Solve Leap year problem with one line of code only 
// use logical Operators 

bool IsLeapYear(short Year){
    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (Year % 400 == 0 && Year % 100 != 0 ) || (Year % 4 == 0) ;
}


short ReadYear(){
    short Year ;
    cout << "\nEnter a Year ? ";
    cin >> Year ;
    return Year ;
}

int main(){

        short Year = ReadYear();

    if(IsLeapYear(Year))
    cout << "\nYes, Year [" << Year << "] is a leap year.\n";
    else 
    cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n";

    system("pause>0");

    return 0;
}