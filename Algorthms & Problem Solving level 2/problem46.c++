#include<iostream>
#include<cmath>

using namespace std ;

// My Abs Function

float  ReadNubmer(string massge){


    float number;
    cout << massge <<endl ;
    cin >> number ;
    return number ;

}

float  MyAbs(float number){

    if (number>0)
    return number ;
    else 
    return (-1)*(number);
}

int main(){


    float number = ReadNubmer("pleas enter the Number ?");
    cout << "My Abs Result :" << MyAbs(number) << endl ;
    cout << "C++ Abs Result :" << abs(number);

    return 0 ;
}