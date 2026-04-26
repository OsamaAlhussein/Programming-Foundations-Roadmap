#include<iostream>
using namespace std ;

int ReadPositiveNumber(string massge)
{
    int number ;
do{
cout << massge << endl ;
cin >> number ;
}while(number <= 0);
return number ;

}

int  SumOfDigits(int number)
{
int sum =0 , Remainder=0 ;

while (number> 0)
{
Remainder = number % 10 ;
number = number / 10 ;
sum+=Remainder;

}
return sum ;
}


int main(){

    int N = ReadPositiveNumber("Please enter a positive number?");

    cout << "Sum of digits = " << SumOfDigits(N);

    return 0;
}