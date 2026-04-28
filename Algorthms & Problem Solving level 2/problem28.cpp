#include<iostream>
using namespace std ;

// Copy Array

int RandomNumber(int From , int To){
    int Random = rand() % (To - From + 1 ) +From;
    return Random ;
}

void FillArrayWithRandomNumber(int arr[100] , int &Length){

    cout << "Enter Array Elemnt ?\n";
    cin >> Length ;

    for(int i=0 ; i<Length ; i++){

        arr[i] = RandomNumber(1 , 100);
    }
}

void PrintArrayRandomNumber(int arr[100] , int Length){

    for(int i=0 ; i<Length ; i++){

        cout << arr[i] << " " ;
    }
    cout << "\n";
}

void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
{

for(int i=0 ; i<arrLength ; i++){
    arrDestination[i] = arrSource[i] ;
}

}

int main(){

srand((unsigned)time(NULL));

int arr[100] , arrLength ;

FillArrayWithRandomNumber(arr,arrLength);

int arr2[100] ;
    cout << "\nArray 1 elements:\n";
PrintArrayRandomNumber(arr,arrLength);

CopyArray(arr,arr2,arrLength);
    cout << "\nArray 2 elements after copy:\n";
PrintArrayRandomNumber(arr2,arrLength);

    return 0;
}