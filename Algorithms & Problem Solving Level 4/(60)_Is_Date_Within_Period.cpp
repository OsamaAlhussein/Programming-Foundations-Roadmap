#include<iostream>
using namespace std ;

// Write a program to read period and 
// Date , then check if date is within this 
// period or not? 

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

    

 



bool IsDateInPeriod(stPeriod Period1 , sDate Date){

return !(CompareDate(Date,Period1.StartDate)==enDateCompare::Befor||CompareDate(Date,Period1.EndDate)==enDateCompare::After);

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
    cout << "\nEnter Period2 :\n\n";
    sDate Date = ReadFullDate();
    

    if(IsDateInPeriod(Period1,Date)){
        cout << "\nYES , Periods Overlap.";
    }else{
        cout << "\nNO , Periods Overlap.";
    }

    system("pause>0");
    return 0;
}