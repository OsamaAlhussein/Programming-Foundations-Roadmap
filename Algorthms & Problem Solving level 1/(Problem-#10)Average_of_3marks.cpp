#include<iostream>
using namespace std ;

void ReadNumbers(int &Mark1 , int &Mark2 , int &Mark3){

    cout << "Pleas enter your Mark 1 ?"<< endl ;
    cin >> Mark1 ;
    
    cout << "Pleas enter your Mark 2 ?"<< endl ;
    cin >> Mark2 ;

    cout << "Pleas enter your Mark 3 ?"<< endl ;
    cin >> Mark3 ;

}

int SumOf3Marks(int Mark1 ,int Mark2 , int Mark3){

    return Mark1 + Mark2 + Mark3 ;
}

float CaluclatAvreage(int Mark1 ,int Mark2 , int Mark3){

    return (float)  SumOf3Marks(Mark1,Mark2,Mark3) / 3 ;
}


void PrintResult(float Avreage){

    cout << "The avreage is : " << Avreage << endl ;
}



int main(){

 int Mark1 , Mark2 , Mark3 ;

 ReadNumbers(Mark1,Mark2,Mark3);
 PrintResult(CaluclatAvreage(Mark1,Mark2,Mark3));

    return 0;
}
