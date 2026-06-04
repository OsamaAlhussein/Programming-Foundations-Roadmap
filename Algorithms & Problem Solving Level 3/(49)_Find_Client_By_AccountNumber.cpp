#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std ;


struct stClient{
    string AcountNumber;
    string PinCode;
    string Name ;
    string Phon ;
    double AcountBalance ;

};

vector <string> SliptString(string S1 , string Delime){
    int pos =0 ;
    string sWord ;
    vector <string> vString ;

    while((pos=S1.find(Delime)) != std::string::npos){
        sWord = S1.substr(0,pos);

        if(sWord!=""){
            vString.push_back(sWord);
        }
        S1.erase(0,pos+Delime.length());
    }

    if(S1!=""){
        vString.push_back(S1);
    }

    return vString ;
}


stClient ConvertLineToRecord(string Line ,string Seperator="#//#"){
    vector <string> vClient ;
    vClient = SliptString(Line,Seperator);
    stClient Client ;

    Client.AcountNumber = vClient[0];
    Client.PinCode = vClient[1];
    Client.Name = vClient[2];
    Client.Phon = vClient[3];
    Client.AcountBalance = stod(vClient[4]);

    return Client ;
}


vector <stClient> LoadClientFromFile(){
    vector <stClient> vClient ;
    fstream MyFile ;

    MyFile.open("osama.txt" , ios::in);

    if(MyFile.is_open()){
        string Line ;
        stClient Client ;

        while(getline(MyFile,Line)){
            Client = ConvertLineToRecord(Line);
            vClient.push_back(Client);
        }
         MyFile.close();
    }
   
    return vClient ;

}

bool FindClientByAccountNumber(stClient  & Cleint , string AcountNumber){

    vector <stClient> vClient = LoadClientFromFile();
    for(stClient C : vClient){
        if(AcountNumber == C.AcountNumber){
            Cleint = C;
            return true ;
        }
    }
    return false ;
}

void PrintClientCard(stClient Client){
    cout << "\nAccout Number: " << Client.AcountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phon;
    cout << "\nAccount Balance: " << Client.AcountBalance; 
}

string ReadClientAccountNumber()
{
string AccountNumber = "";
cout << "\nPlease enter AccountNumber? ";
cin >> AccountNumber;
return AccountNumber;
}

int main(){
    stClient Client;
    string AccountNumber = ReadClientAccountNumber();
    if(FindClientByAccountNumber(Client , AccountNumber)){
        PrintClientCard(Client);
    }
    else{
        cout << "\nClient with Account Number (" << AccountNumber <<") is Not Found!";
    }

    system("pause>0");

    return 0 ;
}