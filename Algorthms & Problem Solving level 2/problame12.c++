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


void PrintInvertedNumberPattern(int num )
{
   for (int i =num ; i>=1 ; i--)
   {
    for (int j = 1 ; j<=i ;j++ )
    {
        cout << i ;
    }
    cout << endl ;
   }
}



int main()
{


PrintInvertedNumberPattern(ReadPositiveNumber("Please enter a positive number?"));


    return 0 ;
}