#include<iostream>
#include<iomanip>
using namespace std ;


void PrintMatrix(int Matrix[3][3] , short Rows , short Cols){

    for(int i=0 ;i<Rows ;  i++){

        for(int j=0 ; j<Cols ; j++){

           cout << setw(2) << Matrix[i][j] << "  ";
        }
        cout << endl ;
    }
}

bool IsPalndomeNumber(int Matrix[3][3] , short Rows , short Cols){

    for(int i=0 ; i<Rows ; i++){
        for(int j=0 ; j<Cols/2 ; j++){
            if(Matrix[i][j]!=Matrix[i][Cols-1-j]){
                return false ;
            }
        }
    }
    return true ;
}

int main(){

    int Matrix[3][3] = {{1,2,1} , {5,5,5} , {7,3,7}};

    cout << "Matrix 1 :\n";
    PrintMatrix(Matrix,3,3);

    if(IsPalndomeNumber(Matrix,3,3)){
        cout << "\nYES : Matrix is Palindrome . \n";

    }
    else{
        cout<< "\nNO : Matrix is NOT Palindrome .\n";
    }

    system("pause>0");


    return 0;
}