#include<iostream>
#include<string>
using namespace std ;

// Write a program to check if year is a leap year or not 

short ReadYear(){
    short Year ;
    cout << "\nEnter a Year ? ";
    cin >> Year ;
    return Year ;
}


bool  IsLeapYear(short Year){
//leap year if perfectly divisible by 400
    if(Year % 400 == 0){
        return true ;
    }
    // not a leap year if divisible by 100 
    // but not divisble by 400 
    else if(Year % 100 == 0){
        return false ;
    }
    // leap year if not divisble by 100 
    // but divisible by 4 
    else if (Year % 4 == 0){
        return true ;
    }
    // all other years are not leap years 
    else{
        return false ; 
    }
}

int main(){

    short Year = ReadYear();

    if(IsLeapYear(Year))
    cout << "\nYes, Year [" << Year << "] is a leap year.\n";
    else 
    cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n";




    return 0;
}