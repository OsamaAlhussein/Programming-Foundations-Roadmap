#include<iostream>
#include<vector>
using namespace std ;

string ReadString(){
    string S1 ;
    cout << "Please enter your string \n";
    getline(cin,S1);
    return S1 ;
}

string LowerAllString(string S1){

    for(int i=0 ; i<S1.length() ; i++){
        S1[i] = tolower(S1[i]);
    }
    return S1 ;
}

vector <string> SplitString(string S1 , string delime){
    short pos =0;
    string sWord ; 
    vector <string> vString ;
    while((pos=S1.find(delime)) != std::string::npos){
         sWord = S1.substr(0,pos);
         if(sWord != " "){
            vString.push_back(sWord); 
         }

         S1.erase(0,pos+delime.length());
    }
    if(S1 != " "){
        vString.push_back(S1);
    }
    return vString ;
}

string JoinString(vector <string> & vString , string delime){
    string S1 ;
    for(string & S : vString){
        S1 += S + delime ;
    }
    return S1.substr(0,S1.length() - delime.length());
}

string ReplaceWordInStringUsingSplit(string S1 , string StringToReplace , string ReplaceTo , bool MachCase=true){

    vector <string> vString ;
    vString = SplitString(S1 , " ");

    for(string & S : vString){

        if(MachCase){
            if(S == StringToReplace){
                S = ReplaceTo ;
            }
        }
        else{
            if(LowerAllString(S)==LowerAllString(StringToReplace)){
                S = ReplaceTo ;
            }
        }
    }

    return JoinString(vString , " ");
}


int main(){

    string S = "\nOsama from Syria , Syria is nice Country\n";
    string StringToReplace = "syria";
    string ReplaceTo = " USA ";
    cout << "Original String\n";
    cout << S << endl ;

    cout << "\nReplace with match case :\n" ;
    cout << ReplaceWordInStringUsingSplit(S,StringToReplace,ReplaceTo) << endl;

    cout << "Replace with not match case :\n";
    cout << ReplaceWordInStringUsingSplit(S,StringToReplace,ReplaceTo,false);
    

    system("pause>0");

    return 0;
}