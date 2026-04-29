#include<iostream>
#include <string>     
#include <cstdlib>  
#include <ctime> 
using namespace std ;

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

void FillArrayWithRandomNumber(int arr[100] , int arrLength)
{

    
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

int Checkenterusernumber(int arr[100], int arrLength , int number)
{
    for(int i=0 ; i<arrLength ; i++)
    { 
      if(number==arr[i])
      {
         return i ;
      }
      
    }
     return -1;
}
int main(){

srand((unsigned)time(NULL));
int arr[100] ,  arrLength = ReadNumber("Enter Array Elemenet?");

FillArrayWithRandomNumber(arr,arrLength);
cout << "Array 1 Element : \n";
PrintArrayRandomNumber(arr,arrLength);

int Number = ReadNumber("pleas enter a number to serch for ?");

if(Checkenterusernumber(arr,arrLength,Number)!=-1)
{
    cout << "Number your are looking for is : " << Number <<endl ;
      cout <<  "Yes , The Number is found at : -)";

}
else 
{
    cout << "Number your are looking for is : " << Number << endl  ;
      cout <<  "The Number is not found at : -(";
}



    return 0 ; 
}