#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std ;

//  Random small letter , Capital letter , Special Character and Digit in order

enum enCharType{SamallLetter = 1 , CapitalLetter = 2 , SpecialCharacter = 3 , Digit = 4};

int RandomNumber(int from , int To )
{
    int Random = rand() % (To - from +1 ) + from ;
    return Random ;
}

char  GetRandomChartype(enCharType CharTyp){
switch(CharTyp){
case enCharType::SamallLetter:
{
    return char(RandomNumber(97,122)) ;
    break;
}
case enCharType::CapitalLetter:
{
    return char(RandomNumber(65,90)) ;
    break;
}
case enCharType::SpecialCharacter:
{
    return char( RandomNumber(33,47));
    break;
}
case enCharType::Digit:
{
    return char(RandomNumber(48,57)) ;
    break;
}


}
}

int main(){

srand((unsigned)time(NULL));

cout << GetRandomChartype(enCharType::SamallLetter) << endl ;
cout << GetRandomChartype(enCharType::CapitalLetter) << endl ;
cout << GetRandomChartype(enCharType::SpecialCharacter) << endl ;
cout << GetRandomChartype(enCharType::Digit) << endl ;




    return 0 ;
}