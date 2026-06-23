#include<iostream>
using namespace std ;

// Write a program to read date and
// how many days to add to it , print the result on screen 



bool IsLeapYear(short Year){
    return (Year % 400 == 0) || (Year % 4 == 100 && Year % 100 != 0) ;
}


short NumberOfDaysInMnth(short Year , short Month){
    if(Month < 1 || Month > 12)
    return 0 ;
    int Days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return (Month == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : Days[Month -1] ; 
    
}


 int NumberOfDaysFromTheBeginningOfYear(short Year , short Month , short Day){
    
    
    int TotalDays = 0 ;
    for(int i=1 ; i<=(Month-1) ; i++){
        TotalDays += NumberOfDaysInMnth(Year , i) ;
    }
    TotalDays += Day ;
    return  TotalDays ;

 }
 struct sDate{
    short Year ;
    short Month ;
    short Day ;
 };

sDate DateFromDayOrderInAYear(short DayOrderInYear , short Year ){
    sDate Date ;
    
    short RemainingDays = DayOrderInYear ;
    short MonthDays = 0;

    Date.Year = Year ;
    Date.Month = 1 ;

    while(true){

        MonthDays = NumberOfDaysInMnth(Year,Date.Month);

        if(RemainingDays > MonthDays){
            RemainingDays -= MonthDays;
            Date.Month++;
        }
        else{
            Date.Day = RemainingDays ;
            break;
        }
    }
    return Date ;
 }

 sDate DateAddDays(sDate Date , short Days){
    int  RemainingDays = Days + (Date.Year , Date.Month , Date.Day);
    short MonthDays = 0 ;

    Date.Month = 1 ;

    while(true){
        MonthDays = NumberOfDaysInMnth(Date.Year , Date.Month) ;
        if(RemainingDays > MonthDays){

            RemainingDays= RemainingDays - MonthDays ;
            Date.Month++;

            if(Date.Month > 12){
                Date.Month = 1; 
                Date.Year ++ ;
            }

        }
        else{
            Date.Day = RemainingDays ;
            break;
        }
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
    Date.Year = ReadYear() ;
    return Date ;
}

short ReadDaystoAdd(){
    short HowMany ;
    cout << "How Many Days to Add ? ";
    cin >> HowMany ;
    return HowMany ;
}



int main(){

    sDate Date = ReadFullDate() ;
    short Days = ReadDaystoAdd();


    Date = DateAddDays(Date,Days) ;


    cout << "\n\nDate after adding [" <<Days << "] days is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;




system("pause>0");

    return 0;
}