#include<iostream>
#include <string>     
#include <cstdlib>  
#include <ctime> 
using namespace std ;
 
enum enCharType{SamallLetter = 1 , CapitalLetter = 2 , SpecialCharacter = 3 , Digit = 4};

int ReadNumber(string massge)
{
    int number ;
    do{
    cout << massge << endl ;
    cin >> number ;
    }while(number < 0);

    return number;
}

int RandomNumber(int from , int To)
{
    int Random = rand() % (To - from +1) + from ;
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

string GenerateWord(enCharType CharType , short Length)
{
    string word="";
    for(int i=1 ; i<=Length ; i++)
    {
        word+=GetRandomChartype(CharType);
 
    }
    return word;
}

string GenerateKey()
{
string key = "" ;
key+=GenerateWord(enCharType::CapitalLetter , 4)+"-";
key+=GenerateWord(enCharType::CapitalLetter , 4)+"-";
key+=GenerateWord(enCharType::CapitalLetter , 4)+"-";
key+=GenerateWord(enCharType::CapitalLetter , 4);
return key ;

}

void Generatkeys(short Length)
{
    for(int i=1 ; i<=Length ; i++)
    {
        cout << "Key [ " << i << " ] : "<< GenerateKey() <<endl ;
    }
}


int main(){

int Length = ReadNumber("pleas enter Number ? ");

Generatkeys(Length) ;

    return 0; 
}

