#include<iostream>
using namespace std ;

// Digit frequencey

int ReadPositiveNumber(string massge)
{
int number ;
do{
cout << massge << endl ;
cin >> number ;
}while(number <= 0);
return number ;
}

int  CountDigitFrequencey(int number , short DigitToCheck)
{

    short Remander =0 , Frequencey =0 ;

    while(number > 0)
    {
        Remander = number % 10 ;
        number = number / 10 ;

        if (Remander==DigitToCheck)
        {
            Frequencey++ ;
        }
    }
    return Frequencey ;
}







int main(){
int Num = ReadPositiveNumber("please enter the main number ?");
short DigitToCheck = ReadPositiveNumber("Please enter one digit to check ?");

cout << "Digit "<< DigitToCheck << " Frequencey is " << CountDigitFrequencey(Num,DigitToCheck)
 << " Time(s).";


    
  

    return 0 ; 
}
