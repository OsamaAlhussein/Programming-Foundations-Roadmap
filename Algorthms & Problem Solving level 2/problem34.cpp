#include<iostream>
using namespace std ;


// Return number index in array 

int ReadNumber(){
int Num ;
    cout << "Please enter a number to search for ?\n";
    cin >> Num ;
    return Num ;
}

int RandomNumber(int From , int To){

    int Random = rand()% (To - From +1)+From ;
    return Random ;
}

void FillArrayWithRandomNumber(int arr[100] , int &arrLength)
{
    cout << "Enter Array element ?\n";
    cin >> arrLength ;

    for(int i=0 ; i<arrLength ; i++){

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

int FindNumberPositionInArray(int arr[100] , int arrLength , int Num){

    for(int i=0 ; i<arrLength ; i++){

        if(arr[i]==Num)
        {
            return i ;
        }
        
    }
    return -1 ;
}


int main(){
    srand((unsigned)time(NULL));

    int arr[100] , arrLength ;

    FillArrayWithRandomNumber(arr,arrLength);
    cout << "\nArray 1 elements:\n";
    PrintArrayRandomNumber(arr, arrLength);

    int Num = ReadNumber();
        cout << "\nNumber you are looking for is: " << Num << endl;

     short NumberPosition = FindNumberPositionInArray(arr , arrLength , Num);

     if(NumberPosition==-1){
       cout << "The number is not found :-(\n";

     }
     else 
     {
         cout << "The number found at position: " << NumberPosition << endl;
        cout << "The number found its order  : " << NumberPosition + 1 << endl ;
     }
     
    return 0;
}