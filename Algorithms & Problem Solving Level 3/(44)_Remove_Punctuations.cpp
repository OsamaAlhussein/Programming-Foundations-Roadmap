#include<iostream>
#include<string>
using namespace std ;


string RemovePunctuations(string S1){
    string S2 ;
    for(int i=0 ; i<S1.length() ; i++){
        if(!ispunct(S1[i])){
            S2 += S1[i] ;
        }
    }
    return S2 ;
}


int main(){
    string S = "welcome to Syria , Syria is a nice country ; it's amazing . ";

    cout << "Original String : \n";
    cout << S << endl ;

    cout << "\n\nPauncuations Removed:\n" <<
    RemovePunctuations(S) ;
    system("pause>0");


    return 0;
}