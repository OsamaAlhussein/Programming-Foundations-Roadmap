#include<iostream>
using namespace std ;

// Month of Year

enum enMonthOfYear{ jan =1 , feb=2 , mar=3 , apr=4, 
                    may=5 , jun=6 , jul=7 ,   aug=8,
                    sep=9 , oct=10 , nov=11 , dec=12};


int ReadNumberInRange(string Message , int From , int To){

    int Number =0 ;
    do{
        cout << Message << endl ;
        cin >> Number ;

    }while(Number < From || Number > To );

    return Number ;
}

enMonthOfYear ReadMontheOfYear(){
    return (enMonthOfYear)ReadNumberInRange("Please enter Month Number 1 to 12",1,12);
}

string GetMonthOfYear(enMonthOfYear Month){

    switch(Month){

        case enMonthOfYear::jan:
        return "january";
        break;
        case enMonthOfYear::feb:
        return "february";
        break;
        case enMonthOfYear::mar:
        return "march";
        break;
        case enMonthOfYear::apr:
        return "april";
        break;
        case enMonthOfYear::may:
        return "may";
        break;
        case enMonthOfYear::jun:
        return "june";
        break;
        case enMonthOfYear::jul:
        return "july";
        break;
        case enMonthOfYear::aug:
        return "august";
        break;
        case enMonthOfYear::sep:
        return "september";
        break;
        case enMonthOfYear::oct:
        return "october";
        break;
        case enMonthOfYear::nov:
        return "november";
        break;
        case enMonthOfYear::dec:
        return "december";
        break;
        default:
        return "Not a valid Month";
    }
}
int main(){

    cout << GetMonthOfYear(ReadMontheOfYear());

    return 0;
}