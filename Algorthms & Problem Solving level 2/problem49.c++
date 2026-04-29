#include<iostream>
#include<cmath>
using namespace std ;

// My Ceil Function 

float ReadNumber(){
    float number ;
    cout <<"Pleas enter number\n";
    cin >> number ;
    return number ;
}

int MyCeil(float Number){

if(Number>0)
return (int)Number+1 ;
else
return (int) Number ;

}

int main(){
float M =ReadNumber();
cout << "My Ceil Number = " << MyCeil(M) << endl ;
cout << "C++ Ceil Number = " << ceil(M);

    return 0 ;
}