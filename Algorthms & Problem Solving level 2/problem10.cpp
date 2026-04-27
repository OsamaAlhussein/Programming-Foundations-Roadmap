#include<iostream>
using namespace std ;

// Print Digit in Order 
int ReadPositiveNumber(string massge)
{
int number ;
do{
cout << massge << endl ;
cin >> number ;
}while(number <= 0);
return number ;
}

int DigitInOrder(int Num){

    int Remender =0 , Num2 =0 ;

    while(Num > 0){
        Remender = Num % 10 ;
        Num = Num / 10 ;
        Num2 = Num2 * 10 + Remender ;
    }
    return Num2 ;
}

void PrintDigitInOrder(int Num2){
    int Remender = 0 ;
    while(Num2 > 0){

        Remender = Num2 % 10;
        Num2 = Num2 / 10 ;
        cout << Remender << endl ;
    }

}

int main(){

    PrintDigitInOrder(DigitInOrder(ReadPositiveNumber("Please enter a the number?")));

    return 0;
}