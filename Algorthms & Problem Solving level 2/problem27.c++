
#include<iostream> 
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std ;

// Average of Random Array 

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


float AvreageOfRandomArray(int arr[100] , int Length){

    return (float) SumOfRandomArray(arr,Length) / Length ;
}

int main(){

  srand((unsigned)time(NULL));

      int arr[100] , Length ;
    FillArrayWithRandomNumber(arr,Length);
    
    cout << "\nArray Element : " ;
    PrintArrayRandomNumber(arr,Length);


    cout << "\nAverage of all number is : " << AvreageOfRandomArray(arr,Length) ;

    return  0 ; 
}