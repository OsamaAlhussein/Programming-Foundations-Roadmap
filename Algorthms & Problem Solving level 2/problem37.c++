#include<iostream>
#include <string>     
#include <cstdlib>  
#include <ctime>
using namespace std ;

// Reslove problem 28 copy array using Add Array Element

int ReadNumber(string massge)
{
    int number ;
    do{
    cout << massge << endl ;
    cin >> number ;
    }while(number < 0);

    return number;
}

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

void AddArrayElement(int number , int arr[100] , int &arrLength){

    arrLength++;
    arr[arrLength - 1 ] = number ;
}

void CopyArrayElement(int arrSousce[100] , int arrDestintion[100] , int arrLength, int &arr2Length)
{
    for(int i=0; i<arrLength;i++){

AddArrayElement(arrSousce[i],arrDestintion,arr2Length);
}

}

void PrintArrayRandomNumber(int arr[100] , int arrLength)
{
    for (int i=0 ; i< arrLength ; i++)
    {
        cout << arr[i] << " ";
    
    }
    cout << "\n";
}



int main(){


    srand((unsigned)time(NULL));

     int arr[100] , arrLength ;

    FillArrayWithRandomNumber(arr,arrLength);
    cout << "Array 1 Element : \n";
PrintArrayRandomNumber(arr,arrLength);

int arr2[100] , arr2Length=0 ; 
CopyArrayElement(arr,arr2,arrLength,arr2Length);


cout << "Array 2 Element after copy :\n";
PrintArrayRandomNumber(arr2,arr2Length);




    return 0 ;
}