#include<iostream>
using namespace std ;


/*Write a program to print number of :
  Days , Hours , Minutes , Seconds 
  in a certain Month */ 



bool IsLeapYear(short Year){
    return (Year % 400 == 0 && Year % 100 != 0) || (Year % 4 ==0) ;
}

short NumberOfDaysInMonth(short Year , short Month){

if(Month < 1 || 12 < Month){
    return 0 ;
}

if(Month == 2){
    return (IsLeapYear(Year)) ? 29 : 28 ;
}

short arr31Days[7] = {1,3,5,7,8,10,12};

for(short i=1 ; i<=7 ; i++){
    if(arr31Days[i-1] == Month){
        return 31 ;
    }
}
// if you reach here then it's 30 days.
return 30 ;


}

int NumberOfHoursInMonth(short Year , short Month){
    return NumberOfDaysInMonth(Year , Month) * 24 ;
}

int NumberOfMinutes(int Year , short Month){
    return NumberOfHoursInMonth(Year , Month) * 60 ;
}

int NumberOfSecondsInMonth(int Year , short Month){
    return NumberOfMinutes(Year , Month) * 60 ; 
}


short ReadYear(){
    short Year ;
    cout << "Please enter a year to check ? ";
    cin >> Year ;
    return Year ;
  }

 short ReadMonth(){
    short Month ;
    cout << "Please enter a Month to check ? ";
    cin >> Month ;
    return  Month ;
 } 

int main(){

    short Year = ReadYear() ;
    short Month =  ReadMonth();

    cout << "\nNumber of Days      in Month[ " << Month << "] is : " <<NumberOfDaysInMonth(Year,Month);

    cout << "\nNumber of Hours     in Month[ " << Month << "] is : " << NumberOfHoursInMonth(Year,Month);

    cout << "\nNumber of Minutes   in Month[ " << Month << "] is : " <<NumberOfMinutes(Year,Month) ;

    cout << "\nNumber of Seconds   in Month[ " << Month << "] is : "<< NumberOfSecondsInMonth(Year,Month);

    system("pause>0");


    return 0;
}