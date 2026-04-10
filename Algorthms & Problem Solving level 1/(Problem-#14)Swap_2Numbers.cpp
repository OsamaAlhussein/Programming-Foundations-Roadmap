#include<iostream>
using namespace std ;


void ReadNumber(int &Num1 , int &Num2){

    cout << "Pleas enter a Number 1 ?\n";
    cin >> Num1 ;

    cout << "Pleas enter a Number 2 ?\n";
    cin >> Num2 ;
}

void Swap(int &A , int &B){
    int Temp ;

    Temp = A ;
    A = B ;
    B = Temp ;
}

void PrintNumbers(int Num1 , int Num2){

    cout << "\nNumber 1 = " << Num1 << endl ;
    cout << "Number 2 = " << Num2 << endl ;
}


int main(){

    int Num1 ,Num2 ;
    ReadNumber(Num1,Num2);
    PrintNumbers(Num1,Num2);
    Swap(Num1,Num2);
    PrintNumbers(Num1,Num2);


    return 0;
}