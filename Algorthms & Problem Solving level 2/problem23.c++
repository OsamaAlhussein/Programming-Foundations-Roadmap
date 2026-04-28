#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>

// Fill Array With Random Number from 1 to 100 

using namespace  std;

int ReadNubmer(string massge)
{
    int number ; 
    do
    {
        cout << massge << endl ;
        cin >> number ;
    }while(number < 0);
    return 0 ; 
}

int  RandomNumber(int from , int To)
{
    int Random = rand() % (To - from + 1 ) + from ;
    return Random;
}

void FillArraywithRandomNubmer(int arr[100] , int &arrLength)
{
    cout << "Enter Array Elemenet : \n" ;
    cin >> arrLength ; 
 for (int i=0 ; i<= arrLength ; i++)
 {
    arr[i] = RandomNumber(1,100);
 }
    cout << endl ;
}

void PrintArraywithRandomNubmer(int arr[100], int arrLength)
{
    for(int i=0 ; i<arrLength ; i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl ;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100] , arrLength  ;
   

    FillArraywithRandomNubmer(arr , arrLength);

    cout << "Array Elemenet : ";
    PrintArraywithRandomNubmer(arr, arrLength);






    return 0 ; 
}