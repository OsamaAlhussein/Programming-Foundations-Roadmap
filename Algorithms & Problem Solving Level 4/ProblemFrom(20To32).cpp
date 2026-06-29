#include<iostream>
using namespace std ;


//

struct sDate{
    short Day ;
    short  Month ;
    short  Year ;
};

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

bool IsLastMonth(sDate Date){
    return (Date.Month==12) ;
}

bool IsLastDays(sDate Date){
    return (Date.Day == NumberOfDaysInMonth(Date.Year,Date.Month));
}


sDate IncreaseDateByOneDay(sDate Date){

    if(IsLastDays(Date)){
       Date.Day = 1 ;
        if(IsLastMonth(Date)){
            Date.Month = 1;
            Date.Year++ ;
        }else{
            Date.Month++ ;
        }
    }else{
        Date.Day++ ;
    }
    return Date ;
}

sDate IncreaseDateByXDays(short Days ,sDate Date){

    for(int i=1 ;i<=Days ;i++){
        Date = IncreaseDateByOneDay(Date);
    }
    return Date ;
}

sDate IncreaseDateByOneWeek(sDate Date){
    
    for(int i=1 ; i<=7 ; i++){
        Date = IncreaseDateByOneDay(Date);
    }
    return Date ;
}

sDate IncreaseDateByXWeek(short Weeks , sDate Date){

    for(int i=1 ; i<=Weeks ; i++){
        Date = IncreaseDateByOneWeek(Date);
    }

    return Date ;
}

sDate IncreaseDateByOneMonth(sDate Date){
    
    if(Date.Month==12){
        Date.Month = 1 ;
        Date.Year++ ;
    }
    else{
        Date.Month++;
    }
    //last check day in date should not exceed max days in the current month 
    // example if date is 31/1/2022 increasing one month should not be 31/2/2022 , it should 
    // be 28/2/2022
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year,Date.Month);
    if(Date.Day > NumberOfDaysInCurrentMonth ){
        Date.Day = NumberOfDaysInCurrentMonth ;
    }
    return Date ;
}

sDate llDateByXMonth(short Month ,sDate Date){

    for(int i=1 ; i<=Month ; i++){
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date ;
}

sDate IncreaseDateByOneYear(sDate Date){
    Date.Year++;
    return Date ;
}

sDate IncreaseDateByXYear(short Years , sDate Date){
    for(int i=1 ; i<=Years ; i++){
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

sDate IncreaseDateByXYear_Faster(short Years ,sDate Date){
    Date.Year +=Years;
    return Date ;
}

sDate IncreaseDateByOneDecade(sDate Date){
    Date.Year +=10;
    return Date ;
}

sDate IncreaseDateByXDecade(short Decade,sDate Date){
    for(int i=1 ; i<=Decade * 10 ;i++){
        Date = IncreaseDateByOneYear(Date);
    }
    return Date ;
}

sDate IncreaseDateByXDecade_Faster(short Decade,sDate Date){
    Date.Year+= Decade*10;
    return Date ;
}

sDate IncreaseDateByOneCentury(sDate Date){
    Date.Year += 100;
    return Date ;
}

sDate IncreaseDateByOneMillennium(sDate Date){
    Date.Year += 1000 ;
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
    Date.Year = ReadYear();

    return Date ;
}



int main(){

    sDate Date ;
    Date = ReadFullDate();
    cout << "\n\nDate After :\n\n";
    Date = IncreaseDateByOneDay(Date);
    
    cout << "\n01 - Adding one day is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = IncreaseDateByXDays(10,Date) ;

    cout << "\n02 - Adding 10 days is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = IncreaseDateByOneWeek(Date);

    cout << "\n03 - Adding One Week is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = IncreaseDateByXWeek(10,Date) ;
    cout << "\n04 - Adding 10 Weeks is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = IncreaseDateByOneMonth(Date);
    
    cout << "\n05 - Adding One Month is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = llDateByXMonth(5,Date);

    cout << "\n06 - Adding 5 Months is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = IncreaseDateByOneYear(Date) ;

    cout << "\n07 - Adding One Year is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = IncreaseDateByXYear(10,Date) ;

    cout << "\n08 - Adding 10 Years is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = IncreaseDateByXYear_Faster(10,Date);

    cout << "\n09 - Adding 10 Years (Faster) is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = IncreaseDateByOneDecade(Date);

    cout << "\n10 - Adding One Decade is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = IncreaseDateByXDecade(10,Date);

    cout << "\n11 - Adding 10 Decades is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = IncreaseDateByXDecade_Faster(10, Date);
    cout << "\n12 - Adding 10 Decades (Faster) is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = IncreaseDateByOneCentury(Date);
    cout << "\n13 - Adding Century is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = IncreaseDateByOneMillennium(Date);
    cout << "\n14 - Adding Millennium is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;





    

    return 0;
}