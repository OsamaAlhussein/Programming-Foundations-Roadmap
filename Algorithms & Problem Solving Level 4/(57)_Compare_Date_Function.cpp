#include<iostream>
using namespace std ;

// Wrinte a program to read Date1 & Date2 
// and write function to compare dates, it
// should return 
// .-1 Befor
// . 0 Equals
// . 1 After  



struct sDate{
    short Day ;
    short Month ;
    short Year ;
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

    cout << "Compare Result = " << CompareDate(Date1,Date2);

    return 0;
}