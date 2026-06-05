#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std ;

struct stClient{
    string AccountNumber ;
    string PinCode ;
    string Name ;
    string Phon ;
    double AccountBalance ;
    bool MarkForDelet = false ;
};


vector <string> SliptString(string S1 , string Delime){
    vector <string> vString ;
    int pos =0 ;
    string sWord ;

    while((pos=S1.find(Delime)) != std::string::npos){
        sWord = S1.substr(0,pos);
        if(sWord != ""){
            vString.push_back(sWord);
        }
        S1.erase(0,pos + Delime.length());
    }
    if(S1 != ""){
        vString.push_back(S1);
    }
    return vString ;
}

stClient ConvertClientToRecord(string Line , string Seperator="#//#"){
    vector <string> vString = SliptString(Line,Seperator);
    stClient Client ;

    Client.AccountNumber = vString[0];
    Client.PinCode = vString[1];
    Client.Name = vString[2];
    Client.Phon = vString[3];
    Client.AccountBalance =stod(vString[4]);

    return Client ;
}


string ConvertClientToLine(stClient Client, string Seperator="#//#"){
    string stClientRecord ="";
    stClientRecord += Client.AccountNumber + Seperator ;
    stClientRecord += Client.PinCode + Seperator ;
    stClientRecord += Client.Name + Seperator ;
    stClientRecord += Client.Phon + Seperator ;
    stClientRecord += Client.AccountBalance ;
    
    return stClientRecord ;
}

vector <stClient> LoadClientDataFromFile(){

    fstream MyFile ;
    vector <stClient> vClient ;
    MyFile.open("osama.txt" , ios::in);

    if(MyFile.is_open()){
        string Line ;
        stClient Client  ;

        while(getline(MyFile,Line)){
            
            Client = ConvertClientToRecord(Line);
            vClient.push_back(Client);

        }
        MyFile.close();
    }

    return vClient ;

}


void PrintClientCard(stClient Client){
    cout << "\nAccout Number: " << Client.AccountBalance;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phon;
    cout << "\nAccount Balance: " << Client.AccountBalance; 
}

string ReadClientAccountNumber()
{
string AccountNumber = "";
cout << "\nPlease enter AccountNumber? ";
cin >> AccountNumber;
return AccountNumber;
}


bool FindClientByAcountNumber( vector <stClient> & vClient , string AccountNumber , stClient & Client){
    

    for(stClient & C : vClient){
        if(C.AccountNumber == AccountNumber){
            Client = C ;
        return true ;        }
    }

    return false ;
}

bool MarkCLientForDeletByAccountNumber(string AccountNumber , vector <stClient> & vClient){

    for(stClient & C : vClient){
        if(C.AccountNumber == AccountNumber){

            C.MarkForDelet = true ;
            return true ;
        }
    }
    return false ;
}


vector <stClient> SaveClientDataToFile(vector <stClient> vCleint){
    fstream MyFile ;
    MyFile.open("osama.txt" , ios::out);
    string DataLine ;

    if(MyFile.is_open()){

        for(stClient C : vCleint){

            if(C.MarkForDelet == false){
                DataLine = ConvertClientToLine(C) ;
                MyFile << DataLine << endl ; 
            }
        }
        MyFile.close();
    }
    return vCleint ;
}


bool UpladeClientByAccountNumber( vector <stClient> & vCLient , string AccountNumber){
   
  stClient Client ;
  char Answer = 'n';

  if(FindClientByAcountNumber(vCLient , AccountNumber , Client)){
    PrintClientCard(Client) ;

    cout <<"\n\n Do you sure want delet this client ? y/n ";
    cin >> Answer ;

    if(Answer == 'y' || Answer == 'Y'){
        MarkCLientForDeletByAccountNumber(AccountNumber , vCLient);
        SaveClientDataToFile(vCLient);

        vCLient = LoadClientDataFromFile();

        cout << "\n\nClient Delet Successfully .";
        return true ;

    }
  }else{

        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }

}

int main(){

    vector <stClient> vClient = LoadClientDataFromFile();
    string AccountNumber = ReadClientAccountNumber(); 

    UpladeClientByAccountNumber(vClient , AccountNumber) ;



   system("pause>0");


    return 0 ;
}