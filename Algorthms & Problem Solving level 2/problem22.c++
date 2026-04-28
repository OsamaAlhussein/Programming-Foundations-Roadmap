#include<iostream>
using namespace std ;
//  Repeated Elements Count In Array 

int ReadPositiveNumber(string massge)
{
int number ;
do
{
    cout << massge << endl ;
    cin >> number ;

}while(number<=0);
return number ; 
}



void ReadArry(int arr[100] , int &arrLength)
{
 cout << "Enter Array Elemenet ? \n";
    cin >> arrLength ;
 for (int i=0 ; i<arrLength ; i++)
 {
    cout << "Element ["<<i+1<<"] : ";
    cin >> arr[i] ;
 }
 cout << endl ;
}

void PrintArray(int arr[100] , int arrLength)
{
    for(int i=0 ; i<arrLength ; i++)
    {
        cout << arr[i] << " ";
    }
    cout <<"\n";
}

int TimesRepeated(int number , int arr[100] , int arrLength )
{
    int counter=0 ;
     
    for (int i=0 ; i<arrLength ; i++)
    {
        if(arr[i]==number)
        {
            counter++;
        }
    }
    return counter ;
}



int main()
{
int arr[100] , arrLength ;

ReadArry(arr,arrLength);

int Number =  ReadPositiveNumber("Enter the number you wont to check ?! ");

cout << "Original array : " ;
PrintArray(arr,arrLength);

cout << Number << " is repeated " << TimesRepeated(Number,arr,arrLength) << " Time(s)";







    return 0 ;
}