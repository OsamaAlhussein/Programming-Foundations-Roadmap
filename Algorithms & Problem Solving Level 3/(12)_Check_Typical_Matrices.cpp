#include<iostream>
using namespace std ;

/*This program involves filling the first Matrix (3x3) with random numbers from 1 to 10.
Then, it fills the second matrix (3x3) with random numbers from 1 to 10 and checks each element. 
If the elements of two matrices are equal, 
it prints "equal"; if not, it prints "not equal" this my solution. */

int RandomNumber(int From , int To){
    int Random = rand() % (To - From +1)+From ;
    return Random ;
}

void FillMatrixRandomNumbers(int arrMatrix[3][3] , short Rows , short Cols){

    for(int i=0 ; i<Rows ; i++){
        for(int j=0 ; j<Cols ; j++){

            arrMatrix[i][j] = RandomNumber(1,10);
        }
    }
}


void PrintMatrix(int arrMatrix[3][3] , short Rows , short Cols){

    for(int i=0 ; i<Rows ; i++){

        for(int j=0 ; j<Cols ; j++){

            printf("%0*d    " , 2 , arrMatrix[i][j]);
        }
        cout << endl ;
    }
}


bool CheckTypcalMatrices(int arrMatrix1[3][3] , int arrMatrix2[3][3] , short Rows , short Cols){

    for(int i=0 ; i<Rows ; i++){
        for(int j=0 ; j<Cols ; j++){
            if(arrMatrix1[i][j]!=arrMatrix2[i][j]){
                return false ;
            }
        }
    }
    return true ; 
}

int main(){

    srand((unsigned)time (NULL));

    int arrMatrix1[3][3] , arrMatrix2[3][3] ;

    FillMatrixRandomNumbers(arrMatrix1,3,3);
    cout << "\nMatrix 1 : \n";
    PrintMatrix(arrMatrix1,3,3);

    FillMatrixRandomNumbers(arrMatrix2,3,3);
    cout << "\nMatrix 2 : \n";
    PrintMatrix(arrMatrix2,3,3);

    if(CheckTypcalMatrices(arrMatrix1,arrMatrix2,3,3))
        cout << "\nYES : both Matrices are equal.\n";
    else 
        cout << "\nNo : both Matrices are Not equal.\n";

        system("pause>0");
    return 0;
}