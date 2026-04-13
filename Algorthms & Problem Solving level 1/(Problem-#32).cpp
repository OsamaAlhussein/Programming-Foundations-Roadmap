#include<iostream>
using namespace std ;

// Power of M 

int ReadNumber(){

    int N;
    cout << "Please enter the numbeer N ?\n";
    cin >> N;
    return N ;
}


int ReadPower(){

    int M;
    cout << "Please enter the Power M ?\n";
    cin >> M;
    return M ;
}



int  PowerOf_M(int N , int M){

    if(M==0)
    {
        return 1 ;
    }
    

    int P = 1;
    for(int i=1 ; i<=M ; i++){

        P = P * N ;
    }

    return P ;
}

int main(){

    int N , M ;
    N = ReadNumber();
    M = ReadPower();
    cout << "Result = " << PowerOf_M(N,M);

    return 0;
}