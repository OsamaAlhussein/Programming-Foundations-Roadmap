#include<iostream>
#include<string>
using namespace std ;

enum enNumberType{Odd=1 , Even=2};

int ReadNumber(){
    int Number ;

    cout << "\nPleas enter the Number\n";
    cin >> Number ;

    return Number ;
}

enNumberType NumberType(int Num){

    if(Num%2==0){
        return enNumberType::Even;
    }
    else 
    {
        return enNumberType::Odd;
    }
}

void PrintNumberType(enNumberType NumberType){

    if(NumberType == enNumberType::Even)
    {
        cout << "\nNumber is Even.\n";
    }
    else{
        cout << "\nNumber is Odd.\n";
    }
}


int main(){


    PrintNumberType(NumberType(ReadNumber()));


    return 0;
}