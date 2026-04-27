#include<iostream>
#include<string>
using namespace std ;

string Readname()
{
    string name ;

    cout << "Pleas enter name ?"<< endl;
    getline(cin , name);
    return name ; 
}


string EncrdText(string Text, short EncrptionKey)

{

    for(int i=0 ; i<=Text.length() ;i++ )
    {
    Text[i] = char((int)Text[i] + EncrptionKey);
    }
    return Text ;
}


string DecryptText(string Text , short EncrptionKey )
{

    for (int i=0 ; i<=Text.length() ; i++)
    {
        Text[i] = char((int)Text[i] - EncrptionKey);
    }
    return Text ;
}

int main(){

   const short  Encrptionkey = 2 ;
    
    string Text = Readname() ;
    string TextAfterEncrption = EncrdText(Text,Encrptionkey);
    string TextAfterDecrytion = DecryptText(TextAfterEncrption,Encrptionkey);

    cout << "Text Before Encryption : " << Text << endl ;
    cout << "Text After Encryption : " << TextAfterEncrption << endl ;
    cout << "Text After Decryption  : " << TextAfterDecrytion ;



    return 0 ; 
}