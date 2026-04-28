#include<iostream>
#include<cmath>
using namespace std ;

// Copy only prime number 

enum enPrimeNotPrime{Prime=1 , NotPrime=2};

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

enPrimeNotPrime CheckPrimeNumber(int Num){
int M = round(Num / 2) ;

    for(int count=2 ; count<=M ; count++){

        if(Num%count==0){
            return enPrimeNotPrime::NotPrime;
        }
        
    }
    return enPrimeNotPrime::Prime ;

}

void CopyOnlyPrimeNumber(int arrSource[100], int arrDestination[100], int arrLength , int &arr2Length)
{
int count = 0 ;

for (int i=0 ;i<arrLength ;i++){

    if(CheckPrimeNumber(arrSource[i])==enPrimeNotPrime::Prime){
        arrDestination[count] = arrSource[i] ;
        count++;
    }
}

arr2Length = --count ;

}


void PrintArrayRandomNumber(int arr[100] , int Length){

    for(int i=0 ; i<Length ; i++){

        cout << arr[i] << " " ;
    }
    cout << "\n";
}

int main(){

    srand((unsigned)time(NULL));

    int arr[100] , arrLength ; 

    FillArrayWithRandomNumber(arr,arrLength) ;

    int arr2[100] , arr2Length=0 ;

    CopyOnlyPrimeNumber(arr,arr2,arrLength,arr2Length) ;

cout << "\nArray 1 elements:\n";
PrintArrayRandomNumber(arr,arrLength);

cout << "\nPrime Nubmer in Array2 :\n";
PrintArrayRandomNumber(arr2,arr2Length);

    return 0;
}