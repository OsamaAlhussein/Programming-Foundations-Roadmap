#include<iostream>
using namespace std ;


void ReadNumbers(int &Num1 , int &Num2 , int &Num3){

    cout << "Pleas enter a number 1 ?\n";
    cin >> Num1 ;

    cout << "Pleas enter a number 2 ?\n";
    cin >> Num2;

    cout << "Pleas enter a number 3 ?\n";
    cin >> Num3;

}

int MaxOf2Number(int Num1 , int Num2 , int Num3){

    if(Num1>Num2 && Num1>Num3)
    return Num1;
    else if(Num2>Num3)
    return Num2;
    else 
    return Num3;
}

void PrintResult(int Max){

    cout << "\nThe Maximum Number is : "<< Max << endl ;
}


int main(){

    int Num1 , Num2 , Num3;
    ReadNumbers(Num1,Num2,Num3);
    PrintResult(MaxOf2Number(Num1,Num2,Num3));

    return 0;
}