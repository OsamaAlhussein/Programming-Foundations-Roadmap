#include<iostream>
using namespace std ;


//Write a program to read a date1 , date2 
// and make a function to calculate the difference in day 
// Note : if date2 is less than date1 print the results Minutes 


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

sDate DecraseDateByOneDay(sDate Date){
   
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

bool IsDate1LessThanDate2(sDate Date1 ,sDate Date2){
   return (Date1.Year < Date2.Year) ? true : ((Date1.Year==Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month==Date2.Month ? Date1.Day < Date2.Day : false) : false );
}

void SwapDates(sDate &Date1 , sDate &Date2){
    sDate SwapDates ;

    SwapDates.Day = Date1.Day;
    SwapDates.Month = Date1.Month ;
    SwapDates.Year = Date1.Year ;

    Date1.Day = Date2.Day;
    Date1.Month = Date2.Month;
    Date1.Year = Date2.Year ;

    Date2.Day = SwapDates.Day;
    Date2.Month = SwapDates.Month;
    Date2.Year = SwapDates.Year ;


    
}


int  GetDifferenceInDay(sDate Date1 , sDate Date2 , bool IncludeEndDay=false){

    int Days = 0;
    int SwapFlagValue =1;

    if(! IsDate1LessThanDate2(Date1,Date2)){

        SwapDates(Date1,Date2);
        SwapFlagValue = -1;

    }

    while(IsDate1LessThanDate2(Date1,Date2)){
        Days++;
        Date1 = DecraseDateByOneDay(Date1);
    }


    return IncludeEndDay ? ++Days*SwapFlagValue : Days *SwapFlagValue ;
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

     

         
    cout << "\nDiffrence is : " << GetDifferenceInDay(Date1,Date2) << " Day(s)";
    cout << "\nDiffrence (Including End Day ) is : " << GetDifferenceInDay(Date1,Date2,true) << " Day(s)";

    system("pause>0");


    return 0;
}