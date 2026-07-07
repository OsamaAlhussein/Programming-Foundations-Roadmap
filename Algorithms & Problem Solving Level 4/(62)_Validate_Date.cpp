#include<iostream>
using namespace std ;

//Write a perogram to read date and write a 
// function to validate this date 

struct sDate{
    short Day; 
    short Month ;
    short Year ;
};

bool IsLeapYear(short Year){
    return (Year % 400 ==0 && Year % 100 !=0) || (Year % 4 == 0);
}

short NumberOfDaysInMnth(short Year , short Month){
    if(Month < 1 || Month > 12)
    return 0 ;
    int Days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return (Month == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : Days[Month -1] ; 
    
}

bool IsLastDayInMonth(sDate Date){

    return (Date.Day==NumberOfDaysInMnth(Date.Year,Date.Month))  ;
    
}


bool IsValidateThisDate(sDate Date){

    if(IsLastDayInMonth(Date))
    return true ;
    else
    return false ;
}


short  ReadYear(){
    short Year ;
    cout << "Please enter a year ? ";
    cin >> Year ;

    return Year ;
}

short ReadMonth(){
    short Month;
    cout << "Please enter a month ? ";
    cin >> Month ;
    return Month ;
}


short ReadDay(){
    short Day ;
    cout << "Please enter a day ? ";
    cin >> Day ;
    return Day ;
}

sDate ReadFullDate(){
    sDate Date ;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date ;
}

int main(){

sDate Date = ReadFullDate();

if(IsValidateThisDate(Date))
cout << "\nYes , Date is a valide Date .";
else
cout << "\nNo , is Not a valide Date .";

    return 0;
}