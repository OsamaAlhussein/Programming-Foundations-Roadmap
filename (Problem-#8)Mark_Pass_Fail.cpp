#include<iostream>
using namespace std ;

enum enPassOrFail{Pass=1 , Fail=2};


int ReadMark(){
    int Mark ;
    cout << "Pleas enter Your Mark ?\n";
    cin >> Mark ;

    return Mark ;
}

enPassOrFail CheckMark(int Mark){

    if(Mark >= 50)
    return enPassOrFail::Pass;
    else 
    return enPassOrFail::Fail ;
}

void PrintResult(int Mark){

    if(CheckMark(Mark)==enPassOrFail::Pass)
    cout << "You Passed ";
    else
    cout << "You Faild";
}


int main(){

    PrintResult(ReadMark());

    return 0;
}