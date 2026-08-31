#include<iostream>
#include "clsUtility.h"
using namespace std ;

int main(){

    clsUtil::Srand() ;
    cout << clsUtil::RandomNumber(1,10) << endl ;
    cout << clsUtil::GetRandomCharacter(clsUtil::MixChars) << endl ;
    cout << clsUtil::GenerateWord(clsUtil::MixChars,8) << endl ;
    cout << clsUtil::GenerateKey(clsUtil::MixChars) << endl ;
    clsUtil::GenerateKeys(10,clsUtil::MixChars)  ;


    cout << "\n";

    int x = 10 , y=20 ;
    cout << x <<  " " << y << endl ;
    clsUtil::Swap(x,y) ;
    cout << x <<  " " << y << endl ;
    

    double a1 = 10.7 , a2 =20.6 ;
    cout << a1 <<  " " << a2 << endl ;
    clsUtil::Swap(a1,a2);
    cout << a1 <<  " " << a2 << endl ;


    clsDate D1(6,10,2025) , D2(29,8,2026);
    cout << D1.DateToString() << "    " << D2.DateToString() << endl ;
    clsUtil::Swap(D1,D2) ;
    cout << D1.DateToString() << "    " << D2.DateToString() << endl ;


    string s1="Osama" , s2="Al-Hosen";
    cout << s1 <<  " " << s2 << endl ;
    clsUtil::Swap(s1,s2);
    cout << s1 <<  " " << s2 << endl ; 

    int Arr1[5] = {1,2,3,4,5};
    clsUtil::ShuffleArray(Arr1,5) ;
    cout << "\nArray 1 after shuffle : \n";
    for(int i=0 ; i<5 ; i++){
        cout << Arr1[i] << endl ;
    }

    string  Arr2[5] = {"Osama" , "Sami" , "Saleh" , "Yasser" , "Ethar"};
    clsUtil::ShuffleArray(Arr2,5) ;
    cout << "\nArray 2 after shuffle : \n";
    for(int i=0 ;i<5 ; i++){
        cout << Arr2[i] << endl ;
    }


    int Arr3[5] ;
    clsUtil::FillArrayWithRandomNumbers(Arr3, 5 , 20 , 50);
        cout << "\nArray 3 after fill : \n";
    for(int i=0;i<5 ; i++){
        cout << Arr3[i] << endl ;
    }


    string Arr4[5] ;
    clsUtil::FillArrayWithRandomWords(Arr4 , 5 ,clsUtil::MixChars , 8 );
        cout << "\nArray 4 after fill : \n";
        for(int i=0 ; i<5;i++){
            cout << Arr4[i] << endl ;
        }


    string Arr5[5] ;
    clsUtil::FillArrayWithRandomKeys(Arr5,5,clsUtil::MixChars);
        cout << "\nArray 5 after filling Keys  : \n";
        for(int i=0 ; i<5 ;i++){
            cout << Arr5[i] << endl ;
        }

    cout << "Text1" << clsUtil::Tabs(5) << "Text2" ;


    const short Encryptionkey = 2 ;

    string TextAfterEncryption , TextAfterDecryption ;
    string Text = "Osama Al-Hosuein" ;
    TextAfterEncryption = clsUtil::EncryptText(Text,Encryptionkey);
    TextAfterDecryption = clsUtil::DecryptionText(TextAfterEncryption,Encryptionkey);


    cout << "\nText Befor Encryption : ";
    cout << Text <<endl ;
    cout << "\nText After Encryption : ";
    cout << TextAfterEncryption << endl ;
    cout << "\nText After Decrytion : ";
    cout << TextAfterDecryption << endl;






    return 0;
}
