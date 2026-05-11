#include<iostream>
using namespace std ;

/*This program is a 3x3 Matrix filled with numbers.
 If the zero counter is greater than the regular number counter,
  it prints "Yes: It's sparse." If not, it prints "No: It's not sparse," and that's 
my solution.*/



void PrintMatrix(int Matrix[3][3] , short Rows , short Cols){

    for(int i=0 ;i<Rows ;  i++){

        for(int j=0 ; j<Cols ; j++){

            printf("%0*d   ",1 , Matrix[i][j]);
        }
        cout << endl ;
    }
}


short  CountNumberInMatrix(int Matrix[3][3] , int Number , short Rows , short Cols ){
 
    short Counter = 0;
    for(int i=0 ; i<Rows ; i++){
        for(int j=0 ; j<Cols ; j++){
            if(Matrix[i][j]==Number){

                Counter++;
            }
        }
    }
    return Counter ;
}

bool IsSparseMatrix(int Matrix[3][3] , short Rows , short Cols){
short MatrixSize = Rows*Cols ;
    return (CountNumberInMatrix(Matrix,0,3,3) >= (MatrixSize / 2 )) ;
}


int main(){

    int Matrix[3][3] = {{0,0,0} , {10,1,1} , {12,9,1}} ;

    cout << "Matrix 1 : \n";
    PrintMatrix(Matrix,3,3);

    if(IsSparseMatrix(Matrix,3,3)){
        cout << "\nYES : It is Sparse. \n";
    }
    else 
    {
        cout << "\nNO : It is NOT Sparse. \n";
    }

    system("pause>0");

    return 0;
}