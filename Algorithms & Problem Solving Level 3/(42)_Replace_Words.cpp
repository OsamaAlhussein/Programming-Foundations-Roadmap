#include<iostream>
#include<vector>
using namespace std ;

string ReadString(){
    string S1 ;
    cout << "Please enter your string \n";
    getline(cin,S1);
    return S1 ;
}

string ReplaceWords(string S1 , string StringToReplace , string ReplaceTo){ // MY Solution a Function
    short pos=0;
    string sWord ;
    string delime=" ";
    string S2 =  "";
    while((pos=S1.find(delime)) != std::string::npos){ 
        sWord = S1.substr(0,pos);
        if(sWord != StringToReplace){
            if(sWord!=" "){
            S2 += sWord +" ";
        }
        }
        else{
            S2 += ReplaceTo ;
        }
        

        S1.erase(0,pos+delime.length());
    }

    if(S1!=StringToReplace){
        if(S1!=" "){
            S2 += S1 +" " ;
        }
    }else{
        S2+= ReplaceTo ;
    }
    return S2 ;
}

string ReplaceWordsInStringUsingBuiltInFunction(string S1 , string StringToReplace , string ReplaceTo){
    int pos = S1.find(StringToReplace);

    while(pos != std::string::npos){
        S1.replace(pos,StringToReplace.length() , ReplaceTo);
        pos = S1.find(StringToReplace);
    }
    return S1;
}

int main(){

    string S = "\nOsama from Syria , Syria is nice Country\n";
    string StringToReplace = "Syria";
    string ReplaceTo = " USA ";
    cout << "Original String \n";
    cout << S << endl ;
    cout << "\nString after Replace\n";
    cout << ReplaceWords(S ,StringToReplace , ReplaceTo) << endl ;
    cout << ReplaceWordsInStringUsingBuiltInFunction(S , StringToReplace , ReplaceTo);

    system("pause>0");

    return 0;
}