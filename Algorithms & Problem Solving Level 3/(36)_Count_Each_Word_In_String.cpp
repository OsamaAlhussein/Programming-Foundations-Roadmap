#include<iostream>
using namespace std ;



string ReadString(){
    string S1 ;
    cout << "\nPlease enter your String \n";
    getline(cin , S1);
    return S1 ;
}

short CountWords(string S1){

    short Count = 0 , Pos = 0; 
    string delim = " " ; // delimiter
    string  sWord ;  // define a string variable 

    // use find() function to get the postion of the delomoters 

    while((Pos = S1.find(delim)) != std::string::npos){

        sWord = S1.substr(0 , Pos) ; // stor the word
        if(S1 != ""){
            Count++ ;
        }
        S1.erase(0 , Pos + delim.length());

    }

    if(S1 != "")
    Count++;
    return Count ;
    
}


int main(){

    string S1 = ReadString();
    cout << "The number of words in your string is : " << CountWords(S1) ;

    system("pause>0");


    return 0 ;
}