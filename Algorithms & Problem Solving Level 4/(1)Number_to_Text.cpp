#include<iostream>
using namespace std ;

//Write a program to read a number and print the text of that number 


string NumbertoText(int Number){

    if(Number == 0){
        return "";
    }

    if(Number >=1 && Number <= 19){
        string arr[] = {"" , "One" ,"Tow" , "Three" , "Four" , "Five" , "Sex" ,"Seven" , "Eight"
        , "Nine" , "Ten" , "Eleven" , "Twelve" , "Thirteen" , "Fourteen" , 
    "Fivteen" , "Sixteen" ,"Seventeen", "Eighteen" , "Nineteen"};

    return arr[Number] + " ";
    }

    if(Number >=20 && Number <=99){
        string arr[] = {"" , "" , " Twenty " , " Thirty " , " Forty " , " Fifty " , 
        " Sixty " , " Seventy " , " Eighty " , " Niety "};

        return arr[Number / 10] + " " + NumbertoText(Number % 10);
    }

    if(Number >= 100 && Number <= 199){

        return " One Hundred " + NumbertoText(Number % 100) ;
    }

    if(Number >=200 && Number<= 999){
        return NumbertoText(Number / 100) + "Hundreds " + NumbertoText(Number % 100);
    }

    if(Number >= 1000 && Number<=1999){
        return " One Thousand " + NumbertoText(Number % 1000) ;
    }

    if(Number >= 2000 && Number<=999999){
        return NumbertoText(Number / 1000) + "Thousand " + NumbertoText(Number % 1000) ;
    }

    if(Number >= 1000000 && Number <= 1999999){
        return " One Million " + NumbertoText(Number % 1000000) ;
    }

    if(Number >= 2000000 && Number <= 999999999){
        return NumbertoText(Number / 1000000) + "Millions " + NumbertoText(Number % 1000000);
    }

    if(Number >= 1000000000 && Number <= 1999999999){
        return " One Billion " + NumbertoText(Number % 1000000000) ;
    }
    else{
        return NumbertoText(Number / 1000000000) + "Billions " +  NumbertoText(Number % 1000000000); 
    }

  
}




int ReadNumber(){
    int Number ;
    cout << "Enter a number ? ";
    cin>> Number ;
    return Number ;
}

int main(){

    int Number = ReadNumber();
    cout << NumbertoText(Number);

    system("pause>0");

    return 0;
}
