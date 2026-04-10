#include<iostream>
using namespace std ;


void ReadNumbers(int &Num1 , int &Num2){

    cout << "Pleas enter a number 1 ?\n";
    cin >> Num1 ;

    cout << "Pleas enter a number 2 ?\n";
    cin >> Num2;

}

int MaxOf2Number(int Num1 , int Num2){

    if(Num1>Num2)
    return Num1;
    else 
    return Num2;
}

void PrintResult(int Max){

    cout << "\nThe Maximum Number is : "<< Max << endl ;
}


int main(){

    int Num1 , Num2;
    ReadNumbers(Num1,Num2);
    PrintResult(MaxOf2Number(Num1,Num2));

    return 0;
}