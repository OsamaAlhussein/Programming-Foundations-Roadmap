#include<iostream>
#include <string>     
#include <cstdlib>  
#include <ctime>
#include<cmath>
using namespace std ;

// Copy prime numbers to a new array 

enum enprimeNotprim{prime=1 , Notprime=2};

enprimeNotprim CheckPrimeNubmer(int Number)
{
int M = round(Number / 2);

for (int counter = 2 ; counter<=M ; counter++)
{
    if(Number%counter==0)
    return enprimeNotprim::Notprime;
     
    
}
return enprimeNotprim::prime;

}

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
    arr[arrLength-1]=number ;
}


void CopyePrimeNumbers(int arrSousce[100] , int arrDestintion[100] , int arrlength , int &arr2Length )
{

    for(int i=0 ; i<arrlength ;i++){

        if(CheckPrimeNubmer(arrSousce[i])==enprimeNotprim::prime)
        {
            AddArrayElement(arrSousce[i],arrDestintion,arr2Length);
        }
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
CopyePrimeNumbers(arr,arr2,arrLength,arr2Length);
cout <<"\nArray 2 Prime numbers :\n";
PrintArrayRandomNumber(arr2, arr2Length);

    return 0;
}