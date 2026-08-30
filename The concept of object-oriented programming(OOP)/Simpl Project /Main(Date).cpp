#include<iostream>
#include"clsDate.h"
using namespace std ;

int main(){

    clsDate Date1 ;
    Date1.Print() ;

    clsDate Date2("11/9/2022");
    Date2.Print();

    
    clsDate Date3(20,12,2023);
    Date3.Print();

    clsDate Date4(250,2022);
    Date4.Print();


    cout << Date2.IsValidDate() ;
    cout << clsDate::CalculateMyAgeInDays(clsDate(20,8,2007));
    return 0;
}

/*.........................*/
