#include<iostream>
using namespace std ;

//Write a program to read a date and make a
// function to increase by one day 

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

bool IsLastDayInMonth(sDate Date){

    return (Date.Day==NumberOfDaysInMnth(Date.Year,Date.Month))  ;
    
}

bool IsLastMonth(sDate Date1){
   return (Date1.Month==12) ;
}

sDate IncreaseDateByOneDay(sDate Date){
   
    if(IsLastDayInMonth(Date)){
        Date.Day = 1 ;
        if(IsLastMonth(Date)){
            Date.Month = 1 ;
            Date.Year +=1 ;
        }else{
            Date.Month+=1;
        }
    }
    else{
        Date.Day+=1 ;
    }

    return Date ;
    
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

    sDate Date ;
    Date = ReadFullDate();

    Date = IncreaseDateByOneDay(Date);

    cout << "Date after adding one day is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    system("pause>0");
    return 0;
}