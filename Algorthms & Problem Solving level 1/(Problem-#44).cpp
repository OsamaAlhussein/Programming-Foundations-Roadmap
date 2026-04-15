#include<iostream>
using namespace std ;

// Day of Week 
enum enDayOfWeek {sat=1 , sun=2 , mon=3 , tue=4 , wed=5 , thu=6 , fri=7};

int ReadNumberInRange(string Message , int From , int To){

    int Number =0 ;
    do{
        cout << Message << endl ;
        cin >> Number ;

    }while(Number < From || Number > To );

    return Number ;
}

enDayOfWeek ReadDayOfWeek(){
    return (enDayOfWeek) ReadNumberInRange("Please enter day number Sat=1 , sun=2 , mon=3 , tue=4 , wed=5 , wed=5 , the=6 , fri=7",1,7);
}


string GetDayOfWeek(enDayOfWeek Day){

    switch(Day){
        case enDayOfWeek::sat :
            return "Saturday";
            break;
        case enDayOfWeek::sun:
            return "Sunday";
            break;
        case enDayOfWeek::mon:
            return "Monday";
            break;
        case enDayOfWeek::tue:
            return "Tuesday";
            break;
        case enDayOfWeek::wed:
            return "Wednesday";
            break;
        case enDayOfWeek::thu: 
            return "Thursday";
            break;
        case enDayOfWeek::fri:
            return "Friday";
            break;
        default:
        return "Not a valid Day";                   
    }
}
int main(){

    cout << GetDayOfWeek(ReadDayOfWeek());

    return 0;
}