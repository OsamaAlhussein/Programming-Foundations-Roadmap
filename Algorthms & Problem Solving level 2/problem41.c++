#include<iostream>
using namespace std ;

// Is Palindrom Array 
void FillArray(int arr[100] , int &arrLength){

    arrLength=5;
    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    arr[3]=20;
    arr[4]=10;

}

void PrintArray(int arr[100], int arrLength){

    for (int i=0 ; i<arrLength ; i++)
    {

        cout << arr[i] <<" ";

    }
}

bool IsPalindromArray(int arr[100] , int arrLength)
{
    
    for(int i=0 ; i<arrLength ; i++)
    {
        if(arr[i]!=arr[arrLength-i-1])
        {
            return false ;
        }     

        return true ;
    }

}

int main(){
int arr[100], arrLength ;

FillArray(arr,arrLength);
cout << "Array 1 elmenet :\n";
PrintArray(arr,arrLength);
 
if(IsPalindromArray(arr,arrLength))
 cout << "\nYes array is Palindrome\n";
    else
        cout << "\nNO array is NOT Palindrome\n";

    return 0 ;
}