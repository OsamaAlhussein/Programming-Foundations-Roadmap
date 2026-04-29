#include<iostream>
#include <string>     


using namespace std ;

// Count Even numbers in array 

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

int EvenCount(int arr[100], int arrLength)
{
    int counter=0;
    for(int i=0; i<arrLength ; i++)
    {
        if (arr[i]%2==0)
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

cout << "Even Number counter is : " <<  EvenCount(arr,arrLength);


    return 0;
}