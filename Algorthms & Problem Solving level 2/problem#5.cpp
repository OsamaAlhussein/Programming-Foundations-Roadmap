#include<iostream>
using namespace std ;

// Print Digits in a Reversed Order 

int ReadPositiveNumber(string massge)
{
    int number ;
do{
cout << massge << endl ;
cin >> number ;
}while(number <= 0);
return number ;

}


void PrintDigits(int number)
{
int  Remainder=0 ;

while (number> 0)
{
Remainder = number % 10 ;
number = number / 10 ;
cout << Remainder << endl ;
}
}


int main(){

PrintDigits(ReadPositiveNumber("Please enter a positive number?"));

    return 0;
}