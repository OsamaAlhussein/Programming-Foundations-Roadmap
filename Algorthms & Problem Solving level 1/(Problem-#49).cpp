#include<iostream>
using namespace std ;
// ATM PIN

/*Write a program to read th ATM PIN code from the user , then check if PIN code =1234 
, then show the balance to user otherwise print "Wrong PIN " and ask the user to enter the 
PIN again assume user balance is 7500*/

string ReadPinCode(){
    string PIN ="";

    cout << "Please enter PIN code ?\n";
    cin >> PIN ;

    return PIN ;
}

bool Login(){

    string PinCode ;
    do{
        PinCode = ReadPinCode();
    if(PinCode == "1234")
    {
        return 1 ;
    }
    else 
    {
        cout << "\nWrong PIN\n";
        system("color 4f");
    }

    }while(PinCode!="1234");
}
int main(){

    if(Login()){
        
        system("color 2f");
        cout << "\nYoue account balnce is " << 7500 << endl ;
    };


    return 0;
}