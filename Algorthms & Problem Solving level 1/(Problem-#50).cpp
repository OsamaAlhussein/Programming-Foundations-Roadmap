#include<iostream>
using namespace std ;

// ATM PIN 3 Times

string ReadPinCode(){
    string PIN ="";

    cout << "\nPlease enter PIN code ?\n";
    cin >> PIN ;

    return PIN ;
}

bool Login(){

    string PinCode ;
    int counter=3 ;
    do{
        counter-- ;
        PinCode = ReadPinCode();
    if(PinCode == "1234")
    {
        return 1 ;
    }
    else 
    {
        cout << "\nWrong PIN , you have " << counter << " more tries\n";
        system("color 4f");
    }

    }while(counter >=1 && PinCode != "1234");
    return 0 ;
};

int main(){

     if(Login()){
        
        system("color 2f");
        cout << "\nYoue account balnce is " << 7500 << endl ;
    }
    else{
        cout << "Your card blocked call the bank for help . \n";
    };



    return 0;
}