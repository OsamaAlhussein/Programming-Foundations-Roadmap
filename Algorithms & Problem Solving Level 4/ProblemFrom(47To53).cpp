#pragma warning(disable : 4996)
#include<iostream>
#include<ctime>
using namespace std ;

// More Date problems

struct sDate{
    short Day ;
    short Month ;
    short Year ;
};

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
return (Date1.Year < Date2.Year) ? true : ((Date1.Year==Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month==Date2.Month ? Date1.Day < Date2.Day : false) : false );

}

bool IsLeapYear(short Year){
    return (Year % 400 == 0) || (Year % 4 ==0 && Year % 100 != 0) ;
}

short NumberOfDaysInMonth(short Year , short Month){
    if(Month <1 || Month > 12){
        return 0 ;
    }
    
    short DaysNumber[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

   return (Month==2) ? (IsLeapYear(Year) ? 29 : 28) : DaysNumber[Month-1] ;
}

bool IsLastDayInMonth(sDate Date)
{
return (Date.Day == NumberOfDaysInMonth(Date.Month,Date.Year));
}
bool IsLastMonthInYear(short Month)
{
return (Month == 12);
}

short DayOfWeekOrder(short Year , short Month , short Day){
    short a = ((14 - Month) / 12) ;
    short y = (Year - a) ;
    short m = Month + (12 * a) - 2 ;
    return (Day + y + (y/4) - (y/100) + (y/400) + (31 * m/12)) % 7 ;
}

short DayOfWeekOrder(sDate Date){
 return DayOfWeekOrder(Date.Year,Date.Month,Date.Day);
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

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = {
    "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayNames[DayOfWeekOrder];
}


bool IsEndOfWeek(sDate Date){
    return (DayOfWeekOrder(Date)==6) ; 
}

bool IsWeekend(sDate Date){
    // Weekends are thursday
    return (DayOfWeekOrder(Date)==4);
}

bool IsBusinessDay(sDate Date){
    return !(DayOfWeekOrder(Date)==5 || DayOfWeekOrder(Date)==6) ;
}

short DaysUntilTheEndOfWeek(sDate Date){

    return 6 - DayOfWeekOrder(Date);
}

short DaysUntilTheEndOfMonth(sDate Date){
    sDate EndOfMontDate;
    EndOfMontDate.Day = NumberOfDaysInMonth(Date.Year,Date.Month);
    EndOfMontDate.Month = Date.Month;
    EndOfMontDate.Year = Date.Year;

return GetDifferenceInDays(Date, EndOfMontDate, true);

}

int DaysUntilTheEndOfYear(sDate Date){
    sDate EndOfYearDate ;

    EndOfYearDate.Day = 31 ;
    EndOfYearDate.Month = 12 ;
    EndOfYearDate.Year = Date.Year ;

    return GetDifferenceInDays(Date , EndOfYearDate , true);

}

sDate GetSystemDate(){
    sDate Date ;
    time_t t = time(0) ;
    tm * now = localtime(&t);

    Date.Year = now->tm_year + 1900 ;
    Date.Month = now->tm_mon +1 ;
    Date.Day = now->tm_mday ;

    return Date ;

}


int main(){

    sDate Date = GetSystemDate() ;

    cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date)) << " , "<< Date.Day << "/"
    << Date.Month << "/" << Date.Year << endl ;

    //_________________
    cout << "\nIs it End of Week \n";
    if(IsEndOfWeek(Date))
    cout << "Yes it is Saturday, it's of Week.";
    else
    cout << "No it's Not end of week.";
    //_________________
    cout << "\n\nIs it Weekend?\n";
    if(IsWeekend(Date))
    cout << "Yes it is a week end.";
    else
    cout << "No today is " <<
    DayShortName(DayOfWeekOrder(Date)) << ", Not a weekend.";
    //_________________
    cout << "\n\nIs it Business Day?\n";
    if(IsBusinessDay(Date))
    cout << "Yes it is a business day.";
    else 
    cout << "No it is NOT a business day.";
    //_________________
    cout << "\n\nDays until end of week : "
    <<DaysUntilTheEndOfWeek(Date) << " Day(s).";
    //_________________
    cout << "\nDays until end of month : "
    <<DaysUntilTheEndOfMonth(Date) << " Day(s).";
    //_________________
    cout << "\nDays until end of year : "
    << DaysUntilTheEndOfYear(Date) << " Day(s).";

    system("pause>0");

    return 0;
}