#include<iostream>
#include<string>
#include<cmath>
using namespace std ;

// Rectangle Area By Diagonal & Side 

void ReadNumbers(float &A , float &D){

    cout << "Pleas enter A\n";
    cin  >> A ;

    cout << "Pleas enter D\n";
    cin  >> D ;
}

float RectangleAreaBySidAndDiagonal(float A , float D){

    float Area = A * sqrt(pow(D,2) - pow(A,2));
    return Area;
}

void PrintResult(float Area){
    cout << "Rectangle Area = "<< Area << endl ;
}

int main(){

    float A , D ;
    ReadNumbers(A,D);
    PrintResult(RectangleAreaBySidAndDiagonal(A,D));

    return 0;
}