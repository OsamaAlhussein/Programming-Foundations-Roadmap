#include<iostream>
using namespace std ;

//Write a program to Read date1 , date1
// check if date1 is less than date2


struct sDate{
    short Year ;
    short Month;
    short Day ;
};



bool IsDate1EqualsToDate2(sDate Date1 ,sDate Date2){
   return (Date1.Year < Date2.Year) ? true : ((Date1.Year==Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month==Date2.Month ? Date1.Day < Date2.Day : false) : false );
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

    Date1 = ReadFullDate();
    cout << "\n\n";
    Date2 = ReadFullDate();



    if(IsDate1EqualsToDate2(Date1,Date2))
    cout << "\nYes , Date1 is Less than Date2 .";
    else
    cout << "\nNo , Date1 is not Less than Date2 .";


    system("pause>0");

    return 0;
}