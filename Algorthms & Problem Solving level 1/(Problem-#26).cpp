#include<iostream>
using namespace std ;


//Print Numbers from 1 to N 


int ReadNumber(){
    int Num ;
    cout << "Please enter a number ;\n";
    cin >> Num ;
    return Num ;
}


void PrintRangFrom1ToN_UsingWhile(int N){

    cout << "Range Printed using while statement :\n";
    int counter = 1 ;
    while(N>=counter){

        cout << counter << endl ;
        counter++ ;
    }
    cout << endl ;
}

void PrintRangFrom1ToN_UsingDoWhile(int N){

    cout << "Range Printed using do..while statement :\n";
    int counter = 0;
    do{
        counter++;
        cout << counter << endl ;
    }while(N>counter);
    cout << endl ;
}



void PrintRangFrom1ToN_UsingFor(int N){

    cout << "Range Printed using for statement :\n";
    for (int counter=1 ; counter<=N ; counter++){

        cout << counter << endl ;

    }
    cout << endl ;

}
int main(){

    int N = ReadNumber();
    PrintRangFrom1ToN_UsingWhile(N);
    PrintRangFrom1ToN_UsingDoWhile(N);
    PrintRangFrom1ToN_UsingFor(N);


    return 0;
}