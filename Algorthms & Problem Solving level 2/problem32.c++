#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std ;

// Copy Array In Reverse order

int ReadNubmer(string massge)
{
    int number ;
    do
    {
        cout << massge <<endl ;
        cin >> number ;

    }while(number<0);
    return number ;

}



int RandomNumber(int from , int To)
{
int Random = rand() % (To - from +1 ) + from ;
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


void CopyArrayReverers(int arrSousce[100] , int arrDestion[100] , int arrLength){


    for(int i=0 ; i<arrLength ; i++)
    {
        arrDestion[i] = arrSousce[arrLength -1 - i];
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




int main(){

srand((unsigned)time(NULL));

int arr[100];
int arrLength = ReadNubmer("Enter number of elemenet ?\a");

FillArrayWithRandomNumber(arr,arrLength);
cout << "Array 1 Elemenet : \n";
PrintArrayRandomNumber(arr,arrLength);
int arr2[100];
CopyArrayReverers(arr,arr2,arrLength);

cout << "Array 2 elemenet after coping array 1 in reversed order : \n";
PrintArrayRandomNumber(arr2,arrLength);



    return 0 ; 
}