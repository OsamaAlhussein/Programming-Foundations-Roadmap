#include<iostream>
using namespace std ;

/*This program is a 3x3 Matrix filled with numbers.
 We give the program a number,
 and it searches the Matrix; if the number exists,
it indicates that it exists, and if not, 
 it indicates that it does not exist.
 That's my solution.*/


void PrintMatrix(int Matrix[3][3] , short Rows , short Cols){

    for(int i=0 ;i<Rows ;  i++){

        for(int j=0 ; j<Cols ; j++){

            printf("%0*d   ",1 , Matrix[i][j]);
        }
        cout << endl ;
    }
}


bool  IsNumberInMatrix(int Matrix[3][3] , int Number , short Rows , short Cols ){
 
   
    for(int i=0 ; i<Rows ; i++){
        for(int j=0 ; j<Cols ; j++){
            if(Matrix[i][j]==Number){

                return true ;
            }
        }
    }
    return false ;
}




int main(){

    int Matrix[3][3] = {{10,20,30} , {11,15,18} , {12,9,1}} ;

    cout << "Matrix 1 : \n";
    PrintMatrix(Matrix,3,3);

    int Num = 0;
    cout << "Enter the number to count in matrix ?  ";
    cin >> Num ;
    

    if(IsNumberInMatrix(Matrix,Num,3,3)){
        cout << "\nYES : It is there. \n";
    }
    else 
    {
        cout << "\nNO : It is NOT there. \n";
    }

    system("pause>0");

    return 0;
}