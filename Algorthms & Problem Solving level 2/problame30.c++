#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>

// Sum of 2 Arrays to a third one 

using namespace std ;

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
int RandomNubmer(int from , int To)
{
   int Random = rand() % (To - from +1) + from ;

   return Random ;
}

void  FillArraywithRandomNumber(int arr[100] , int &arrLength)
{


    for(int i=0 ; i<arrLength; i++)
    {
        arr[i] = RandomNubmer(1,100);
    }
    cout << "\n";
}

void SumofRandomArray(int arrSousce[100] , int arrDestition[100] , int arrSum[100] , int arrLength )
{

for(int i=0 ; i<arrLength ; i++)
{
    arrSum[i] = arrSousce[i] + arrDestition[i] ;
}

}

void PrintArrayRandomNumber(int arr[100] , int arrLength){

    for(int i=0 ; i<arrLength ; i++)
    {
        cout << arr[i] <<"  ";
    }
    cout << "\n";
}
int main(){

 srand((unsigned)time(NULL));

int arr[100] , arr2[100] , arrSum[100] ;
int  arrLength ;
cout << "Enter Elemenet Array :\n";
cin >> arrLength ;

FillArraywithRandomNumber(arr,arrLength);
cout << "Array 1 Elemenet :\n";
PrintArrayRandomNumber(arr,arrLength);


FillArraywithRandomNumber(arr2,arrLength);
cout << "Array 2 Elemenet :\n";
PrintArrayRandomNumber(arr2,arrLength);
cout << "\n";
SumofRandomArray(arr,arr2,arrSum,arrLength);
cout << "Sum Array 1 Elemenet and Array 2 Elemenet = \n";
PrintArrayRandomNumber(arrSum,arrLength);



    return 0 ; 
}