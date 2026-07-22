
/*This project builds upon the "Algorithms and Problem Solving – Level 3" course project. 
Bank user functionalities requiring a username and password have been added, 
where entering the correct credentials grants access to the main interface.
Here is my solution.*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
const string ClientsFileName = "Bank2.txt";
const string UsersFileName = "Users10.txt" ;
void ShowMainMenue();
void TransactiosMenueScreen();
void GoBackToMainUsers();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

struct stUsers{
    string UserName ;
    string Pasword ;
    short Perissions =-1;
    bool MarkForDelet = false ;
};

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }   
        S1.erase(0, pos + Delim.length()); /* erase() until
    positon and move to next word. */
    }
        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }
        return vString;
}

sClient ConvertLinetoRecord(string Line, string Seperator ="#//#")
{
    sClient Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double
    return Client;
}
string ConvertRecordToLine(sClient Client, string Seperator ="#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{
    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode
    if (MyFile.is_open())
        {
        string Line;
        sClient Client;
        while (getline(MyFile, Line))
        {
        Client = ConvertLinetoRecord(Line);
         if (Client.AccountNumber == AccountNumber)
        {
            return true;
        }
     vClients.push_back(Client);
    }
    MyFile.close();
    }
    return false;
}

sClient ReadNewClient()
{
    sClient Client;
    cout << "Enter Account Number? ";
    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, Client.AccountNumber);
    while (ClientExistsByAccountNumber(Client.AccountNumber,ClientsFileName))
    {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }
        cout << "Enter PinCode? ";
        getline(cin, Client.PinCode);
        cout << "Enter Name? ";
        getline(cin, Client.Name);
        cout << "Enter Phone? ";
        getline(cin, Client.Phone);
        cout << "Enter AccountBalance? ";
        cin >> Client.AccountBalance;
    return Client;
}

vector <sClient> LoadCleintsDataFromFile(string FileName)
{
    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode
    if (MyFile.is_open())
    {
        string Line;
        sClient Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
}
    return vClients;
}
void PrintClientRecordLine(sClient Client)
{
cout << "| " << setw(15) << left << Client.AccountNumber;
cout << "| " << setw(10) << left << Client.PinCode;
cout << "| " << setw(40) << left << Client.Name;
cout << "| " << setw(12) << left << Client.Phone;
cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowAllClientsScreen()
{
    vector <sClient> vClients =
    LoadCleintsDataFromFile(ClientsFileName);
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout <<
    "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout <<
    "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    if (vClients.size() == 0)
    cout << "\t\t\t\tNo Clients Available In the System!";
    else
        for (sClient Client : vClients)
        {
    PrintClientRecordLine(Client);
    cout << endl;
    }
    cout <<
    "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

void PrintClientCard(sClient Client)
{
cout << "\nThe following are the client details:\n";
cout << "-----------------------------------";
cout << "\nAccout Number: " << Client.AccountNumber;
cout << "\nPin Code : " << Client.PinCode;
cout << "\nName : " << Client.Name;
cout << "\nPhone : " << Client.Phone;
cout << "\nAccount Balance: " << Client.AccountBalance;
cout << "\n-----------------------------------\n";
}
bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
return false;
}
sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;
    Client.AccountNumber = AccountNumber;
    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    return Client;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
    for (sClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}
vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite
    string DataLine;
        if (MyFile.is_open())
        {
            for (sClient C : vClients)
            {
                if (C.MarkForDelete == false)
                {
                //we only write records that are not marked for delete.
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
                }
            }
                MyFile.close();
        }   
            return vClients;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;
       
    }
     MyFile.close();
}
void AddNewClient()
{
    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName,
    ConvertRecordToLine(Client));
}

void AddNewClients()
{
    char AddMore = 'Y';
    do
    {
    //system("cls");
    cout << "Adding New Client:\n\n";
    AddNewClient();
    cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
    cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveCleintsDataToFile(ClientsFileName, vClients);
            //Refresh Clients
            vClients = LoadCleintsDataFromFile(ClientsFileName);
            cout << "\n\nClient Deleted Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber
        << ") is Not Found!";
        return false;
    }
    return false ;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            for (sClient& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }
            SaveCleintsDataToFile(ClientsFileName, vClients);
            cout << "\n\nClient Updated Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber
        << ") is Not Found!";
        return false;
}
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}


void ShowDeleteClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------\n";
    vector <sClient> vClients =
    LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);
}
void ShowUpdateClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Info Screen";
    cout << "\n-----------------------------------\n";
    vector <sClient> vClients =
    LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);
}
void ShowAddNewClientsScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-----------------------------------\n";
    AddNewClients();
}

void ShowFindClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------\n";
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    sClient Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, vClients,Client))
    PrintClientCard(Client);
    else
    cout << "\nClient with Account Number[" << AccountNumber
    << "] is not found!";
}
void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-----------------------------------\n";
}
enum enMainMenueOptions
{
eListClients = 1, eAddNewClient = 2,
eDeleteClient = 3, eUpdateClient = 4,
eFindClient = 5, eTransactions = 6 
 ,eMangeUsers = 7 , eLogout=8 
};



void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
        system("pause>0");
    ShowMainMenue();
}
short ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 8]? ";
    short Choice = 0;
    cin >> Choice;
    return Choice;
}



void GoBackToMainTransactions(){
    
    cout << "\n\nPress any key to go back Transaction Menue...";
    system("pause>0");
    TransactiosMenueScreen();
}
short ReadMainTransactions()
{
cout << "Choose what do you want to do? [1 to 4]? ";
short Choice = 0;
cin >> Choice;
return Choice;
}



bool DepositBalanceToClientByAccountNumber(string AccountNumber , double Amount , vector <sClient> & vClient){
    char Answer = 'n';  
    cout << "Are you sure want perform this transactions y/n ? ";
    cin >> Answer ;

    if(Answer == 'Y' || Answer == 'y'){

        for(sClient &C : vClient){
            if(C.AccountNumber == AccountNumber){
                C.AccountBalance += Amount ;
                cout << "Done successfully new balance is " << C.AccountBalance<< endl ;
                SaveCleintsDataToFile(ClientsFileName,vClient);
                return true ;


            }
            
               
            
        }
    }
     return  false;
    
}
void ShowDepositScreen(){
    system("cls");
    cout << "\n-----------------------------\n";
    cout << "\tDeposit Screen  ";
    cout << "\n-----------------------------\n";
    vector <sClient>  vClient  = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    sClient Client ;
    while(! FindClientByAccountNumber(AccountNumber,vClient,Client)){
        cout << "\nClinet with ["<< AccountNumber << "] dose not exist ";
        AccountNumber = ReadClientAccountNumber();
    }
    PrintClientCard(Client);

    double Amount = 0;
    cout << "Plese enter deposit amount ? ";
    cin >> Amount ;

    DepositBalanceToClientByAccountNumber(AccountNumber,Amount,vClient);
    
    
  
}

double Readwihtdraw(){

    double with =0;
    cout << "Plese enter withdraw amount ? ";
    cin >> with ;
    return with ;
}


bool WithDrawAnswer(char ans , double with , vector <sClient> & vClient , string AccountNumber){
        if(toupper(ans) == 'Y'){
        
        for(sClient & C : vClient){
            if(C.AccountNumber == AccountNumber){
                if(C.AccountBalance >= with){
                    C.AccountBalance = C.AccountBalance - with ;
                    cout << "Done successfully new balance is " << C.AccountBalance<< endl ;
                     SaveCleintsDataToFile(ClientsFileName,vClient);
                    return true ;
                }else{
                    cout << "Can't change account balance \n";
                    
                    return false ;
                }
            }
        }
    }
    else{
            GoBackToMainTransactions();
            return false ; 
    }

}



void ShowWithDraw(){
    system("cls");
    cout << "\n-----------------------------\n";
    cout << "\tWithDraw Screen";
    cout << "\n-----------------------------\n";
    vector <sClient> vClient = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    sClient Client ;
    while(! FindClientByAccountNumber(AccountNumber,vClient,Client)){
        cout << "\nClinet with ["<< AccountNumber << "] dose not exist ";
        AccountNumber = ReadClientAccountNumber();
    }
    PrintClientCard(Client);

    double Amount = 0;
    cout << "Plese enter deposit amount ? ";
    cin >> Amount ;

    //Validate that the amount does not exceeds the balance
    while(Amount > Client.AccountBalance){
        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
        cout << "Please enter another amount? ";
        cin >> Amount;
    }
    
    DepositBalanceToClientByAccountNumber(AccountNumber,(Amount * -1),vClient);

}


void PrintClientRecord(sClient Client){

    cout << "|" << left << setw(15) << Client.AccountNumber ;
    cout << "|" << left << setw(40) << Client.Name ;
    cout << "|" << left << setw(12) << Client.AccountBalance ;

}
void PrintAllCkientData(vector <sClient> vClient){

    cout << "\n\t\t\t\t Client List (" << vClient.size() << ") CLient(s). \n";
    cout << "\n------------------------------------------------------------";
    cout << "------------------------------------\n";
    cout << "|" << left << setw(15) << " Account Number " ;
    cout << "|" << left << setw(40) << " Name " ;
    cout << "|" << left << setw(12) << " Account Balance " ;
    cout << "\n\n------------------------------------------------------------";
    cout << "------------------------------------\n";
    double ans =0 ;
    for(sClient & C : vClient){
        PrintClientRecord(C) ;
        cout << endl ;
        ans += C.AccountBalance ;
    }

    cout << "\n---------------------------------------------------------";
    cout << "-----------------------------------------\n";

    cout << "\n\t\t\t Total Balances = " << ans << endl ;

}
    

void ShowTotalBalances(){
    system("cls");
    vector <sClient> vClient = LoadCleintsDataFromFile(ClientsFileName);
    PrintAllCkientData(vClient);
}


enum enMainTransactions{Deposit=1 , Withraw=2 , TotalBalance=3 , MainMenue=4};

void PerFormTransactionsMenueOption(enMainTransactions MainTransactions)
{
    switch(MainTransactions){

        case enMainTransactions::Deposit :
        {
            system("cls");
            ShowDepositScreen();
            GoBackToMainTransactions();
            break;
        }

        case enMainTransactions::Withraw:
        {
            system("cls");
            ShowWithDraw();
            GoBackToMainTransactions();
            break;
        }

        case enMainTransactions::TotalBalance:
        {
            system("cls");
            ShowTotalBalances();
            GoBackToMainTransactions();
            
            break;
        }

        case enMainTransactions::MainMenue:
        {
            GoBackToMainMenue();
            break; 
        }
    }
}


void TransactiosMenueScreen(){
    system("cls");
    cout << "\n=======================================\n";
    cout << "\tTransactions Menue Screen                ";
    cout << "\n=======================================";
    cout << "\n\t [1] Deposit.";
    cout << "\n\t [2] Withdraw.";
    cout << "\n\t [3] Total Balance.";
    cout << "\n\t [4] Main Menue.";
    cout << "\n=======================================\n";
    PerFormTransactionsMenueOption((enMainTransactions) ReadMainTransactions());
}


//=====================================================================
//                      Extenion 2 (REQYUIREMENTS)
//=====================================================================

stUsers ConvertLineToRecord_User(string Line, string Seperator ="#//#"){
    stUsers U ;
    vector <string> vUsers;
    vUsers  = SplitString(Line,Seperator);
     U.UserName = vUsers[0];
    U.Pasword = vUsers[1];
    U.Perissions = stoi(vUsers[2]);

  return U ;
}

string ConvertRecordToLine_User(stUsers User , string Seperator ="#//#"){
    string stUserRecord = "";
    stUserRecord += User.UserName + Seperator; 
    stUserRecord += User.Pasword + Seperator;
    stUserRecord += to_string(User.Perissions) ;

    return stUserRecord ;
}

vector <stUsers> LoadUsersDataFromFile(string UsersFileName){
    fstream Myfile ;
    vector <stUsers> vUsers ;

    Myfile.open(UsersFileName , ios::in);

    if(Myfile.is_open()){
        string Line ;
        stUsers User ;
        while(getline(Myfile,Line)){

            User = ConvertLineToRecord_User(Line);
            vUsers.push_back(User);            
        }
        Myfile.close();
    }
    return vUsers ;
}






bool FindUserByUsernameByAndPassword(string UserName , string Password , vector <stUsers> Currently){
    
    for(stUsers U : Currently){
        if(U.UserName == UserName && U.Pasword==Password){
            return true ;
        }
    }
    return false ;
}

bool FindUserByUserName(vector <stUsers> vUser , string UserName , stUsers &User){

    for(stUsers U : vUser){
        if(U.UserName == UserName){
            User = U ;
            return true ;
        }
    }
    return false ;
}

enum enMainMenueUsers{
    eListUsers=1 , eAddNewUser=2 , eDeleteUser=3 ,
    eUpdateUser=4 , eFindUser=5 , eMainMenue=6 
};

short ReadMainMenueUser(){
    short Choose ;
    cout << "Choose what do you want to do ? [1 to 6] ? ";
    cin >> Choose ; 
    return Choose ;
}

//------------------------------------------------
//              ShowAllUsersScreen 
//------------------------------------------------
void PrintUserRecordLine(stUsers User){
    cout << "| " << left << setw(15) << User.UserName  ;
    cout << "| " << left << setw(10) << User.Pasword  ;
    cout << "| " << left << setw(40) << User.Perissions  ;
}


void ShowAllUsersScreen(){
    system("cls");
    vector <stUsers> vUsers = LoadUsersDataFromFile(UsersFileName) ;
    cout << "\n\t\t\t\t\tUser List (" << vUsers.size() << ") User(s).";
    cout <<
    "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
        if (vUsers.size() == 0)
    cout << "\t\t\t\tNo Clients Available In the System!";
    else
        for (stUsers &User : vUsers)
        {
    PrintUserRecordLine(User);
    cout << endl;
    }
    cout <<
    "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    
    
}


//-------------------------
//      addnew user
//-------------------------



bool UserExistsByUserName(string UserName, string FileName)
{
    vector <stUsers> vUsers ;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode
    if (MyFile.is_open())
        {
        string Line;
        stUsers User;
        while (getline(MyFile, Line))
        {
        User = ConvertLineToRecord_User(Line);
         if (User.UserName == UserName)
        {
            return true;
        }
     vUsers.push_back(User);
    }
    MyFile.close();
    }
    return false;
}


stUsers ReadInfoUser(){
    stUsers User ;

    cout << "Enter UserName ? ";
    getline(cin >> ws , User.UserName) ; 
    cout << "Enter Password ? ";
    getline(cin , User.Pasword);
    User.Perissions = -1 ;

    return User ;
}



void AddNewUser(){
    stUsers User = ReadInfoUser();
     AddDataLineToFile(UsersFileName,ConvertRecordToLine_User(User));
}

void ShowAddNewUserScreen(){

    system("cls");
    cout << "\n-----------------------------\n";
    cout << "\tAdd New User Screen";
    cout << "\n-----------------------------\n";
    char AddMore = 'Y';
    do
    {
    cout << "\nAdding New User:\n\n";
    AddNewUser();
    cout << "\nUser Added Successfully, do you want to add more user? Y/N? ";
    cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}


//--------------------
//      delete user
//--------------------

bool MarkUserForDeleteByUserName(string UserName , vector <stUsers> & vUser){
    
    for(stUsers & U : vUser){
        if(U.UserName == UserName){
            U.MarkForDelet = true ;
            return true ;
        }
    }
    return false ;

}


vector <stUsers> SaveUserDateToFile(string UsersFileName , vector <stUsers>  vUser){
    fstream MyFile ;
    MyFile.open(UsersFileName , ios::out);

    string DeleteLine ;
    
    if(MyFile.is_open()){

        for(stUsers U : vUser){

            if(U.MarkForDelet == false){
                DeleteLine = ConvertRecordToLine_User(U) ;
                MyFile << DeleteLine << endl ;
            }
        }
        MyFile.close();
    }
    return vUser ;
}

void PrintUserCard(stUsers User){
    cout << "\n--------------------------------------\n";
    cout << "User Name : " << User.UserName << endl ;
    cout << "Passowrd  : " << User.Pasword << endl ;
    cout << "Permissions :" << User.Perissions ;
    cout << "\n--------------------------------------\n";

}

bool DeletUserByUserName( string UserName , vector <stUsers> & vUser){
    stUsers User ;
    
    char Answer = 'n';
    if (FindUserByUserName(vUser,UserName,User))
    {
        PrintUserCard(User);
        cout << "\n\nAre you sure you want delete this user? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkUserForDeleteByUserName(UserName , vUser);
            SaveUserDateToFile(UsersFileName,vUser);
            //Refresh User
            vUser = LoadUsersDataFromFile(UsersFileName);
            cout << "\n\nUser Deleted Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nUser with User Name (" << UserName
        << ") is Not Found!";
        return false;
    }
    return false ;
} 




string ReadUserName(){
    string UserName ;
    cout << "Enter User Name ? ";
    getline(cin >> ws , UserName);
    return UserName ;
}

void ShowDeleteUserScreen(){
        system("cls");
    cout << "\n-----------------------------\n";
    cout << "\tDelete User Screen";
    cout << "\n-----------------------------\n";
    vector <stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);
    string UserName = ReadUserName(); 
    DeletUserByUserName(UserName,vUsers);


}


//-------------------
//      Update
//-------------------
stUsers ChangeUser(string UserName){
    stUsers User ;
    User.UserName = UserName ;
    cout << "Enter Password ? ";
    getline(cin  >> ws , User.Pasword);
    return User ;
}

bool UpdateByUserName( string UserName , vector <stUsers> & vUser){
    stUsers User ;
    
    char Answer = 'n';
    if (FindUserByUserName(vUser,UserName,User))
    {
        PrintUserCard(User);
        cout << "\n\nAre you sure you want update this User? y/n ? ";
        cin >> Answer;
        if(Answer == 'Y' || Answer=='y'){
            for(stUsers &U : vUser){
                if(U.UserName == UserName){

                U = ChangeUser(UserName);
                break;
                
                }

            }
                SaveUserDateToFile(UserName,vUser); 
                cout << "\n\nUser Updated Successfully.";
                 
                return true ;

        }   
    }
    else {
        cout << "\nUser with User Name (" << UserName
        << ") is Not Found!";
        return false ;
    }
    return false;
} 


void ShowUpdatUserScreen(){
    system("cls");
    cout << "\n-----------------------------\n";
    cout << "\tUpdat User Screen";
    cout << "\n-----------------------------\n";
    vector <stUsers> vUsers = LoadUsersDataFromFile(UsersFileName); 
    string UserName = ReadUserName();
    UpdateByUserName(UserName,vUsers);
}

//-----------------------
//          Find user
//-----------------------
void ShowFindUserScreen(){

    system("cls");
    cout << "\n-----------------------------\n";
    cout << "\tFind User Screen";
    cout << "\n-----------------------------\n";
    stUsers User ;
    vector <stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);
    string UserName = ReadUserName();
    if(FindUserByUserName(vUsers,UserName,User)){
        PrintUserCard(User);
    }
    else{
    cout << "\nUser with User Name[" << UserName
    << "] is not found!";
    }
}

void PeFormMainMenueUsers(enMainMenueUsers MainMenueUsers){

    switch(MainMenueUsers){

        case enMainMenueUsers::eListUsers:
        {
            system("cls");
            ShowAllUsersScreen();
            GoBackToMainUsers();
            break;
        }
        case enMainMenueUsers::eAddNewUser:
        {
            system("cls");
            ShowAddNewUserScreen();
            GoBackToMainUsers();
            break;
        }
        case enMainMenueUsers::eDeleteUser:
        {
            system("cls");
            ShowDeleteUserScreen();
            GoBackToMainUsers();
            break;
        }
        case enMainMenueUsers::eUpdateUser:
        {
            system("cls");
            ShowUpdatUserScreen();
            GoBackToMainUsers();
            break;
        }
        case enMainMenueUsers::eFindUser:
        {
            system("cls");
            ShowFindUserScreen();
            GoBackToMainUsers();
            break;
        }
        case enMainMenueUsers::eMainMenue:
        {
            GoBackToMainMenue();
            break;
        }
    }
}

void ShowMangeUsersMenueScreen(){
    system("cls");
    cout << "\n=======================================\n";
    cout << "\tMange Users Menue Screen                   ";
    cout << "\n=======================================";
    cout << "\n\t [1] List Users.";
    cout << "\n\t [2] Add New User.";
    cout << "\n\t [3] Delete User.";
    cout << "\n\t [4] Updat User.";
    cout << "\n\t [5] Find User ." ;
    cout << "\n\t [6] Main Menue." ;
    cout << "\n=======================================\n";
    PeFormMainMenueUsers((enMainMenueUsers )ReadMainMenueUser());
}

void GoBackToMainUsers(){
    cout << "\n\nPress any key to go back to Main Users...";
    system("pause>0");
    ShowMangeUsersMenueScreen();

}






void ShowLogin(){
    cout << "\n-----------------------------------\n";
    cout << "\t\tLogin Screen ";
    cout << "\n-----------------------------------\n";

    stUsers Users = ReadInfoUser();
    vector <stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);

    while(!FindUserByUsernameByAndPassword(Users.UserName,Users.Pasword,vUsers)){
        cout << "\n\nInvlaid Username/Password!\n";
        Users = ReadInfoUser();
    }
    ShowMainMenue();

    system("pause>0");


}

//=================================================================================

void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
switch (MainMenueOption)
{
case enMainMenueOptions::eListClients:
    {
    system("cls");
    ShowAllClientsScreen();
    GoBackToMainMenue();
    break;
    }

    case enMainMenueOptions::eAddNewClient:
    {
    system("cls");
    ShowAddNewClientsScreen();
    GoBackToMainMenue();
    break;
    }

case enMainMenueOptions::eDeleteClient:
    {
    system("cls");
    ShowDeleteClientScreen();
    GoBackToMainMenue();
    break;
    }
case enMainMenueOptions::eUpdateClient:
    {
    system("cls");
    ShowUpdateClientScreen();
    GoBackToMainMenue();
    break;
    }
case enMainMenueOptions::eFindClient:
    {
    system("cls");
    ShowFindClientScreen();
    GoBackToMainMenue();
    break;
    }
case enMainMenueOptions::eTransactions :
{
    system("cls");
    TransactiosMenueScreen();
    break;
}
case enMainMenueOptions::eMangeUsers:
    {
    system("cls");
    ShowMangeUsersMenueScreen();
    break;
    }

case enMainMenueOptions::eLogout:
    {
        system("cls");
        ShowLogin();
        break;
    }    
}
}

void ShowMainMenue()
{
system("cls");
cout << "===========================================\n";
cout << "\t\tMain Menue Screen\n";
cout << "===========================================\n";
cout << "\t[1] Show Client List.\n";
cout << "\t[2] Add New Client.\n";
cout << "\t[3] Delete Client.\n";
cout << "\t[4] Update Client Info.\n";
cout << "\t[5] Find Client.\n";
cout << "\t[6] Transactions.\n";
cout << "\t[7] Mange Users.\n";
cout << "\t[8] Logout.\n";
cout << "===========================================\n";
PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}







int main()
{
ShowLogin();
system("pause>0");

return 0;
}
