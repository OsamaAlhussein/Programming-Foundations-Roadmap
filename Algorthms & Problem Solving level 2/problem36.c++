#include<iostream>
using namespace std ;

// Add array element simi Dynamic 

int ReadNumber(){

    int number ;
    do{

        cout <<"pleas enter the Number ?"<< endl ;
        cin>> number ; 

    }while(number <0);

    return number ;
}

void AddArrayElmenet(int number , int arr[100] , int &arrLength )
{
    arrLength++;
    arr[arrLength - 1] =number ;
}

void InputUserNumberinArray(int arr[100] ,int &arrLength){

    bool AddMore = true ;

    do{

        AddArrayElmenet(ReadNumber(),arr,arrLength);

        cout << "\nDo you want Add more nubmers ? [0]:No , [1]:Yes ?\n";
        cin >> AddMore ;

    }while(AddMore);
}

void PrintArray(int arr[100], int arrLength){
    for(int i=0 ; i<arrLength; i++)
    {
        cout << arr[i] << " ";

    }
    cout << "\n";
}
int main(){

    int arr[100] , arrLength =0 ;
    InputUserNumberinArray(arr,arrLength);
    cout << "Array Length : " << arrLength << endl ;

    cout << "Array elemenet : ";
    PrintArray(arr,arrLength);



    return 0 ;
}