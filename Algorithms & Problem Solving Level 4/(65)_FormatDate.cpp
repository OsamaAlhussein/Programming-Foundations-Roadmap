#include<iostream>
#include<vector>
using namespace std ;

//Write a program to read Date and write a 
// Function to format that date .

struct sDate{
    short Day ;
    short Month ;
    short Year ;
};

vector <string> SliptString(string S1 , string Delime){
    vector <string> vString;
    int pos =0;
    string sWord ;// define a string variable

    // use find() function to get the position of the delimiters

    while((pos=S1.find(Delime)) != std::string::npos){
        sWord = S1.substr(0,pos); // stor the word 

        if(sWord!=""){
            vString.push_back(sWord);
        }
        S1.erase(0,pos + Delime.length());
    }

    if(S1!=""){
        vString.push_back(S1);
    }
    return vString ;
}

string ReplaceWordInString(string S1 , string StringToReplace , string ReplaceTo){

    short pos = S1.find(StringToReplace);
     
    while(pos!=std::string::npos){
        S1 = S1.replace(pos ,StringToReplace.length() , ReplaceTo);
        pos = S1.find(StringToReplace);//find next 

    }
    return S1;
}

string DateToString(sDate Date)
{
return to_string(Date.Day) + "/" + to_string(Date.Month) +
"/" + to_string(Date.Year);
}

sDate StringToDate(string S1){
    sDate Date ;
    vector <string> vString = SliptString(S1 , "/") ;
    
    Date.Day = stoi(vString[0]);
    Date.Month = stoi(vString[1]);
    Date.Year = stoi(vString[2]);
    return Date ;
}



string FormateDate(sDate Date , string DateFormat="dd/mm/yyyy"){

    string FormattedDateString = "" ;
    FormattedDateString = ReplaceWordInString(DateFormat , "dd" , to_string(Date.Day)) ;
    FormattedDateString = ReplaceWordInString(FormattedDateString , "mm" ,to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString , "yyyy" , to_string(Date.Year));

    return FormattedDateString ;
    
}

string ReadDateString(){
    string S ;
    cout << "Plesae enter Date dd/mm/yyyy ? ";
    getline(cin >>ws , S);
    return S ;
}

int main(){
    string DateString = ReadDateString();

    sDate Date = StringToDate(DateString) ;

cout << "\n" << FormateDate(Date) << "\n";
cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n";
cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";
cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";
cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";
cout << "\n" << FormateDate(Date, "Day:dd, Month:mm,Year:yyyy") << "\n";


    return 0;
}