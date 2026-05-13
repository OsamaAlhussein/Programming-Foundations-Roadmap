#include<iostream>
#include<cctype>
#include<string>
using namespace std ;


char ReadChar()
{
    char c ;
    cout << "Please enter a Charcter ?\n";
    cin >> c ;
    return c ;

}

char InvertCharcter(char C){
    return isupper(C) ? tolower(C) : toupper(C) ;
}




int main(){

    char C = ReadChar();

    cout << "Char after inverting case \n";
     C = InvertCharcter(C);
    cout << C ;
    system("pause>0");

    return 0;
}