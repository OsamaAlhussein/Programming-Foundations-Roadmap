#include<iostream>
#include<string>
#include<iomanip>
using namespace std ;

/*Write a program for a 3x3 array filled with numbers from 1 to 100, then print the sum of each column, 
This is my solution.
*/

int RandomNumber(int From , int To){

    int Random = rand() % (To - From + 1) + From ;

    return Random ;
}


void FillMatrixWithRandomNumbers(int  arr[3][3] , short Rows , short Cols){

    for(int i=0 ; i<Rows ;i++){

    for(int j=0; j<Cols ; j++){

        arr[i][j] = RandomNumber(1,100) ;
    }
    }

}


void PrintMatrix(int arr[3][3] , short Rows , short Cols){

   
    for(int i=0 ;i<Rows ; i++){

        for(int j=0 ; j<Cols ;j++){

            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << endl ;
    }

}

int ColsSum(int arr[3][3] , short Row , short ColNumber){

    int Sum=0 ;
    for(int i=0 ; i<Row ; i++)
    {
        Sum += arr[i][ColNumber] ;
    }
    return Sum ;
}


void PrintEachColSum(int arr[3][3] , short Rows , short Cols){

    cout << "The following are the sum of each col in the matrix :\n";

    for(int i=0 ; i<Cols ; i++){

        cout << "Col " << i+1 << " Sum = " << ColsSum(arr,Rows,i) << endl ;
    }

}


int main(){

    srand((unsigned)time(NULL));

    int arr[3][3] ;

    FillMatrixWithRandomNumbers(arr,3,3);
     cout << "The following is a 3x3 Random Matrix \n";
    PrintMatrix(arr,3,3);
    
    PrintEachColSum(arr,3,3);
    system("pause>0");
    

    return 0;
}