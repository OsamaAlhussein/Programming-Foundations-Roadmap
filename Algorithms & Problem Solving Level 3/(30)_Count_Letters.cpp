#include<iostream>
using namespace std ;


string ReadString(){
    string S1 ;
    cout << "\nPlease enter your stringn\n";
    getline(cin , S1) ;
    return S1 ;
}

char ReadCharcter(){
    char Ch ;
    cout << "\nPlease enter a Charcter ? \n";
    cin >> Ch ;
    return Ch ;
}


short CountLetter(string S1 , char Ch){
short Counter = 0;
    for(int i=0 ; i<S1.length() ; i++){

        if(S1[i]==Ch){
            Counter++;
        }
    }
    return Counter ;
}


int main(){

    string S1 = ReadString() ;
    char Ch = ReadCharcter() ;

    cout << "Lettter \'" << Ch << "\' count = " << CountLetter(S1,Ch);

    system("pause>0") ;


    return 0;
}