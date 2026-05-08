#include<iostream>
#include<iomanip>
using namespace std ;

/*This program involves filling the first array with random numbers from 1 to 10,
 and finally printing only the second row and the second column.
 That's my solution.*/


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


void PrintMatrix(int arr[3][3] , short Rows , short Cols){

    for(int i=0 ; i<Rows ; i++){

        for(int j=0 ; j<Cols ; j++){

             printf("%0*d   " , 2 , arr[i][j]) ;
        }
        cout << endl ;
    }
}

void PrintMiddleRow(int arr[3][3] , short RowNumber , short Col){

        for(int j=0 ; j<Col ;j++){

            printf("%0*d  " , 2 , arr[RowNumber-1][j]) ;
        }
    
}

void PrintMiddleCol(int arr[3][3] , short Row , short ColNumber){

    for(int i=0 ; i<Row ; i++){

        printf("%0*d   ", 2 , arr[i][ColNumber-1]) ;
    }
}

int main(){
    srand((unsigned)time(NULL));

    int Matrix1[3][3] ;
    
    FillMatrixRandomNumbers(Matrix1,3,3);
    cout << "Matrix 1 :\n";
    PrintMatrix(Matrix1,3,3);

    cout << "Middle Row of Matrix 1 is :\n";
    PrintMiddleRow(Matrix1,2,3);
    cout << endl ;

    cout << "Middle col of Matrix 1 is : \n";
     PrintMiddleCol(Matrix1,3,2);


    system("pause>0");


    return 0;
}