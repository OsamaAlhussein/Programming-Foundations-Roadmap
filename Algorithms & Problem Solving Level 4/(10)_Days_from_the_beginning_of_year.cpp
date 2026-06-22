#include<iostream>
using namespace std ;


//Write a program to print total days from the beginning of year 

bool LeapYear(short Year){
    return (Year % 400 == 0) || (Year % 4 == 100 && Year % 100 != 0) ;
}


short NumberOfDaysInMnth(short Year , short Month){
    if(Month < 1 || Month > 12)
    return 0 ;
    int Days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return (Month == 2) ? ((LeapYear(Year)) ? 29 : 28) : Days[Month -1] ; 
    
}


 int DaysFromTheBeginningOfYear(short Year , short Month , short Day){
    
    
    int TotalDays = 0 ;
    for(int i=1 ; i<=(Month-1) ; i++){
        TotalDays += NumberOfDaysInMnth(Year , i) ;
    }
    TotalDays += Day ;
    return  TotalDays ;

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




int main(){

    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();

    cout << "\n\nNumber of Days from the begining of the year is : " << DaysFromTheBeginningOfYear(Year,Month,Day);

    return 0;
}