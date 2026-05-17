#include<iostream>
using namespace std ;





string ReadString(){
    string S1 ;
    cout << "\nPlease enter your String \n";
    getline(cin , S1);
    return S1 ;
}

bool IsVowel(char Ch){

    Ch = tolower(Ch);
    return ((Ch=='a') || (Ch=='e') || (Ch=='o') || (Ch=='u') || (Ch=='i'));
}


void PrintAllVowelInString(string S1){

    cout <<"\n Vowel in string are : " ;
    for(int i=0 ; i<S1.length() ; i++){
        if(IsVowel(S1[i])){
           cout << S1[i] << "  " ;
        }
    }

}

int main(){

    
    string S1 = ReadString();

    PrintAllVowelInString(S1) ;

    system("Pause>0");

   
    
    return 0;
}