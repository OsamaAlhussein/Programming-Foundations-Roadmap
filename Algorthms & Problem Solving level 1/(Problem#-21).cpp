#include<iostream>
#include<cmath>
using namespace std ;

// Circle Area Along the circmfernce 

float ReadCircumference(){
    float L ;
    cout << "Please enter Circumference ? \n";
    cin  >> L ;
    return L ;
}

float CircleAreaByCirumference(float L){

    const float PI = 3.141592553589793238 ;
    float Area = pow(L,2) / (4 * PI) ;

    return Area ;
}

void PrintResult(float Area){
    cout << "Circle Area = "<< Area<< endl;
    
}

int main(){

    PrintResult(CircleAreaByCirumference(ReadCircumference()));
    return 0;
}