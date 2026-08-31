#include<bits/stdc++.h>
#include<string>
#include"clsDate1.h"
using namespace std ;


class clsInputValidate{

    public:

    static bool IsNumberBetween(short Num , short  From , short To){

        return (Num >= From && Num <= To );
    } 

    static bool IsNumberBetween(int Num , int From , int To){

        return (Num >= From && Num <= To );
    } 

    static bool IsNumberBetween(float Num , float From , float To){

        return (Num >= From && Num <= To );
    } 

    static bool IsNumberBetween(double Num , double From , double To){

        return (Num >= From && Num <= To );
    } 

    static bool IsDateBetween(clsDate Date , clsDate FromDate , clsDate ToDate){
    return (clsDate::IsDate1BeforeDate2(Date,ToDate) && clsDate::IsDate1AfterDate2(Date,FromDate)) || 
                (clsDate::IsDate1BeforeDate2(ToDate,Date) && clsDate::IsDate1AfterDate2(FromDate,Date)) ;
    }

    static int ReadIntNumber(string Message){
        int num =0;
        cin >> num ;
        while(cin.fail()){

            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max() , '\n') ;
            cout << Message << endl ;
            cin >> num ;
        }
        return num ;
    }

    static int ReadIntNumberBetween(int from , int to , string message){

        int num = ReadIntNumber(message) ;

        while(!IsNumberBetween(num,from,to)){
            cout << message << endl ;
             num = ReadIntNumber(message) ;
        }
        
            return num ;
        
    }

    static double ReadDblNumber(string Message){
        double num =0;
        cin >> num ;
        while(cin.fail()){

            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max() , '\n') ;
            cout << Message << endl ;
            cin >> num ;
        }
        return num ;
    }

    static double ReadDblNumberBetween(double from , double to , string message){

        double num = ReadDblNumber(message) ;

        while(!IsNumberBetween(num,from,to)){
            cout << message << endl ;
            num = ReadDblNumber(message) ;
        }
        
            return  num ;
        
    }

    static bool IsValideDate(clsDate Date){
        return clsDate::IsValidDate(Date) ;
    }

    
};
