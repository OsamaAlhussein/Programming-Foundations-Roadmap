#include<iostream>
#include<vector>
using namespace std ;


string ReadString(){
    string S1 ;
    cout << "Please enter a your string ?\n";
    getline(cin,S1);
    return S1;
}


vector <string> SlipString(string S1 , string Delime){
    short pos = 0 ;
    string sWord ;
    vector <string> vString ;

    while((pos=S1.find(Delime)) != std::string::npos){
        sWord = S1.substr(0,pos) ;

        if(sWord!=" "){
            vString.push_back(sWord);
        }

        S1.erase(0,pos+Delime.length());

        
    }
    if(S1!=" "){
        vString.push_back(S1);
    }
    return vString ;
    
};


string ReverseWord(string S1){
    vector <string> vString ;
    string S2 ;

    vString = SlipString(S1 , " ");

    // Declare iterator 
    vector <string>::iterator iter = vString.end();

    while(iter != vString.begin()){
        --iter ;
        S2 += *iter + " ";

    }
    S2 = S2.substr(0,S2.length()-1) ;
    return S2 ;
}


int main(){
    string S1 = ReadString();
    cout << "\n\n String after reversing words \n";
    cout << ReverseWord(S1);
    system("pause>0");
    return 0;
}