#include<iostream>
#include<string>
#include<iomanip>
using namespace std ;


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

int RowSum(int arr[3][3] , short RowNumber , short Cols){

    int sum =0;
    for(int j=0 ; j<Cols ; j++){

            sum = sum + arr[RowNumber][j] ;
        }
    
    return sum ;
}


void PrintEachRowSum(int arr[3][3] , short Rows , short Cols){

    cout << "The following are the sum of each row in the matrix :\n";

    for(int i=0 ; i<Rows ; i++){

        cout << "Row " << i+1 << " Sum = " << RowSum(arr,i,Cols) << endl ;
    }

}


int main(){

    srand((unsigned)time(NULL));

    int arr[3][3] ;

    FillMatrixWithRandomNumbers(arr,3,3);
     cout << "The following is a 3x3 Random Matrix \n";
    PrintMatrix(arr,3,3);

    PrintEachRowSum(arr,3,3);

    
    system("pause>0");
    

    return 0;
}