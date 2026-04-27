#include<iostream>
using namespace std ;

int  ReadPositiveNumber(string massge )
{

    int num ;
    do{
    cout << massge << endl ;
    cin >> num ;
    }while(num<=0);
    return num ;

}


void PrintLetterPattern(int num )
{
    for (int i = 65 ; i <65+num ; i++)
    {
        for(int j = 65 ; j <= i ; j++)
        {
            cout << char(i) ;
        }
        cout << endl ;
    }

}




int main(){


    PrintLetterPattern(ReadPositiveNumber("Please enter a positive number?"));


    return 0 ;
}
