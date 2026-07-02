#include<iostream>
using namespace std ;

//Write a program to read Date1 & Date2
// and check if Date1 is after Date2 or not 

struct sDate{
    short Day ;
    short Month ;
    short Year ;
};

bool IsDate1LessThanDate2(sDate Date1 ,sDate Date2){
   return (Date1.Year < Date2.Year) ? true : ((Date1.Year==Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month==Date2.Month ? Date1.Day < Date2.Day : false) : false );
}

bool IsDateEqualsToDate2(sDate Date1 ,sDate Date2){
   return (Date1.Year == Date2.Year) ? ((Date1.Month==Date2.Month) ? Date1.Day == Date2.Day : false) : false ;
}

bool IsDate1AfterDate2(sDate Date1 , sDate Date2){
    return  (!IsDate1LessThanDate2(Date1,Date2) && IsDateEqualsToDate2(Date1,Date2));
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
    sDate Date1 , Date2 ;
    cout << "\nEnter Date1 : \n";
    Date1 = ReadFullDate();
    cout << "\nEnter Date2 : \n";
    Date2 = ReadFullDate();
    

    if(IsDate1AfterDate2(Date1,Date2))
    cout << "\n\nYes , Date1 is After Date2 .";
    else 
    cout << "\n\nNo , Date1 is not after Date2 .";


    return 0;
}