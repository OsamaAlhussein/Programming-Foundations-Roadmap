#include<iostream>
#include<cmath>
using namespace std ;


// Circle Area Inscribed in a a Square 

float ReadSquareSide(){
    float A;
    cout << "Please enter square side A ? \n";
    cin  >> A ;

    return A ;
}


float CircleAreaInscribedInSquare(float A){

    const float PI = 3.14159265358979328 ;
    float Area = (PI * pow(A , 2)) / 4 ;
    return Area ;
}

void PrintResult(float Area){

    cout << "Circle Area = "<< Area << endl ;
}

int main(){

    PrintResult(CircleAreaInscribedInSquare(ReadSquareSide()));


    return 0;
}