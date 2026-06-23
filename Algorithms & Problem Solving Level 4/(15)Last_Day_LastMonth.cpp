#include<iostream>
using namespace std ;

// Write a program to read a date and check 
// If it is last Day in Month 
// If it is last Month in year


struct sDate{
    short Year ;
    short Month;
    short Day ;
};

bool IsLeapYear(short Year){
    return (Year % 400 == 0) || (Year % 4 == 100 && Year % 100 != 0) ;
}

short NumberOfDaysInMnth(short Year , short Month){
    if(Month < 1 || Month > 12)
    return 0 ;
    int Days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return (Month == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : Days[Month -1] ; 
    
}

bool IsLastDay(sDate Date){

    return (Date.Day==NumberOfDaysInMnth(Date.Year,Date.Month)) ? true : false ;
    
}

bool IsLastMonth(sDate Date1){
   return (Date1.Month==12) ? true : false ;
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

    sDate Date1 ;

    Date1 = ReadFullDate();


    if(IsLastDay(Date1))
    cout << "\nYea , Day is last Day in Month .";
    else
    cout << "\nNo , Day is Not last Day in Month .";

    if(IsLastMonth(Date1))
    cout << "\nYea , Day is last Month in Year.";
    else
    cout << "\nNo , Day is Not last Month in Year.";

    system("pause>0");

    return 0;
}