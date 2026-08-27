#include<iostream>
#include "clsStirng.h"
using namespace std ;


int main(){

    clsString String1("Osama Al Housein");

    cout << String1.getValue() << endl ;
 
    cout << String1.CountCapitalLetters() << endl ;

    cout << "Number of word : " << String1.CounterWords() << endl ;

    cout<< "Number of word (Sami Hosen): " << clsString::CounterWords("Sami Hosen") << endl ;

    cout << "Length of String1 " << String1.Length() << endl ;
    cout << "Count Captal Letter of String1 : "<< String1.CountCapitalLetters() << endl ;



    return 0;
}
