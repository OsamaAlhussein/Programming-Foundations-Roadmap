#include<iostream>

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


void PrintNumberPattern(int num )
{
    for (int i = 1 ; i <= num ; i++)
    {
        for(int j = 1 ; j <= i ; j++)
        {
            cout << i ;
        }
        cout << endl ;
    }

}







int main()
{

PrintNumberPattern(ReadPositiveNumber("Please enter a positive number?"));







    return 0 ;
}