#include<iostream>
using namespace std ;


struct stInfo{

    string FirstName ;
    string LastName ;

};

stInfo ReadInfo(){

    stInfo Info ;

    cout << "Pleas enter your First Name ?\n";
    cin >> Info.FirstName ;

    cout << "Pleas enter your Last Name ?\n";
    cin >> Info.LastName ;

    return Info ;
}


string GetFullName(stInfo Info){

    string FullName = Info.FirstName +" "+ Info.LastName ;
    return FullName ;
}
    

void PrintFullName(string FullName){

    cout << "Your full Name is : " << FullName << endl ;

}


int main(){

    PrintFullName(GetFullName(ReadInfo()));


    return 0;
}