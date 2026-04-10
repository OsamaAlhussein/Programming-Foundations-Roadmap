#include<iostream>
using namespace std ;


void ReadNumbers(int &A , int &B){
    
    cout << "Pleas enter A ?\n";
    cin >> A ;

    cout << "Pleas enter B ?\n";
    cin >> B ;

}

float CalculatRectangleArea(float A ,float B){
    return A*B;
}

void PrintResult(float Area){
    cout << "\nRectangl Area = " << Area << endl ;
}


int main(){
int A , B ;
ReadNumbers(A,B);
PrintResult(CalculatRectangleArea(A,B));

    return 0;
}