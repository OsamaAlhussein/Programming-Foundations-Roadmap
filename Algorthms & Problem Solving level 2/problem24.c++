#include<iostream> 
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std ;

// Max of Random Array

int RandomNubmer(int from , int To)
{
   int Random = rand() % (To - from +1) + from ;

   return Random ;
}

void  FillArraywithRandomNumber(int arr[100] , int &arrLength)
{
    cout << "Enter Array Element : \n";
    cin >> arrLength ;

    for(int i=0 ; i<arrLength; i++)
    {
        arr[i] = RandomNubmer(1,100);
    }
    cout << "\n";
}

void PrintArrayRandomNumber(int arr[100] , int arrLength){

    for(int i=0 ; i<arrLength ; i++)
    {
        cout << arr[i] <<"  ";
    }
    cout << "\n";
}

int MaxNumberInArray(int arr[100] , int arrLength )
{

int Max = 0;
for (int i=0 ; i<arrLength ; i++)
{

    if(arr[i]>Max)
    {
        Max = arr[i] ;
    }

}
return Max ;

}


int  main()
{
    srand((unsigned)time(NULL));
    int arr[100] , arrLength ;

    FillArraywithRandomNumber(arr,arrLength);
cout << "Elemenet Array : ";
    PrintArrayRandomNumber(arr,arrLength);

    cout << "MAX Number = "
    << MaxNumberInArray(arr,arrLength) ;




    return 0 ;
}