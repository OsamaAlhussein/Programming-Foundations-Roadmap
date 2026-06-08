#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std ;

string FilName = "Bank1.txt";

struct stClient{
    string AccountNumber ;
    string PinGode ;
    string Name ;
    string Phon ;
    double AccountBalance ;
    bool MarkForDelete = false ;
};

vector <string> SliptString(string S1 , string Delime){
    int pos = 0;
    string sWord ;
    vector <string> vString ;

    while((pos=S1.find(Delime)) != std::string::npos){
        sWord = S1.substr(0,pos) ;
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

string ConvertRecordToLine(stClient Client , string Seperator="#//#"){
    string S ="";

    S += Client.AccountNumber + Seperator ;
    S += Client.PinGode + Seperator ;
    S += Client.Name + Seperator ;
    S += Client.Phon + Seperator ;
    S += to_string(Client.AccountBalance) ;

    return S ;

}

stClient ConvertLineToRecord(string Line ,string Seperator="#//#"){
    stClient Client ;
    vector <string> vString = SliptString(Line , Seperator) ;
    Client.AccountNumber = vString[0];
    Client.PinGode = vString[1] ;
    Client.Name = vString[2];
    Client.Phon = vString[3];
    Client.AccountBalance = stod(vString[4]);

    return Client ;
}
    
vector <stClient> LoadClientDataForFile(string FileName){
    vector <stClient> vClient ;
    fstream MyFile ;
    MyFile.open(FileName , ios::in);

    if(MyFile.is_open()){

        string Line ;
        stClient Client ;
        while(getline(MyFile,Line)){

        Client = ConvertLineToRecord(Line) ;
        vClient.push_back(Client);

        }
        MyFile.close();
    }
    return vClient ;
}

//  Show All Clients #1 

void PrintClientRecord(stClient Client){

    cout << "|" << left << setw(15) << Client.AccountNumber ;
    cout << "|" << left << setw(15) << Client.PinGode ;
    cout << "|" << left << setw(40) << Client.Name ;
    cout << "|" << left << setw(12) << Client.Phon ;
    cout << "|" << left << setw(12) << Client.AccountBalance ;

}

void PrintAllCkientData(vector <stClient> vClient){

    cout << "\n\t\t\t\t Client List (" << vClient.size() << ") CLient(s). \n";
    cout << "\n------------------------------------------------------------";
    cout << "------------------------------------\n";
    cout << "|" << left << setw(15) << " Account Number " ;
    cout << "|" << left << setw(15) << " Pin Code " ;
    cout << "|" << left << setw(40) << " Name " ;
    cout << "|" << left << setw(12) << " Phon " ;
    cout << "|" << left << setw(12) << " Account Balance " ;
    cout << "\n\n------------------------------------------------------------";
    cout << "------------------------------------\n";

    for(stClient & C : vClient){
        PrintClientRecord(C) ;
        cout << endl ;
    }

    cout << "\n---------------------------------------------------------";
    cout << "-----------------------------------------";

}

void Main1(){
    system("cls");
    cout << "\n-----------------------------\n";
    cout << "     Show Client List Screen    ";
    cout << "\n-----------------------------\n\n";
    vector <stClient> vClient = LoadClientDataForFile(FilName);
    PrintAllCkientData(vClient);
}

// Add Clients  #2 

bool CheckAccountNumber(string AccountNumber){
    vector <stClient> vCleint = LoadClientDataForFile(FilName);

        for(stClient & C : vCleint){

            if(C.AccountNumber == AccountNumber){

                cout << "Client with [" << AccountNumber << "] already exisis , Enter another Account Number ? ";
                return true ;
            }
        }
        
    return false ;

}

stClient ReadClintData(){
    stClient Client ;
    do{
        cout << "Enter Account Number ? ";
        getline(cin >> ws , Client.AccountNumber);

    }while(CheckAccountNumber(Client.AccountNumber));



    cout << "Enter Pin Code ? ";
    getline(cin,Client.PinGode) ;
    cout << "Enter Name ? ";
    getline(cin,Client.Name);
    cout << "Enter Phon ? ";
    getline(cin,Client.Phon) ;
    cout << "Enter Account Balance ? ";
    cin >> Client.AccountBalance ;

    return Client ;
}

void AddDataLineToFile(string FileName , string ClientRecord){
    fstream MyFile ;
    MyFile.open(FileName , ios::out | ios::app);

    if(MyFile.is_open()){
        MyFile << ClientRecord << endl ;
        MyFile.close();
    }
}

void AddNewClient(string FileName){
    stClient Client = ReadClintData() ;
    string Line = ConvertRecordToLine(Client) ;
    AddDataLineToFile(FileName , Line) ;
}

void AddClients(string FileName){
    char AddMore = 'Y' ;

    do{
        system("cls");
        cout << "\n-----------------------------\n";
        cout << "      Add New Client Screen     ";
        cout << "\n-----------------------------\n\n";
        AddNewClient(FileName) ;

        cout << "Client added Successfully , Do you want to add More Clients ? Y/N ? ";
        cin >> AddMore ;

    }while(toupper(AddMore) == 'Y') ; 
}

void Main2(){


    AddClients(FilName);

}

// Delet CLient #3 ;
 
string ReadAccountNumber(){
    string  AccountNumber ;
    cout << "PLease enter Account Number ? ";
    getline(cin >> ws,AccountNumber);
    return AccountNumber ;
}

bool FindClientAccountNumber(vector <stClient> & vClient , stClient & Client , string AccountNumber){
     
    for(stClient & C : vClient){
        if(C.AccountNumber == AccountNumber){
            Client = C ;
            return true ;
        }
    }
    return false ;
}

bool MarkForDelete(vector <stClient> & vClient , string AccountNumber){
    
    for(stClient & C : vClient){
        if(C.AccountNumber == AccountNumber){
            C.MarkForDelete = true ;
            return true ;
        }
    }
    return false ;
}

vector <stClient> SaveClientsToFil(vector <stClient> vClient , string FileName){
    fstream MyFile ;
    MyFile.open(FileName , ios::out) ;
    string DataLine ;

    if(MyFile.is_open()){
        
            for(stClient C : vClient){

                if(C.MarkForDelete == false){
                    DataLine = ConvertRecordToLine(C);
                    MyFile << DataLine << endl ;
                }
                
            }
            MyFile.close();
    }
    return vClient ;
}

void PrintClientCard(stClient Client){
    cout << "\nThe Following are the client details : ";
    cout << "\n-------------------------------------------------";
    cout << "\nAccount Number   : " << Client.AccountNumber ;
    cout << "\nPin Code       : " << Client.PinGode ;
    cout << "\nName           : " << Client.Name ;
    cout << "\nPhon           : " << Client.Phon ;
    cout << "\nAccountBalance : " << Client.AccountBalance ;
    cout << "\n-------------------------------------------------" << endl ;

}

bool UpladeClientByAccountNumber( vector <stClient> & vClient , string AccountNumber){
    char Answer = 'n' ;
    stClient Client;
    if(FindClientAccountNumber(vClient , Client , AccountNumber)){

        PrintClientCard(Client);

        cout <<"\n\n Do you sure want delet this client ? y/n ";
        cin >> Answer ;

        if(Answer == 'Y' || Answer =='y'){

            MarkForDelete(vClient ,AccountNumber) ;
            SaveClientsToFil(vClient , FilName);

            vClient = LoadClientDataForFile(FilName);
            cout << "\n\nClient Delet Successfully .";
            return true ;
        }

    }else{
        
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }


}

void Main3(){
    system("cls");
    cout << "\n-----------------------------\n";
    cout << "      Delete Client Screen      ";
    cout << "\n-----------------------------\n\n";
    vector <stClient> vClient = LoadClientDataForFile(FilName) ;
    string AccountNumber = ReadAccountNumber() ;
    UpladeClientByAccountNumber(vClient,AccountNumber) ;

}

// Update Client Info #4

stClient ChangeClientRecord(string AccountNumber){
    stClient Client ;
    Client.AccountNumber =  AccountNumber ;

    cout << "Enter Pin Code ? ";
    getline(cin >> ws , Client.PinGode);
    cout << "Enter Name ? ";
    getline(cin , Client.Name);
    cout << "Enter Phon ? " ;
    getline(cin , Client.Phon);
    cout << "Enter Account Balance ? ";
    cin >> Client.AccountBalance ;

    return Client ;
}

bool UpdateClientInfo(vector <stClient> & vClient  , string AccountNumber){
    char Answer = 'n';
    stClient Client ;

    if(FindClientAccountNumber(vClient , Client , AccountNumber)){

        PrintClientCard(Client);

        cout << "Do you sure want update this client Y/N ? ";
        cin >> Answer ;

        if(Answer == 'Y' || Answer == 'y'){
            for(stClient & C : vClient){
                if(C.AccountNumber == AccountNumber){
                    
                    C = ChangeClientRecord(AccountNumber) ;  
                    break;
                }
            }
            SaveClientsToFil(vClient , FilName) ;

            cout << "\n\nClient Delet Successfully .";
            return true ;
        }

    }else
    {
            cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
            return false;

    } 
}

void Main4(){
    system("cls");
    cout << "\n-----------------------------\n";
    cout << "      Update Client Screen      ";
    cout << "\n-----------------------------\n\n";
    vector <stClient> vClient = LoadClientDataForFile(FilName);
    string AccountNumber = ReadAccountNumber();
    UpdateClientInfo(vClient,AccountNumber);

}

// Find Client #5 

bool FindClient(){
    vector <stClient> vClient = LoadClientDataForFile(FilName);
    string AccountNumber = ReadAccountNumber();
    stClient Client ;
    if(FindClientAccountNumber(vClient , Client , AccountNumber)){
        PrintClientCard(Client);
        return true ;
    } 
    else {
        cout << "\nClient with Account Number (" << AccountNumber <<") is Not Found!";
        return false ;
    }
}

void Main5(){
    system("cls");
    cout << "\n-----------------------------\n";
    cout << "       Find Client Screen       "; 
    cout << "\n-----------------------------\n\n";
    FindClient() ;
}

void Main6(){
    system("cls");
    cout << "\n-----------------------------\n";
    cout << "        Program Ends : -)        ";
    cout << "\n-----------------------------\n";

    system("pause>0");

    
}



void MainMenueScreen(){
    cout << "\n=======================================\n";
    cout << "             Main Menue Screen             ";
    cout << "\n=======================================\n";
    cout << "\n[1] : Show Client List. ";
    cout << "\n[2] : Add New Client.   ";
    cout << "\n[3] : Delete Client.    ";
    cout << "\n[4] : Updat Client Info.";
    cout << "\n[5] : Find CLient.      ";
    cout << "\n=======================================\n";
}


void ChooseUser(short Num){

    if(Num == 1){
        Main1() ;
        
    }
    else if(Num == 2 ){
        Main2();
        
    }
    else if (Num == 3){
        Main3() ;
        
    }
    else if(Num == 4){
        Main4();
        
    }
    else if(Num == 5){
        Main5();
        
    }else{

        Main6();
    }
}

int main(){

    short Num=0 ;

    while(true){

        do{
        MainMenueScreen();

        cout << "Choose what do you want to do ? [1 to 6] ? ";
        cin >> Num ;
    }while(6 < Num || Num < 0);

    ChooseUser(Num) ;
    cout << "\npress any key to go back to Main Menue. . . ";
    system("pause>0");
    system("cls");
        
    }


    
    
    



    

    return 0;
}