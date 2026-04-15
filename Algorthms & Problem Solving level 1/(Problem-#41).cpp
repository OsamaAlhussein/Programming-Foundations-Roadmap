#include<iostream>
using namespace std ;

//weeks and days 

float ReadPositiveNumber(string Message){

    float Num =0 ;
    do
    {
        cout << Message << endl ;
        cin >> Num ;
    }while(Num <=0 );

    return Num ;
}

float HourToDays(float NumberOfHour){

    float Day ;
    Day = NumberOfHour / 24 ;
    return (float) Day ;
}

float HourToWeek(float NumbeerOfHour){

    float week ;
    week = HourToDays(NumbeerOfHour) / 7 ;
    return week ;
}


int main(){

    float NumberOfHour = ReadPositiveNumber("Please enter Number of Hour ?");
    float NumberOfDay = HourToDays(NumberOfHour);
    float NumberOfWeek = HourToWeek(NumberOfHour);
    cout << endl ;

    cout << "Total Hours : " << NumberOfHour << endl ;
    cout << "Total Day   : " << NumberOfDay  << endl ;
    cout << "Total Week  : " << NumberOfWeek << endl ;

    return 0;
}