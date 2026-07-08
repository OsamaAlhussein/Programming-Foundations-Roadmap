#include<iostream>
#include<vector>
using namespace std ;

//Write a program to :
//Read Date String .
// Convert it to date structure
// Peint Day , Month , Year separately 
// Then cinvert Date structure to string and 
// print it on the screen.
//Note : Write the following functions :
// StrringToDate
// DateToString 

struct sDate{
    short Day ;
    short Month ;
    short Year ;
};

vector <string> SliptString(string S , string Delime){
    vector <string> vString ;
    int pos =0;
    string sWord ;

    while((pos=S.find(Delime)) != std::string::npos){

        sWord = S.substr(0,pos);
        if(sWord!=""){
            vString.push_back(sWord);
        }
        S.erase(0,pos+Delime.length());
    }

    if(S!=""){
        vString.push_back(S);
    }
    return vString ;
}

sDate StringToDateStruct(string S){
    sDate Date ;
    vector <string> vDate;

    vDate = SliptString(S,"/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date ;
}

string DateToString(sDate Date){

    return to_string(Date.Day)+ "/" + to_string(Date.Month) +"/"+ to_string(Date.Year);
}

string ReadDateString(){
    string S ;
    cout << "Plesae enter Date dd/mm/yyyy ? ";
    getline(cin >>ws , S);
    return S ;
}






int main(){

    string DateString = ReadDateString();

    sDate Date = StringToDateStruct(DateString);

    cout << "\nDay:" << Date.Day << endl;
    cout << "Month:" << Date.Month << endl;
    cout << "Year:" << Date.Year << endl;

    cout << "\nYou Entered: " << DateToString(Date) << "\n" ;

    system("pause>0");
    return 0;
}