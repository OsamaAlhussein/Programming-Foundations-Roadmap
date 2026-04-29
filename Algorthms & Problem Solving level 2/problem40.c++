#include<iostream>
using namespace std ;

// Copy Distinct Numbers to Array 

void FillArrayElment(int arr[100] ,int &arrLength )
{
    arr[0]=10;
    arr[1]=10;
    arr[2]=10;
    arr[3]=50;
    arr[4]=50;
    arr[5]=70;
    arr[6]=70;
    arr[7]=70;
    arr[8]=70;
    arr[9]=90;

}

void PintArrayElment(int arr[100] , int arrLength){

    for(int i=0 ; i<arrLength ; i++)
    {
        cout << arr[i] << "  " ;
    }
    cout << "\n ";
}

short  Checkenterusernumber(int arr[100], int arrLength , int number)
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

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return Checkenterusernumber(arr,arrLength,Number)!=-1;
}

void AddArrayElement(int number , int arr[100] , int &arrLength){

    arrLength++;
    arr[arrLength-1]=number ;
}

void CopyDistionNubmerToArray(int arrSource[100] , int arrDesintion[100] , int arrLength ,int &DestinationLength )
{
    for(int i=0 ; i<arrLength ; i++)
    {
        if(!IsNumberInArray(arrSource[i],arrDesintion,DestinationLength))
        {
            AddArrayElement(arrSource[i],arrDesintion,DestinationLength);
        }

    }

    
}

int main(){

    int arr[100] ,SourceLength =10 , arr2[100] , DestinationLength=0 ;

    FillArrayElment(arr,SourceLength);
    cout << "Array 1 Element : \n";
    PintArrayElment(arr,SourceLength);

    CopyDistionNubmerToArray(arr,arr2,SourceLength,DestinationLength);

    cout << "Array 2 element :\n";
    PintArrayElment(arr2,DestinationLength);











    return 0 ; 
}