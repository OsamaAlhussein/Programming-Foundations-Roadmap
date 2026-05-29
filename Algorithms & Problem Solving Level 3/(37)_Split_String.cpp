#include<iostream>
#include <vector>
using namespace std; 


string ReadString(){
    string S1 ;
    cout << "Please enter your string \n";
    getline(cin , S1) ;
    return S1;
}

vector <string> SplitString(string S1 , string delim ){
   
    vector <string > vString ;
    short pos ;
    string sWord ; // define a string variable

    // use find() function to get the position of the delimiters
    while((pos = S1.find(delim)) != std::string::npos){

        sWord = S1.substr(0,pos); // stor the word 

        if(sWord != ""){
           
            vString.push_back(sWord);
        }

        S1.erase(0,pos+delim.length()); /* erase() until
positon and move to next word. */
    }

    if(S1!=""){
        vString.push_back(S1);
    }
    return vString ;

}


int main(){
    vector <string> vStirng ;

    string S1 = ReadString();
    vStirng = SplitString(S1," ") ;
    cout << "Token : " << vStirng.size() << endl ;
    for(string & S : vStirng){
        cout << S << endl ;
    }
    system("pause>0");



    return 0 ;
}