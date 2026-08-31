#pragma once 
#include<iostream>
#include"clsDate1.h"  //This library is found in the simple project within the OPP concept.
#include<string>
#include<iomanip>

using namespace std ;

class clsUtil{

    public :


    enum enCharTayp {SmallLetter = 1, CapitalLetter = 2 , Digit = 3 ,  MixChars=4, SpecialCharacter = 5 };


    static void Srand() 
    {
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From , int To){
        int RandomNum = rand() % (To - From +1) + From ;
        return RandomNum ;
    }

    static char GetRandomCharacter(enCharTayp CharType)
{
    if(CharType == MixChars){
        //Capital/Samll/Digits only
        CharType = (enCharTayp) RandomNumber(1,3) ;
    }
        switch (CharType)
    {
        case enCharTayp::SmallLetter:
        {
            return char(RandomNumber(97, 122)); 
            break;
        }
        case enCharTayp::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharTayp::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharTayp::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
    }
}

    static string GenerateWord(enCharTayp CharType, short Length){
        string Word;
        for (int i = 1; i <= Length; i++) 
        {
            Word += GetRandomCharacter(CharType);
        }
        return Word;
    }

    static string GenerateKey(enCharTayp CharType){
    string Key = "";
        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType , 4) + "-";
        Key = Key + GenerateWord(CharType , 4) + "-";
        Key = Key + GenerateWord(CharType , 4);
        return Key;
    }

    static void GenerateKeys(short NumberOfKeys , enCharTayp CharType)
    {   
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Kay [" << i << "] : " << GenerateKey(CharType) << endl;
        }
    }

    static void FillArrayWithRandomNumbers(int arr[100], int  arrLength , short From , short To){
        for (int i = 0 ; i < arrLength; i++){
            arr[i] = RandomNumber(From, To);
        }
    }

    static void FillArrayWithRandomWords(string arr[100] , int arrLength , enCharTayp CharType , int WordLength){

        for(int i=0 ; i<arrLength ; i++){
            arr[i] = GenerateWord(CharType ,WordLength) ;
        }
    }

    static void FillArrayWithRandomKeys(string arr[100] , int arrLength , enCharTayp CharType){
        for(int i=0 ; i<arrLength ; i++){
            arr[i] = GenerateKey(CharType) ;
        }
    }

    static void Swap(int &A , int &B){
    int Temp ;
    Temp = A ;
    A = B ;
    B = Temp ;
    }

    static void Swap(double &A , double &B){
    double Temp ;
    Temp = A ;
    A = B ;
    B = Temp ;
    }

    static void Swap(bool  &A , bool &B){
    bool Temp ;
    Temp = A ;
    A = B ;
    B = Temp ;
    }

    static void Swap(char &A , char &B){
    char Temp ;
    Temp = A ;
    A = B ;
    B = Temp ;
    }

    static void Swap(string &A , string &B){
    string Temp ;
    Temp = A ;
    A = B ;
    B = Temp ;
    }

    static void Swap(clsDate &A , clsDate &B){
    clsDate Temp ;
    Temp = A ;
    A = B ;
    B = Temp ;
    }

    static void ShuffleArray(int arr[100], int arrLength){   
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    static void ShuffleArray(string  arr[100], int arrLength){
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    static string Tabs(short NumberOfTabs){
        string Tabs = "";
        for(int i=0 ; i<NumberOfTabs ; i++){
            Tabs += "   " ;
        }

        return Tabs ;
    }

    static string EncryptText(string Text, short EncryptionKey){

    for (int i = 0; i < Text.length(); i++)
    { 
        Text[i] = char((int) Text[i] + EncryptionKey);
    }
    return Text; 
    }

    static string DecryptionText(string Text, short EncryptionKey){
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text; 
    }

};

