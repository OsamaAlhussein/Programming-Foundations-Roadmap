#include <iostream>
#include <string>
#include<cctype>
using namespace std;

string ReadString(){
    string S1 ;
    cout << "Please enter Your string ?\n";
    getline(cin , S1) ;

    return S1 ;
}


string UpperFirstLetterEachOfWord(string S1){
    
    bool isFirstLetter = true ;
    for(int i=0 ; i<S1.length() ; i++){

        if(S1[i] != ' ' && isFirstLetter ){
        
            S1[i] = toupper(S1[i]) ;

        }
        isFirstLetter = (S1[i] == ' ' ? true : false) ;

        
    }
    return S1 ;
   
}

int main()
{
    string S1 = ReadString();
    cout << "\nString after conversion:\n";  
     S1 = UpperFirstLetterEachOfWord(S1);
    cout << S1 ;
    system("pause>0");

return 0;
}