#include<iostream>
using namespace std ;


int ReadNumber(){

    int Number ;
    cout << "Pleas enter a Number ?\n";
    cin >> Number ;

    return Number;
}


float Calculate_Half_Number(int Number){

    return (float) Number / 2 ;
}

void Print_Result(float Number)
{

    string Result = "Half of " + to_string(Number) + " is " + to_string(Calculate_Half_Number(Number));
    cout << "Half Number : "<< Result << endl ;
}


int main(){

    Print_Result(ReadNumber());

    return 0;
}
