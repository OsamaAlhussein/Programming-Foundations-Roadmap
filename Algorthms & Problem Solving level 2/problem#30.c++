#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std ;

enum enprimNumber{prime=1 , Notprime = 2};


enprimNumber CheckPrimeNumber(int number)
{
    int M =  round(number / 2) ;
    for (int counter=2 ; counter <= M ; counter++)
    {
        if(number%counter == 0 )
        {
            return enprimNumber::Notprime;
        }   
    }
    return enprimNumber::prime;
}

int RandomNumber(short From , short To)
{
    short Random = rand() % (To - From + 1)+ From ;
    return Random ;
}

void FillArrayWithRandomNumber(int arr[100] , int &arrLength)
{
    cout << "Enter Array Elmenet ?\n";
    cin >> arrLength ;
    for (int i=0 ; i<arrLength; i++)
    {
        arr[i] = RandomNumber(1,100);
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

void printprimeArray(int arr[100], int arrLength)
{
    for(int i=0 ; i<arrLength ; i++)
    {
        if(CheckPrimeNumber(arr[i])==enprimNumber::prime)
        {
            cout << arr[i] <<" ";
        }
    }
}

int main(){

srand((unsigned)time(NULL));

int arr[100] , arrLength ;

FillArrayWithRandomNumber(arr,arrLength);

cout << "Array 1 elemenet :\n";
PrintArrayRandomNumber(arr,arrLength);

cout << "Prime Numbers in Array 2:\n";
printprimeArray(arr,arrLength);



    return 0 ;
}