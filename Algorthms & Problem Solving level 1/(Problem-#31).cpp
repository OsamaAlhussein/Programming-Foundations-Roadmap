#include<iostream>
using namespace std ;


//Power of 2 , 3 , 4 

int ReadNumber(){

    int N;
    cout << "Please enter a number ?\n";
    cin >> N;
    return N ;
}


void PowerOf2_3_4(int N){

    int a , b , c ;
    a = N*N ;
    b = N*N*N ;
    c = N*N*N*N ;
    cout << "Power( " << N <<" , 2 ) = " << a << endl ;
    cout << "Power( " << N <<" , 3 ) = " << b << endl ;
    cout << "Power( " << N <<" , 4 ) = " << c << endl ;
}

int main(){

    PowerOf2_3_4(ReadNumber());


    return 0;
}