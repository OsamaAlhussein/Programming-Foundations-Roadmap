#include<iostream>
using namespace std ;

// Sum Even Numbers from 1 to N 

enum enOddOrEven{Odd=1 , Even=2};

int ReadNumber(){
    int Num ;
    cout << "Please enter a number ;\n";
    cin >> Num ;
    return Num ;
}

enOddOrEven CheckOddOrEven(int Number){
    if(Number%2==0)
    return enOddOrEven::Even;
    else 
    return enOddOrEven::Odd;
}

int SumOddNumbersFrom1ToN_UsingWhile(int N){
cout << "Sum Even numbers using while statement :\n";
    int counter = 1 , sum=0 ; 
    while(counter<=N)
    {
        if(CheckOddOrEven(counter)==enOddOrEven::Even)
        {
            sum+=counter;
        }
        counter++;
    }
    return sum ;
}


int SumOddNumbersFrom1ToN_UsingDoWhile(int N){
cout << "Sum Even numbers using do..while statement :\n";
    int counter = 0, sum = 0;
    do{
         counter++;
        if(CheckOddOrEven(counter)==enOddOrEven::Even)
        {
            sum+=counter;
        }
       
    }while(counter<N);
    
    return sum ;
}


int SumOddNumbersFrom1ToN_UsingFor(int N){

       cout << "Sum Even numbers using for statement :\n";
    int sum = 0;
    for(int counter=1 ; counter<=N ; counter++){

        if(CheckOddOrEven(counter)==enOddOrEven::Even){
            sum+=counter;
        }
    }
    return sum ;
}
int main(){

    int N = ReadNumber();
   cout << SumOddNumbersFrom1ToN_UsingFor(N) << endl;
   cout << SumOddNumbersFrom1ToN_UsingDoWhile(N) << endl;
   cout << SumOddNumbersFrom1ToN_UsingWhile(N) << endl;

    return 0;
}