#include<iostream>
#include<cmath> 
using namespace std ;

float ReadDimeter(){

    float D ;
    cout << "Please enter radious D ?\n";
    cin >> D ;
    return D ;
}

float CircleAreaByDiameter(float D){
    const float PI = 3.14159265358979328 ;
    float Area = (pow(D,2) * PI) / 4 ;
    return Area ;
}

void PrintResult(float Area){

    cout << "Circle Area = "<< Area << endl ;
}

int main(){

    PrintResult(CircleAreaByDiameter(ReadDimeter()));


    return 0;
}