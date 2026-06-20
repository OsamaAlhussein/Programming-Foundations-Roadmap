#include<iostream>
using namespace std ;


/*Write a program to print number of :
  Days , Hours , Minutes , Seconds 
  in a certain year */ 

  bool IsLeapYear(short Year){
    return (Year % 400 ==0 && Year % 100 !=0) || (Year % 4 == 0);
  }

  int NumberOfDaysInYear(short Year){
        return (IsLeapYear(Year)) ? 366 : 356 ; 
  }

  int NumberOfHoursInYear(short Year){
        return NumberOfDaysInYear(Year) * 24 ; 
  }
  int NumberOfMinutesInYear(short Year){
        return NumberOfHoursInYear(Year) * 60; 
  }
  int NumberOfSecondsInYear(short Year){
        return NumberOfMinutesInYear(Year) * 60 ; 
  }


  short ReadYear(){
    short Year ;
    cout << "Please enter a year to check ? ";
    cin >> Year ;
    return Year ;
  }

int main(){

  short Year = ReadYear();

      cout << "\nNumber of Days      in Year[ " << Year << "] is : " << NumberOfDaysInYear(Year);

      cout << "\nNumber of Hours     in Year[ " << Year << "] is : " << NumberOfHoursInYear(Year);

      cout << "\nNumber of Minutes   in Year[ " << Year << "] is : " << NumberOfMinutesInYear(Year);

      cout << "\nNumber of Seconds   in Year[ " << Year << "] is : " << NumberOfSecondsInYear(Year);

      system("pause>0");


    return 0;
}