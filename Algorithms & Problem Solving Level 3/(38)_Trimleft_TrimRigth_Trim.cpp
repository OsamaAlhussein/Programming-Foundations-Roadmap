#include<iostream>
using namespace std ;



string ReadString(){
    string S1 ;
    cout << "Please enter your string \n";
    getline(cin , S1);
    return S1 ;

}

string TrimLeft(string S1){

for(int i=0 ; i<S1.length(); i++){
    if(S1[i] != ' '){
            return S1.substr(i , S1.length()-i);        
        }
    }
    return "";
}

string TrimRight(string S1){

    for(int i=S1.length()-1 ; i>0 ; i--){
        if(S1[i]!=' '){
            return S1.substr(0,i+1) ;
        }
    }
    return "";
}

string Trim(string S1){
    return TrimLeft(TrimRight(S1));
}

int main(){

    string S ="    Osama Al Huseein     ";
    cout << "String    = " << S << endl ;
    cout << "Trim left = " << TrimLeft(S) << endl ;
    cout << "Trim Right= "<< TrimRight(S) << endl ;
    cout << "Trime     = " << Trim(S) ;

    system("pause>0");


    return 0 ;
}