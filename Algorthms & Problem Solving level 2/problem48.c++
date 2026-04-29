#include<iostream>
#include<cmath>
using namespace std ;

// My floor Function

float ReadNumber(){
    float number ;
    cout <<"Pleas enter number\n";
    cin >> number ;
    return number ;
}

int Myfloor(float Number){

if(Number>0)
return (int)Number ;
else
return (int)Number - 1;

}

int main(){
float M =ReadNumber();
cout << "My floor Number " << Myfloor(M) << endl ;
cout << "C++ floor Number " << floor(M);

    return 0 ;
}