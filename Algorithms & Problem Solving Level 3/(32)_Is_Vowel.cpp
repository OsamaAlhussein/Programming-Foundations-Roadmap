#include<iostream>
using namespace std ;

/*This program checks whether the letters are phonetic or not
and this is my solution*/

char ReadCharcter(){
    char Ch ;
    cout << "\nPlease enter a charcter ?\n";
    cin >> Ch ;

    return Ch ;
}

bool IsVowel(char Ch){

    Ch = tolower(Ch);
    return ((Ch=='a') || (Ch=='e') || (Ch=='o') || (Ch=='u') || (Ch=='i'));
}

int main(){

    while(true){
        char Ch = ReadCharcter();

    if(IsVowel(Ch)){
        cout << "\nYES Letter " << Ch << " is vowel\n";
    }
    else {
        cout << "\nNO Letter " << Ch <<" is Not vowel\n";
    }

    }
    
    return 0;
}