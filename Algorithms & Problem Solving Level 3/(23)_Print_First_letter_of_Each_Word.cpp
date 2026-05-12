#include <iostream>
#include <string>
using namespace std;

string ReadString(){
    string S1 ;
    cout << "Please enter Your string ?\n";
    getline(cin , S1) ;

    return S1 ;
}


void PrintUpperFirstLetterEachOfWord(string S1){
    cout << "First Letter if this string \n";
    bool isFirstLetter = true ;
    for(int i=0 ; i<S1.length() ; i++){

        if(S1[i] != ' ' && isFirstLetter){
            cout << S1[i] << endl; 

        }
        isFirstLetter = (S1[i] == ' ' ? true : false) ;
    }
}

int main()
{

    PrintUpperFirstLetterEachOfWord(ReadString());

    system("pause>0");

return 0;
}