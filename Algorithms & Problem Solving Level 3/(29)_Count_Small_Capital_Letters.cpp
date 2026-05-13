#include<iostream>
using namespace std ;

string ReadString(){
    string S1 ;
    cout << "Please enter your stringn\n";
    getline(cin , S1) ;
    return S1 ;
}

enum enWhatToCount{SmallLetter=0 , CapitallLetter=1 , All=2};

short Count = 0;

short CountLetters(string S1 , enWhatToCount WhatToCount=enWhatToCount::All)
{
    if(WhatToCount==enWhatToCount::All){

        return S1.length();
    }

    for(short i =0 ; i< S1.length(); i++){

        if(WhatToCount==enWhatToCount::CapitallLetter && isupper(S1[i])){
            Count++ ;
        }


        if(WhatToCount==enWhatToCount::SmallLetter && islower(S1[i]))
        {
            Count++ ;
        }
    }

    return Count ;

    
}

int CountSmallLetters(string S1){
int Count=0;
    for(int i=0 ; i<S1.length() ; i++){
        if(islower(S1[i])){
            Count++ ;
        }
    }
    return Count ;
}

int CountCapitalLetters(string S1){
    int Count=0 ;
    for(int i=0 ; i<S1.length();i++){
        if(isupper(S1[i])){
            Count++;
        }
    }
    return Count;
}


int main(){

    string S1 = ReadString();

    cout << "String Length = " << S1.length() << endl ;
    cout << "Capital Letters Count = " <<  CountCapitalLetters(S1) << endl ;
    cout << "Small Letters Count = "<< CountSmallLetters(S1) ;


    cout << "\n\nMethod 2\n";
cout << "\nString Length = " << CountLetters(S1);
cout << "\nCapital Letters Count= " << CountLetters(S1,enWhatToCount::CapitallLetter);
cout << "\nSmall Letters Count= " << CountLetters(S1,enWhatToCount::SmallLetter );


    system("pause>0");


    return 0;
}