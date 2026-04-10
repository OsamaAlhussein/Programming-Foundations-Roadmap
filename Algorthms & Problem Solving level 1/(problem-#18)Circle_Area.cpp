#include<iostream>
#include<cmath>
using namespace std ;

float  ReadRadious(){
    float R ;
    cout << "Pleas enter tadious R ? \n";
    cin  >> R ;
    return R ;

}

float CircleArea(float R){
    const float PI = 3.14159265358979328 ;
    float Area = pow(R,2) * PI ;
    return Area ;
}

void PrintResult(float Area){

    cout << "Circle Area = " << Area << endl ;

}

int main(){

    PrintResult(CircleArea(ReadRadious()));

    return 0;
}