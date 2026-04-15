#include<iostream>
#include<string>
using namespace std ;

// sum until -99

float ReadNumber(string Message){

    float Num ;
    cout << Message << endl ;
    cin  >> Num ;

    return Num ;
}

float SumNumbers(){
    
    int Sum =0 , Number=0 , counter=1 ;

    do{
        Sum+=Number ;
        Number = ReadNumber("Please enter The Number " + to_string(counter));
        counter++ ;
    }while(Number!=-99);

    return Sum ;
}

int main(){

    int Sum = SumNumbers() ;
    cout << endl << "Result = " << Sum ;


    return 0;
}