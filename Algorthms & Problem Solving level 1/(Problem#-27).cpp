#include<iostream>
using namespace std ;

// Print Numbers from N to 1 


int ReadNumber(){
    int Num ;
    cout << "Please enter a number ;\n";
    cin >> Num ;
    return Num ;
}


void PrintRangFrom1ToN_UsingWhile(int N){

    cout << "Range Printed using while statement :\n";
    
    while(N>=1){

        cout << N << endl ;
        N--;
    }
    cout << endl ;
}

void PrintRangFrom1ToN_UsingDoWhile(int N){

    cout << "Range Printed using do..while statement :\n";
    int counter = N + 1;
    do{
        counter--;
        cout << counter << endl ;
    }while(counter>1);
    cout << endl ;
}


void PrintRangFrom1ToN_UsingFor(int N){

    cout << "Range Printed using for statement :\n";
    for (int counter=1 ; N>=counter ; N--){

        cout << N << endl ;

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