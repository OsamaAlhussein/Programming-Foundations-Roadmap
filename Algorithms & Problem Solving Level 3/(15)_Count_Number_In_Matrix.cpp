#include<iostream>
using namespace std ;


/*This program is a 3x3 Matrix filled with numbers. 
I give it a number, it searches for it in this matrix,
 and it returns how many times that number appears,
  this my solution .*/


int ReadNumber(){

    int Num = 0;
    cout << "Enter the number to count in matrix ?  ";
    cin >> Num ;
    return Num ;
}


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


int main(){

    int Matrix1[3][3] = { {9,1,12} , {0,9,1} , {0,9,9}};

    cout << "Matrix 1 : \n";
    PrintMatrix(Matrix1,3,3);

    int N = ReadNumber() ;

    cout << "\nNumber " << N << " count in matrix is : " << CountNumberInMatrix(Matrix1,N,3,3) << endl ;

    system("pause>0") ;

    return 0;
}