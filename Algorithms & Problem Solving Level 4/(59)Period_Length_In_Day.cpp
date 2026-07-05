#include<iostream>
using namespace std ;

//Weite a program to read a period and 
//calculate period length in days ? 


struct sDate{
    short Day; 
    short Month ;
    short Year ;
};

struct stPeriod{
    sDate StartDate ;
    sDate EndDate ;
};

bool IsDate1BeforThanDate2(sDate Date1 ,sDate Date2){
   return (Date1.Year < Date2.Year) ? true : ((Date1.Year==Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month==Date2.Month ? Date1.Day < Date2.Day : false) : false );
}

bool IsDateEqualsToDate2(sDate Date1 ,sDate Date2){
   return (Date1.Year == Date2.Year) ? ((Date1.Month==Date2.Month) ? Date1.Day == Date2.Day : false) : false ;
}

bool IsDate1AfterDate2(sDate Date1 , sDate Date2){
    return  (!IsDate1BeforThanDate2(Date1,Date2) && IsDateEqualsToDate2(Date1,Date2));
}

enum enDateCompare{Befor=-1 , Equals=0 , After=1};


enDateCompare CompareDate(sDate Date1 , sDate Date2){

    if(IsDate1BeforThanDate2(Date1,Date2)){
          return enDateCompare::Befor ;
    }
    
    if(IsDateEqualsToDate2(Date1,Date2)){
        return enDateCompare::Equals ;
    }

    /*
    if(IsDate1AfterDate2(Date1,Date2)){
        return enDateCompare::After ;
    }*/

    // This is Faster 
    return enDateCompare::After ;
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

short CalculatePeriodeLength(stPeriod Period , bool IncludeEndDate=false){
   
    short Days =0;
    while(CompareDate(Period.StartDate,Period.EndDate)==enDateCompare::Befor){
        Days++;
        Period.StartDate = IncreaseDateByOneDay(Period.StartDate) ;
    }
    return IncludeEndDate ? ++Days : Days ;
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

stPeriod ReadPeriod(){
    stPeriod Period ;
    
    cout << "Enter Start Date :\n";
    Period.StartDate = ReadFullDate();
    cout << "\n\nEnter End Date : \n";
    Period.EndDate = ReadFullDate();

    return Period ;
}

int main(){
    cout << "\nEnter Period1 :\n\n";
    stPeriod Period1 = ReadPeriod();

    cout << "Period Length is : "<< CalculatePeriodeLength(Period1)<<endl;
    cout << "Period Length (Include End Date) is : "<< CalculatePeriodeLength(Period1,true)<<endl;


    
    




    system("pause>0");
    return 0;
}