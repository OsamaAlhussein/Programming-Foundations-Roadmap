#include<iostream>
using namespace std ;


/*This program involves filling the first matrix (3x3) with random numbers from 1 to 10,
 and then filling the second matrix (3x3) with numbers from 1 to 10.
  Next, we add the two matrices and compare them. 
  If the matrices are equal, we print that they are equal;
   if they are not, we print that they are not equal. 
   This is my  solution I .*/

int RandomNumber(int From , int To){

    int Random = rand() % (To - From +1) + From ;
    return Random ;
}

void FillMatrixRandomNumbers(int Matrix[3][3] , short Rows , short Cols){

    for(int i=0; i<Rows ; i++){

        for(int j=0 ; j<Cols ; j++){

            Matrix[i][j] = RandomNumber(1,10);
        }
    }
}


void PrintMatrix(int Matrix[3][3] , short Rows , short Cols){

    for(int i=0 ; i<Rows ; i++){

        for(int j=0 ; j<Cols ; j++){

            printf("%0*d   ",2,Matrix[i][j]);
        }
        cout << endl ;
    }
}

int SumOfMatrix(int Matrix[3][3] , short Rows , short Cols){

    int Sum = 0;

    for(int i=0 ; i<Rows ; i++){

        for(int j=0 ; j<Cols ; j++){

            Sum += Matrix[i][j] ;
        }
    }
    return Sum ;
}

bool CheckMatrixEquality(int Matrix1[3][3] , int Matrix2[3][3] , short Rows , short Cols){

    return (SumOfMatrix(Matrix1,Rows,Cols)==SumOfMatrix(Matrix2,Rows,Cols));
}

int main(){

    srand((unsigned)time(NULL));

    int Matrix1[3][3] , Matrix2[3][3] ;

    FillMatrixRandomNumbers(Matrix1,3,3);
    cout << "\nMatrix 1 :\n";
    PrintMatrix(Matrix1,3,3);

    FillMatrixRandomNumbers(Matrix2,3,3);
    cout << "\nMatrix 2 :\n";
    PrintMatrix(Matrix2,3,3);


    if(CheckMatrixEquality(Matrix1,Matrix2,3,3)){

        cout << "\nYES : both Matrices are equal.\n";
    }
    else {
        cout << "\nNO : both Matrices are Not equal.\n";
    }

    system("pause>0");



    return 0;
}