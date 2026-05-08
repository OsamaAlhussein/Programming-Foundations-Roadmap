#include<iostream>
#include<iomanip>
using namespace std ;


/*This program involves filling the first array with random numbers from 1 to 10,
 and the second array with the same numbers.
 The program then prints the product of the two arrays and the final result.
 This is my solution.
*/

int RandomNumbers(int From , int To){
    int Random = rand() % (To - From +1 ) +From ;
    return Random ;
}


void FillMatrixRandomNumbers(int arr[3][3] , int Rows , int Cols){

    for(int i=0 ;i<Rows ; i++){

        for(int j=0 ; j<Cols ; j++){

            arr[i][j] = RandomNumbers(1,10);
        }
    }
}


void MultiplyingMatrices(int Matrix1[3][3] , int Matrix2[3][3] , int MatrixResult[3][3] , short Rows , short Cols){

    for(int i = 0 ; i<Rows ; i++){

        for(int j=0 ; j<Cols ; j++){
        
            MatrixResult[i][j] = Matrix1[i][j] * Matrix2[i][j] ;
        }
    }
}

void PrintMatrix(int arr[3][3] , short Rows , short Cols){

    for(int i=0 ; i<Rows ; i++){

        for(int j=0 ; j<Cols ; j++){

             printf("%0*d   " , 2 , arr[i][j]) ;
        }
        cout << endl ;
    }
}

int main(){
    srand((unsigned)time(NULL));

    int Matrix1[3][3] , Matrix2[3][3] , MatrixResult[3][3] ;
    
    FillMatrixRandomNumbers(Matrix1,3,3);
    cout << "Matrix 1 : \n";
    PrintMatrix(Matrix1,3,3);
    cout << endl ;

    FillMatrixRandomNumbers(Matrix2,3,3);
    cout << "Matrix 2 : \n";
    PrintMatrix(Matrix2,3,3);
    cout << endl ;
    MultiplyingMatrices(Matrix1,Matrix2,MatrixResult,3,3);

    cout << "Result Matrix 1 * Mateix 2 : \n";
    PrintMatrix(MatrixResult,3,3) ;
    
    system("pause>0");

    return 0;
}