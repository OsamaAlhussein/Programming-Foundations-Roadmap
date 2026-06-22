#include<iostream>
#include<string>
using namespace std ;


//Write a program to read a data , and 
// print the day name of week.

short ReadYear(){
    short Year ;
    cout << "Please enter a year ? ";
    cin >> Year ;
    return Year ;
}


short ReadMonth(){
    short Month ;
    cout << "Please enter a month ? ";
    cin >> Month ;
    return Month ;
}


short ReadDay(){
    short Day ;
    cout << "Please enter a day ? ";
    cin >> Day ;
    return Day;
}


short DayOfWeekOrder(short Year , short Month , short Day){
    short a = ((14 - Month) / 12) ;
    short y = (Year - a) ;
    short m = Month + (12 * a) - 2 ;
    return (Day + y + (y/4) - (y/100) + (y/400) + (31 * m/12)) % 7 ;

}

string DayShortname(short DayOfWeekOrder){
    string  arrNameDay[7] = {"Sunday" , "Monday" , "Tuesday" , 
        "Wednesday" , "thursday" , "Friday" , "Saturday"};

        return arrNameDay[DayOfWeekOrder];
}




int main(){


    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();

    

    cout << "\n\nData      : " << Day << "/" << Month << "/" << Year << endl ;
    cout << "Day Order : " <<DayOfWeekOrder(Year,Month,Day)<< endl ;
    cout << "Day Name  : " << DayShortname(DayOfWeekOrder(Year,Month,Day)) ;
 



    return 0;
}