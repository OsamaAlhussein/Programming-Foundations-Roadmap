#include<iostream>
#include<cctype>
#include<string>
using namespace std ;


string ReadString(){
    string S1 ;
    cout << "Please enter Your string ?\n";
    getline(cin , S1) ;

    return S1 ;
}


string AllLettersAreUpperCase(string S1){

    for(int i=0 ; i<S1.length() ; i++){

        S1[i] = toupper(S1[i]);
    }
    return S1 ;
}

string AllLettersAreLowerCase(string S1){
    for(int i=0 ;i<S1.length() ; i++){

        S1[i] = tolower(S1[i]);
    }

    return S1 ;
}



int main(){

    string S1 = ReadString();

    cout << "\nString After Upper : \n";
    S1 = AllLettersAreUpperCase(S1) ;
    cout << S1 << endl ;

    cout << "\nString After Lower : \n";
    S1 = AllLettersAreLowerCase(S1);
    cout << S1 ;

system("pause>0");


    return 0;
}