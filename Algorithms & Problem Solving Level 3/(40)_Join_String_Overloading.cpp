#include<iostream>
#include<vector>
using namespace std ;


string JoinString(vector <string> & vSring , string delim){
    string S1 ="";
    for(string & S : vSring){
        S1 = S1 + S + delim ;
    }
    return S1.substr(0,S1.length() - delim.length());
}

string JoinString( string arrStirng[] , short length , string delim){
    string S1 ="";
    for(int i=0 ; i<length ; i++){
        S1 = S1 + arrStirng[i] + delim ;
    }
    return S1.substr(0,S1.length() - delim.length());
}


int main(){
    vector <string> vString = {"Osama","Sami","Rahma"};
    string arrstirng[] = {"Osama","Sami","Rahma"};; 
    cout << "\nVector after Join \n";
    cout << JoinString(vString,",");

    cout << "\n\nArray after Join \n";
    cout << JoinString(arrstirng,3,",");

    system("pause>0");

    return 0;
}