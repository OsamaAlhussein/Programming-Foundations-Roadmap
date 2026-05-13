#include<iostream>
#include<string>
#include<cctype>
using namespace std ;


string ReadString(){
    string S1 ;
    cout << "Please enter your stringn\n";
    getline(cin , S1) ;
    return S1 ;
}


char InvertCharcter(char Ch){
    return isupper(Ch) ? tolower(Ch) : toupper(Ch) ;

}

string InvertAllLettersCase(string S1){

    for(int i=0 ; i<S1.length() ; i++){
        S1[i] = InvertCharcter(S1[i]);
    }
    return S1 ;
}


int main(){
    string S1 = ReadString();

    cout << "String After Invert All Letters case :\n";
    S1 = InvertAllLettersCase(S1);
    cout << S1 ;
    
    system("pause>0");


    return 0;
}