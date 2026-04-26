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

void PrintAllDigitsFrequencey(int Num){

    for(int i=0 ; i<Num ;i++){
        short DigitFrequencey = 0 ;

        DigitFrequencey = CountDigitFrequencey(Num,i);

        if(DigitFrequencey > 0){

            cout << "Digit " << i << "Frequwncey is " << DigitFrequencey 
            << " Time(s).\n" ;
        }

    }
}





int main(){

    int N = ReadPositiveNumber("Please enter the a number ?");
    PrintAllDigitsFrequencey(N);

    return 0;
}