#include<iostream>
using namespace std ;


string ReadString(){
    string S1 ;
    cout << "\nPlease enter your String \n";
    getline(cin , S1);
    return S1 ;
}

void PrintEcahWordInString(string S1){

   string delim = " " ; // Delimiter 

   cout << "\nYour string wrords are : \n";
   short pos = 0 ;
   string sWord ; // define a string variable 

   // use find() function to get the position of the delimiters 
   while((pos = S1.find(delim)) != std::string::npos){
    sWord = S1.substr(0,pos) ; //store the word 
    if(sWord!="")
    {
        cout << sWord << pos << endl ;
        
    }

    S1.erase(0 , pos + delim.length()) ; // erase() until position and ,ove to next word . 
   }

   if(S1 != ""){
    cout << S1 << endl ; // it print last word of the string 
   }

}



int main(){

    string S1= ReadString();

    PrintEcahWordInString(S1); 

    system("pause>0");


    return 0;
}