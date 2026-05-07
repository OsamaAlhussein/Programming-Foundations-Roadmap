#include<iostream>
#include<iomanip>
using namespace std ;

/*This program involves filling in an array from 1 to 9 and then printing the inverse of the array.
 This is my solution.*/

void FillMatrixOrderedNumber(int arr[3][3] , int Rows , int Cols){

    int count = 0 ;

    for(int i=1 ; i<=Rows ; i++){

        for(int j=1 ; j<=Cols ; j++){
            count++;
            arr[i][j] = count ;

        }
         
    }

}


void PrintMatrixOrderedNumber(int arr[3][3] , short Rows , short Cols){

    for(int i=1 ; i<=Rows ;i++){

        for(int j=1 ;j<=Cols ; j++){

            cout << setw(3) << arr[i][j]  << "   " ; 
        }
        cout << endl ;
    }
}


void TracposeMatrix(int arr[3][3] , int arrTracpose[3][3] , short Rows , short Cols){

    for(int i=1 ; i<=Rows ; i++){

        for(int j=1 ; j<=Cols ; j++){

            arrTracpose[i][j] = arr[j][i] ;
        }
        cout << endl ;
    }
}

int main(){

    int arr[3][3] , arrTracposr[3][3] ;

    FillMatrixOrderedNumber(arr,3,3);
    cout << "The following is a 3x3 ordered matrix :\n";
    PrintMatrixOrderedNumber(arr,3,3);
    cout << endl ;
   
    TracposeMatrix(arr,arrTracposr,3,3);

    cout << "The following is a Tracpose Matrix :\n";
    PrintMatrixOrderedNumber(arrTracposr,3,3);
     system("pause>0");

    return 0;
}