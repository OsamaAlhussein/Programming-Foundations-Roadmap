#include<iostream>
using namespace std ;

// Shuffle ordered array

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
void FillArrayWithRandomNumber(int arr[100] , int arrLength)
{

    
    for(int i=0 ; i<arrLength ; i++)
    {
        arr[i] = i+1 ;
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

void Swap(int &A , int &B)
{
    int Temp ;
    Temp = A ;
    A = B ;
    B = Temp ;
}
int RandomNumber(int from , int To)
{
int Random = rand() % (To - from +1 ) + from ;
return Random ;
}

void ShufflArray(int arr[100], int arrLenght){

int index1 , index2 ;
for(int i=0 ; i<arrLenght ; i++){

index1 = RandomNumber(1,arrLenght) - 1 ;
index2 = RandomNumber(1,arrLenght) -1 ; 

Swap(arr[index1],arr[index2]);

}

}


int main(){

int arr[100]  ;
int arrLength = ReadNubmer("Enter number of elemenet ?\a");

FillArrayWithRandomNumber(arr,arrLength);
cout << "Array  Elemenet befor shuffl :\n";
PrintArrayRandomNumber(arr,arrLength);
ShufflArray(arr,arrLength);

cout << "Array elmenet after shuffl :\n";
PrintArrayRandomNumber(arr,arrLength);
    return 0 ;
}