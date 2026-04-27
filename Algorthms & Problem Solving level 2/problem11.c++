#include<iostream>
using namespace std ; 

int Readnumber(string massge )
{
    int number ;
    do
    {
        cout<< massge << endl ;
        cin >> number ;

    }while(number<0);
    return number ;
}

int ReverseNumber(int number)
{
    int remainder =0 , number2 =0 ;
    while (number > 0)
    {
        remainder = number % 10 ;
        number = number / 10 ;
        number2 = number2 * 10 + remainder ;
    }
    return number2 ;
}

bool IsPalindromNumber(int num)
{
   return num == ReverseNumber(num) ;
}

int main (){

 if(IsPalindromNumber(Readnumber("pleas enter nubmer ?")))
    {
        cout << "Yes , it is a Palindrom number\n ";
    }
    else 
    {
        cout << "No , it isnot  a Palindrom number\n ";
    }

    return 0 ;
}