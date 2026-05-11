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


int  MinNumberInMatrix(int Matrix[3][3] , short Rows , short Cols){

    int Min = Matrix[0][0] ;
    for(int i=0 ; i<Rows ; i++){
        for(int j=0 ;j<Cols ; j++){
            if(Matrix[i][j]<Min){
                Min = Matrix[i][j] ;
            }

        }
    }
    return Min ;
}

int  MaxNumberInMatrix(int Matrix[3][3] , short Rows , short Cols){

    int Max = 0 ;
    for(int i=0 ; i<Rows ; i++){
        for(int j=0 ;j<Cols ; j++){
            if(Matrix[i][j]>Max){
                Max = Matrix[i][j] ;
            }

        }
    }
    return Max ;
}




int main(){

    int Matrix1[3][3] = {{77,5,12} , {22,20,1} , {1,0,9}};
    int Matrix2[3][3] = {{5,80,90} , {22,77,1} , {10,8,33}};

    cout << "Matrix 1 :\n";
    PrintMatrix(Matrix2,3,3);

    cout << "\nMinimum Number is : " << MinNumberInMatrix(Matrix2,3,3) << endl;

    cout << "\nMax Number is : " << MaxNumberInMatrix(Matrix2,3,3) ;



    system("pause>0");



    return 0;
}