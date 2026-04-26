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

int ReverseNumber(int Num){
    int Num2=0 , Remainder=0;

    while(Num > 0){

        Remainder = Num % 10 ;
        Num = Num / 10 ;
        Num2 = Num2 * 10 + Remainder ;
    }

    return Num2 ;
}

int main(){
    int N =ReadPositiveNumber("Please enter a positive number?");

    cout << "Reverse is :\n" << ReverseNumber(N) ;


    return 0;
}