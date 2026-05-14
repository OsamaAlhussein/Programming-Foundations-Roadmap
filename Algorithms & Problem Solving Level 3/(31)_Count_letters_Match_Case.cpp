#include<iostream>
#include<string>
#include<cctype>
using namespace std ;


string ReadString(){
    string S1 ;
    cout << "\nPlease enter your string ?\n";
    getline(cin , S1);
    return S1 ;
}


char ReadCharcter()
{
    char Ch ;
    cout << "\nPlease enter a Charcter\n";
    cin >> Ch;
    return Ch ;
}
char InvertCharcter(char Ch){
    return isupper(Ch) ? islower(Ch) : isupper(Ch);
}

short CounterLetter(string S1 , char Ch ,bool MatchCase=true){

short Count =0 ;

    for(int i=0 ; i<S1.length() ; i++){
        
        if(MatchCase)
        {
            if(S1[i]==Ch){
                Count++;
            }
            else 
            {
                if(tolower(S1[i])==tolower(Ch)){
                    Count++ ;
                }
            }
        }
    }

    return Count ;
}


int main(){

    string S1 = ReadString();

    char Ch1 = ReadCharcter();

    cout << "\nLetter \'" << Ch1 << "\' Count = " << CounterLetter(S1,Ch1) ;

    cout << "\nLetter \'" << Ch1 << "\' Or \'"<< InvertCharcter(Ch1) << "\' Count = "
    <<  CounterLetter(S1,Ch1,false)  ;

    system("pause>0");


    return 0;
}