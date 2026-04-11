#include<iostream>
using namespace std ;

// Read Until Age Between 18 and 45 
int ReadAge(){
    int Age=1 ;

        cout << "Please enter Age between 18 and 45 ?\n";
    cin >> Age ;

     return Age ;
}

bool ValidateNumberInrange(int Number ,int From , int To){

    return (Number >= From && Number <= To );
}

int ReadUntilAgeBetween(int From , int To){

    int Age ;
    do{

        Age = ReadAge();

    }while(!ValidateNumberInrange(Age,From,To));
    return Age ;
}

void PrintResult(int Age){
cout << "Your Age is : "<< Age << endl ;
}


int main(){

    PrintResult(ReadUntilAgeBetween(18,45));


    return 0;
}