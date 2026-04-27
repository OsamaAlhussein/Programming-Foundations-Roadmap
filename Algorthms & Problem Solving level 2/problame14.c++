#include<iostream>
#include<string>
using namespace std ;


int  ReadPositiveNumber(string massge )
{

    int num ;
    do{
    cout << massge << endl ;
    cin >> num ;
    }while(num<0);
    return num ;

}


void PrintInvertedLetterPattern(int num )
{
    for (int i =64 + num ; i>=65 ; i--)
    {
        for (int j = i ; j >=65 ; j--)
        {
            cout << char(i) ;
        }
        cout << endl ;
    }
}


int main(){

PrintInvertedLetterPattern(ReadPositiveNumber("Please enter a positive number?"));


    return 0 ; 
}