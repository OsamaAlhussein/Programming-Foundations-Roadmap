#include<iostream>
#include<ctime>
#include<cmath>

using namespace std ;

// Sum of Random array

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

int SumOfRandomArray(int arr[100] , int Length){

    int sum =0 ;
    for(int i=0 ; i<Length ; i++){

        sum+=arr[i] ;
    }

    return sum ;
    
}

int main(){

    srand((unsigned)time(NULL));
    int arr[100] , Length ;
    FillArrayWithRandomNumber(arr,Length);
    
    cout << "\nArray Element : " ;
    PrintArrayRandomNumber(arr,Length);

    cout << "Sum of all number is : " <<  SumOfRandomArray(arr,Length) ;

    return 0;
}