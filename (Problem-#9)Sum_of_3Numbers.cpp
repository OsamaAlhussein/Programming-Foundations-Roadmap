#include<iostream>
using namespace std ;


void ReadNumbers(int &Num1 , int &Num2 , int &Num3){

    cout << "Pleas enter your Number 1 ?"<< endl ;
    cin >> Num1 ;
    
    cout << "Pleas enter your Number 2 ?"<< endl ;
    cin >> Num2 ;

    cout << "Pleas enter your Number 3 ?"<< endl ;
    cin >> Num3 ;

}


int SumOf3Numbers(int Num1 ,int Num2 , int Num3){

    return Num1+Num2+Num3 ;
}

void PrintResult(int Total){

    cout << "The total um of  Numbers is : "<< Total << endl ;
}


int main(){

    int Num1 , Num2 , Num3 ;

    ReadNumbers(Num1,Num2,Num3);
    PrintResult(SumOf3Numbers(Num1,Num2,Num3));


    return 0;
}