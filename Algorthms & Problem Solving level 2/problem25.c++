#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
// Min of Random Array
using namespace std ;
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

int MinNumberInArray(int arr[100] , int arrLength )
{

int Min = 100;
for (int i=0 ; i<arrLength ; i++)
{

    if(arr[i]<Min)
    {
        Min = arr[i] ;
    }

}
return Min  ;

}
int main()
{
  srand((unsigned)time(NULL));
  int arr[100] , arrLength ;
    FillArraywithRandomNumber(arr,arrLength);
cout << "Elemenet Array : ";
    PrintArrayRandomNumber(arr,arrLength);

    cout << "Min Number = "
    << MinNumberInArray(arr,arrLength) ;

    return 0 ; 
}