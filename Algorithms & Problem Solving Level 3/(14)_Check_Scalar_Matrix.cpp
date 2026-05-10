#include<iostream>
using namespace std ;


void PrintMatrix(int arrMatrix[3][3] , short Rows , short Cols){

    for(int i=0 ; i<Rows ; i++){

        for(int j=0 ; j<Cols ; j++){

            printf("%0*d    " , 1 , arrMatrix[i][j]);
        }
        cout << endl ;
    }
}

bool IsScalarMatrix1(int arrMatrix1[3][3] , short Rows , short Cols){

    int FirstDiagElemement = arrMatrix1[0][0] ;

    for(int i=0 ; i<Rows ; i++){
        for(int j=0 ; j<Cols ; j++){

            //check for diagonals element
            if(i==j && arrMatrix1[i][j]!=FirstDiagElemement){
                return false ;
            }
            //check for rest elements
            else if(i!=j && arrMatrix1[i][j]!=0){
                return false ;
            }
        }
    }
    return true ;
}



int main(){

    srand((unsigned)time (NULL));

    // int arrMatrix1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
     int arrMatrix1[3][3] = {{9,0,0} , {0,9,0} , {0,0,9}};

    // FillMatrixRandomNumbers(arrMatrix1,3,3);
    cout << "\nMatrix 1 : \n";
    PrintMatrix(arrMatrix1,3,3);

    if(IsScalarMatrix1(arrMatrix1,3,3)){
        cout << "\nYES : Matrix is Scalar.";
    }
    else 
    {
        cout << "\nNO : Matrix is Not Scalar.";
    }

        system("pause>0");

    return 0;
}