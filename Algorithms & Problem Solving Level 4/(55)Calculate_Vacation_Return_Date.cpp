#include<iostream>
using namespace std ;

//Write a program To read Vacation start 
// Date From and VacationDays , then make a 
//function to caluclate the vacation return Date . 
// Note : Weekend are excluded 

struct sDate{
    short Year ;
    short Month;
    short Day ;
};

short DayOfWeekOrder(short Year , short Month , short Day){
    short a = ((14 - Month) / 12) ;
    short y = (Year - a) ;
    short m = Month + (12 * a) - 2 ;
    return (Day + y + (y/4) - (y/100) + (y/400) + (31 * m/12)) % 7 ;
}

short DayOfWeekOrder(sDate Date){
 return DayOfWeekOrder(Date.Year,Date.Month,Date.Day);
}


bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
return (Date1.Year < Date2.Year) ? true : ((Date1.Year==Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month==Date2.Month ? Date1.Day < Date2.Day : false) : false );

}

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
    return (NumberOfDaysInMnth(Date.Year,Date.Month)==Date.Day);
}

bool IsLastMonthInYear(short Month)
{
return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
        Date.Day = 1;
        Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
return Date;
}

bool IsBusinessDay(sDate Date){
    return !(DayOfWeekOrder(Date)==5 || DayOfWeekOrder(Date)==6) ;
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = {
    "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayNames[DayOfWeekOrder];
}

sDate CalculateVacationRetyrnDate(sDate DateFrom, short Days){
    
    
    for(int i=1 ; i<=Days ;i++){
        if(IsBusinessDay(DateFrom)){
        DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        
    }
    return DateFrom ;

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

short ReadVacation(){
    short Days ;
    cout << "Please enter a vacation days ? " ;
    cin >> Days ;
    return Days ;
}

int main(){

    sDate DateFrom , DateTo;
    cout << "\nVacation Starts: ";
    DateFrom = ReadFullDate() ;
    short NumberOfVacation = ReadVacation();

    DateTo = CalculateVacationRetyrnDate(DateFrom,NumberOfVacation);

    cout << "Return Date : " << DayShortName(DayOfWeekOrder(DateTo)) 
    << DateTo.Day <<"/" << DateTo.Month <<"/"<<DateTo.Year ;

    return 0;
}