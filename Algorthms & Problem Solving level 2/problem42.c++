#include<iostream>
#include <string>     
#include <cstdlib>  
#include <ctime>
#include<cmath>

using namespace std ;


int RandomNumber(int from , int To)
{
    int Random = rand() % (To - from +1) + from ;
    return Random ;
}

void FillArrayWithRandomNumber(int arr[100] , int &arrLength)
{
    cout << "Pleas enter Array Length\n";
    cin >> arrLength ;

    
    for(int i=0 ; i<arrLength ; i++)
    {
        arr[i] = RandomNumber(1,100) ;
    }
    cout << "\n";
}

void PrintArrayRandomNumber(int arr[100] , int arrLength)
{
    for (int i=0 ; i< arrLength ; i++)
    {
        cout << arr[i] << " ";
    
    }
    cout << "\n";
}

int CheckOddnumber(int arr[100], int arrLength)
{
    int counter=0;
    for(int i=0; i<arrLength ; i++)
    {
        if (arr[i]%2==1)
        {
            counter++;
        }
    }

    return counter ;
}


int main(){

    srand((unsigned)time(NULL));

int arr[100] ,arrLength ;

FillArrayWithRandomNumber(arr,arrLength);
cout << "Array 1 elmenet :\n";
PrintArrayRandomNumber(arr,arrLength);

cout << "Odd Number counter : " <<  CheckOddnumber(arr,arrLength);


    return 0;
}