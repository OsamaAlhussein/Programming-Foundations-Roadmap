#include<iostream>
#include<iomanip>
using namespace std ;

int RandomNumber(int From , int To ){

    int Random = rand() % (To - From +1) + From ;
    return Random ;
}

void FillMatrixRandomNumbers(int Matrix1[3][3] , short Rows , short Cols){

    for(int i=0 ; i<Rows ; i++){

        for(int j=0 ; j<Cols ; j++){

            Matrix1[i][j]=RandomNumber(1,10);
        }
    }
}


void PrintMatrix(int Matrix1[3][3] , short Rows , short Cols){

    for(int i=0 ; i<Rows ; i++){

        for(int j=0 ; j<Cols ; j++){

            printf("%0*d   ",2,Matrix1[i][j]);
        }
        cout << endl ;
    }
}


int  SumOfMatrix(int Matrix1[3][3] , short Rows , short Cols){
    int Sum =0 ;

    for(int i=0 ;i<Rows ; i++){

        for(int j=0 ; j<Cols ; j++){

            Sum += Matrix1[i][j] ;
        }
    }
    return Sum ;
}

int main(){
    srand((unsigned)time(NULL));
    int Matrix1[3][3] ;

    FillMatrixRandomNumbers(Matrix1,3,3);
    cout << "\nMatrix 1 :\n";
    PrintMatrix(Matrix1,3,3);

    cout << "\n\nSum of matrix 1 is : "<< SumOfMatrix(Matrix1,3,3) << endl ;

    system("pause>0");


    return 0;
}