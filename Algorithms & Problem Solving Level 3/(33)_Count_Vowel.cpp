#include<iostream>
using namespace std ;

/*This program counts the number of vowel letters in the text and 
lastly prints the total number of vowel letters. This is my solution.
*/



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


short CountVowel(string S1){

    short Count =0 ;
    for(int i=0 ; i<S1.length() ; i++){
        if(IsVowel(S1[i])){
            Count++ ;
        }
    }
    return Count ;
}

int main(){

    
    string S1 = ReadString();

    cout << "\n Number Of Vowel is : " << CountVowel(S1) << endl ;

    system("Pause>0");

   
    
    return 0;
}