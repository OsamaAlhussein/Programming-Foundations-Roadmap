#include<iostream>
using namespace std ;


//Write a program to read a date and make a functions to 
// Decrase date as follows 

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




sDate DecraseDateByOneDay(sDate Date){

    if(Date.Day==1){
        if(Date.Month==12){
            Date.Day = 31 ;
            Date.Month = 12 ;
            Date.Year--;
        }else{
            Date.Month-- ;
            Date.Day = NumberOfDaysInMonth(Date.Year,(Date.Month));
        }
    }else{
        Date.Day-- ;
    }
    return Date ;
}

sDate DecraseDateByXDays(short Days ,sDate Date){

    for(int i=1 ;i<=Days ;i++){
        Date = DecraseDateByOneDay(Date);
    }
    return Date ;
}

sDate DecraseDateByOneWeek(sDate Date){
    
    for(int i=1 ; i<=7 ; i++){
        Date = DecraseDateByOneDay(Date);
    }
    return Date ;
}

sDate DecraseDateByXWeek(short Weeks , sDate Date){

    for(int i=1 ; i<=Weeks ; i++){
        Date = DecraseDateByOneWeek(Date);
    }

    return Date ;
}

sDate DecraseDateByOneMonth(sDate Date){
    
    if(Date.Month==1){
        Date.Month = 12 ;
        Date.Year-- ;
    }
    else{
        Date.Month--;
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

sDate DecraseDateByXMonth(short Month ,sDate Date){

    for(int i=1 ; i<=Month ; i++){
        Date = DecraseDateByOneMonth(Date);
    }
    return Date ;
}

sDate DecraseDateByOneYear(sDate Date){
    Date.Year--;
    return Date ;
}

sDate DecraseDateByXYear(short Years , sDate Date){
    for(int i=1 ; i<=Years ; i++){
        Date = DecraseDateByOneYear(Date);
    }
    return Date;
}

sDate DecraseDateByXYear_Faster(short Years ,sDate Date){
    Date.Year -=Years;
    return Date ;
}

sDate DecraseDateByOneDecade(sDate Date){
    Date.Year -=10;
    return Date ;
}

sDate DecraseDateByXDecade(short Decade,sDate Date){
    for(int i=1 ; i<=Decade * 10 ;i++){
        Date = DecraseDateByOneYear(Date);
    }
    return Date ;
}

sDate DecraseDateByXDecade_Faster(short Decade,sDate Date){
    Date.Year -= Decade*10;
    return Date ;
}

sDate DecraseDateByOneCentury(sDate Date){
    Date.Year -= 100;
    return Date ;
}

sDate DecraseDateByOneMillennium(sDate Date){
    Date.Year -= 1000 ;
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
    Date = DecraseDateByOneDay(Date);
    
    cout << "\n01 - Subtracting one day is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = DecraseDateByXDays(10,Date) ;

    cout << "\n02 - Subtracting 10 days is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = DecraseDateByOneWeek(Date);

    cout << "\n03 - Subtracting One Week is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = DecraseDateByXWeek(10,Date) ;
    cout << "\n04 - Subtracting 10 Weeks is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = DecraseDateByOneMonth(Date);
    
    cout << "\n05 - Subtracting One Month is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = DecraseDateByXMonth(5,Date);

    cout << "\n06 - Subtracting 5 Months is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = DecraseDateByOneYear(Date) ;

    cout << "\n07 - Subtracting One Year is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = DecraseDateByXYear(10,Date) ;

    cout << "\n08 - Subtracting 10 Years is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = DecraseDateByXYear_Faster(10,Date);

    cout << "\n09 - Subtracting 10 Years (Faster) is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = DecraseDateByOneDecade(Date);

    cout << "\n10 - Subtracting One Decade is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = DecraseDateByXDecade(10,Date);

    cout << "\n11 - Subtracting 10 Decades is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = DecraseDateByXDecade_Faster(10, Date);
    cout << "\n12 - Subtracting 10 Decades (Faster) is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = DecraseDateByOneCentury(Date);
    cout << "\n13 - Subtracting Century is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;

    Date = DecraseDateByOneMillennium(Date);
    cout << "\n14 - Subtracting Millennium is : " << Date.Day <<"/" <<Date.Month<<"/" <<Date.Year;





    

    return 0;
}