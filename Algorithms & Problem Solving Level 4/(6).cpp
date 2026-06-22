#include<iostream>
using namespace std ;

// Write a program to print Number of Days in a certain Month
// Note : Tow line logic



bool IsLeapYear(short Year){
    return (Year % 400 == 0 && Year % 100 != 0) || (Year % 4 ==0) ;
}

short NumberOfDaysInMonth(short Year , short Month){

if(Month < 1 || 12 < Month){
    return 0 ;
}
 
    int NumberOfDays[13] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return (Month == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : NumberOfDays[Month - 1] ;

}




short ReadYear(){
    short Year ;
    cout << "Please enter a year to check ? ";
    cin >> Year ;
    return Year ;
  }

 short ReadMonth(){
    short Month ;
    cout << "Please enter a Month to check ? ";
    cin >> Month ;
    return  Month ;
 } 

int main(){

    short Year = ReadYear() ;
    short Month =  ReadMonth();

    cout << "\nNumber of Days in Month[" << Month << "] is : " <<NumberOfDaysInMonth(Year,Month);

    system("pause>0");


    return 0;
}

