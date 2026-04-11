#include<iostream>
using namespace std ;


//Read Age Between 18 and 45   

int ReadAge(){
    int Age ;

    cout << "Please enter your Age ?\n";
    cin >> Age ;
    return Age ;
}

bool ValidateNumberInrange(int Number ,int From , int To){

    return (Number >= From && Number <= To );
}

void PrintResult(int Age){
    if(ValidateNumberInrange(Age,18,45))
        cout << " is a valid age \n";
    else 
        cout << " is a invalid age \n";

}

int main(){

    PrintResult(ReadAge());


    return 0;
}