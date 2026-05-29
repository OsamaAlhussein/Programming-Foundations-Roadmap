#include<iostream>
#include<vector>
using namespace std ;



string JoinString(vector <string> & vString , string dilem){
    string S1 ;
    for(string & S : vString){
        S1 += S + dilem ;
    }
     
    return S1.substr(0,S1.length() - dilem.length()) ;
}


int main(){
    vector <string> vString = {"Osama","Sami","Rahma"};

    cout << "\nVector after Join \n";
    cout << JoinString(vString,",");

    system("pause>0");

    return 0;
}