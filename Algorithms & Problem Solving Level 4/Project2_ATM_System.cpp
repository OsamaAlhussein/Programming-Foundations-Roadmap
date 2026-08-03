#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Path to the text file storing clients database
const string ClientsFileName = "Bank2.txt";

// Forward declarations for functions
void ShowCheckBalance();
void ShowMainMenue();
void ShowNormalWithdraw();
void ShowQuikWithdraw();
void Login();

// Structure representing a single client's account details
struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

// Global variable to hold currently logged-in user session
sClient CurrentClient;

// Navigation helper: returns to main menu after action completion
void GoBackToMainMenue() {
    cout << "\nPress any key to go back to Main Menue. . . \n";
    system("pause>0");
    ShowMainMenue();
}

// Navigation helper: resets or re-displays normal withdraw screen
void GoBackToScreenNormalWithdraw() {
    cout << "\nPress any key to continue. . . \n";
    system("pause>0");
    ShowNormalWithdraw();
}

// Helper: Splits a string into substrings using a specified delimiter
vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    int pos = 0;
    string sWord = "";

    while ((pos = S1.find(Delim)) != std::string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "") {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "") {
        vString.push_back(S1);
    }
    return vString;
}

// Converts a record line from the file into an sClient struct
sClient ConvertLineToRecord(string Line, string Seperator = "#//#") {
    sClient Client;
    vector<string> vString = SplitString(Line, Seperator);
    Client.AccountNumber = vString[0];
    Client.PinCode = vString[1];
    Client.Name = vString[2];
    Client.Phone = vString[3];
    Client.AccountBalance = stod(vString[4]);

    return Client;
}

// Converts an sClient struct object into a single formatted string line for saving
string ConvertRecordToLine(sClient Client, string Seperator = "#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

// Loads all client records from the database file into a vector
vector<sClient> LoadClientDataFromFile(string FileName) {
    fstream MyFile;
    vector<sClient> vClient;
    MyFile.open(FileName, ios::in); // Read mode

    if (MyFile.is_open()) {
        string Line;
        sClient Client;

        while (getline(MyFile, Line)) {
            Client = ConvertLineToRecord(Line);
            vClient.push_back(Client);
        }
        MyFile.close();
    }
    return vClient;
}

// Helper function to read account number from user
string ReadAccountNumber() {
    string AccountNumber = "";
    cout << "Enter Account Number ? ";
    getline(cin >> ws, AccountNumber);
    return AccountNumber;
}

// Helper function to read pin code from user
string ReadPinCode() {
    string PinCode = "";
    cout << "Enter PinCode? ";
    getline(cin >> ws, PinCode);
    return PinCode;
}

// Saves updated client records back into the storage file
vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients) {
    fstream MyFile;
    MyFile.open(FileName, ios::out); // Write/Overwrite mode
    string DataLine;

    if (MyFile.is_open()) {
        for (sClient C : vClients) {
            if (C.MarkForDelete == false) {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

// Searches for a client matching credentials; assigns to client parameter if found
bool FindClientByAccountNumberAndPinCode(string AccountNumer, string PinCode, sClient& Client) {
    vector<sClient> vClient = LoadClientDataFromFile(ClientsFileName);

    for (sClient& C : vClient) {
        if (C.AccountNumber == AccountNumer && C.PinCode == PinCode) {
            Client = C;
            return true;
        }
    }
    return false;
}

// Updates account balance (deposit/withdraw) and persists updates to file
bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<sClient>& vClient) {
    char Answer = 'n';
    cout << "Are you sure want perform this transactions y/n ? ";
    cin >> Answer;

    if (Answer == 'Y' || Answer == 'y') {
        for (sClient& C : vClient) {
            if (C.AccountNumber == AccountNumber) {
                C.AccountBalance += Amount;
                cout << "Done successfully new balance is " << C.AccountBalance << endl;
                SaveCleintsDataToFile(ClientsFileName, vClient);
                return true;
            }
        }
    }
    return false;
}

// Loads client session data into global CurrentClient variable
bool LoadClientInfo(string AccountNumber, string PinCode) {
    return FindClientByAccountNumberAndPinCode(AccountNumber, PinCode, CurrentClient);
}

// Displays current account balance screen
void ShowCheckBalance() {
    system("cls");
    cout << "====================================\n";
    cout << "\tCheck Balace Screen";
    cout << "\n====================================\n";
    cout << "\n Your Balance is : " << CurrentClient.AccountBalance;
}

// Maps quick withdrawal options (1..8) to corresponding numeric amounts
short getQuikWthiDrawAmount(short QuickWithDrawOption) {
    switch (QuickWithDrawOption) {
    case 1: return 20;
    case 2: return 50;
    case 3: return 100;
    case 4: return 200;
    case 5: return 400;
    case 6: return 600;
    case 7: return 800;
    case 8: return 1000;
    default: return 0;
    }
}

// Processes quick withdrawal logic based on selected option
void PeformQuikWithdraw(short QuickWithDrawOption) {
    if (QuickWithDrawOption == 9)
        return;

    short WithDrawBalanc = getQuikWthiDrawAmount(QuickWithDrawOption);

    if (WithDrawBalanc > CurrentClient.AccountBalance) {
        cout << "\nThe amount exceeds your balance make another choise .\n";
        cout << "\nPress any key to continue. . . \n";
        system("pause>0");
        ShowQuikWithdraw();
        return;
    }

    vector<sClient> vClient = LoadClientDataFromFile(ClientsFileName);
    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, (WithDrawBalanc * -1), vClient);
    CurrentClient.AccountBalance -= WithDrawBalanc;
}

// Reads quick withdrawal menu input option
short ReadQuikWithDrawOption() {
    short n = 0;
    while (n < 1 || n > 9) {
        cout << "Choose what to withdraw from[1] to [9] ? ";
        cin >> n;
    }
    return n;
}

// Displays quick withdrawal menu screen
void ShowQuikWithdraw() {
    system("cls");
    cout << "========================================\n";
    cout << "\t\tQuik Withdraw ";
    cout << "\n========================================\n";
    cout << "\t [1] 20    \t [2] 50\n";
    cout << "\t [3] 100   \t [4] 200\n";
    cout << "\t [5] 400   \t [6] 600\n";
    cout << "\t [7] 800   \t [8] 1000\n";
    cout << "\t [9] Exit\n";
    cout << "\n========================================\n";
    cout << "\n Your Balance is : " << CurrentClient.AccountBalance << endl;

    PeformQuikWithdraw(ReadQuikWithDrawOption());
}

// Validates whether requested amount is within available account balance
void AmountExceedeYourBalance(int amount) {
    if (amount > CurrentClient.AccountBalance) {
        cout << "The amount exceede your balance , make anthor choise .";
        cout << "\nPress any key to continue. . . \n";
        system("pause>0");
        ShowNormalWithdraw();
    }
}

// Reads normal withdrawal amount ensured to be a multiple of 5
int ReadWithdrawBalance() {
    int Amount = 0;
    cout << "\nEnter an amunt multiple of 5's ? ";
    cin >> Amount;

    while (Amount % 5 != 0) {
        cout << "\nEnter an amunt multiple of 5's ? ";
        cin >> Amount;
    }

    return Amount;
}

// Performs processing logic for custom normal withdrawal
void PeformNormalWithdrawOption() {
    short WithdrawBalance = ReadWithdrawBalance();

    if (WithdrawBalance > CurrentClient.AccountBalance) {
        cout << "The amount exceede your balance , make anthor choise .";
        cout << "\nPress any key to continue. . . \n";
        system("pause>0");
        ShowNormalWithdraw();
        return ;
    }

    vector<sClient> vClient = LoadClientDataFromFile(ClientsFileName);
    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, (WithdrawBalance * -1), vClient);
    CurrentClient.AccountBalance -= WithdrawBalance;
}

// Displays normal custom withdrawal screen
void ShowNormalWithdraw() {
    system("cls");
    cout << "========================================\n";
    cout << "\t\t Normal Withdraw";
    cout << "\n========================================\n";
    PeformNormalWithdrawOption();
}

// Reads positive deposit amount input
int ReadDepositAmount() {
    int Amount = 0;
    cout << "\nEnter a postive Deposit Amount ? ";
    cin >> Amount;

    while (Amount < 0) {
        cout << "\nEnter a positive Deposit Amount ? ";
        cin >> Amount;
    }

    return Amount;
}

// Performs account deposit processing logic
void PeformDepositAmount() {
    int DepositAmount = ReadDepositAmount();
    vector<sClient> vClient = LoadClientDataFromFile(ClientsFileName);
    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, DepositAmount, vClient);
    CurrentClient.AccountBalance += DepositAmount;
}

// Displays deposit screen menu
void ShowDepositScreen() {
    system("cls");
    cout << "\n========================================\n";
    cout << "\t\t Deposit ";
    cout << "\n========================================\n";
    PeformDepositAmount();
}

// Enum mapping main menu options
enum enMainMenue {
    eQuikWithdraw = 1,
    eNormalWithdraw = 2,
    eDeposit = 3,
    eCheckBalanc = 4,
    eLogout = 5
};

// Route user action based on Main Menu choices
void PeformMianMenue(enMainMenue MainMenue) {
    switch (MainMenue) {
    case enMainMenue::eQuikWithdraw:
        ShowQuikWithdraw();
        GoBackToMainMenue();
        break;

    case enMainMenue::eNormalWithdraw:
        ShowNormalWithdraw();
        GoBackToMainMenue();
        break;

    case enMainMenue::eDeposit:
        ShowDepositScreen();
        GoBackToMainMenue();
        break;

    case enMainMenue::eCheckBalanc:
        ShowCheckBalance();
        GoBackToMainMenue();
        break;

    case enMainMenue::eLogout:
        Login();
        break;
    }
}

// Reads generic numerical menu choices
short ReadChoose() {
    short n;
    cin >> n;
    return n;
}

// Displays Main ATM Menu Screen
void ShowMainMenue() {
    system("cls");
    cout << "\n=======================================\n";
    cout << "\t\tATM System Bank";
    cout << "\n=======================================\n";
    cout << "\t[1] Quik Withraw";
    cout << "\n\t[2] Normal Withdraw";
    cout << "\n\t[3] Deposit";
    cout << "\n\t[4] Check Balanc";
    cout << "\n\t[5] Logout";
    cout << "\n=======================================\n";
    cout << "Choose what from[1] to [5]\n";
    PeformMianMenue((enMainMenue)ReadChoose());
}

// System Login Screen Handler
void Login() {
    bool LoginFaild = false;
    string AccountNumber, Password;

    do {
        system("cls");

        cout << "\n-------------------------------\n";
        cout << "\t Login Screen ";
        cout << "\n-------------------------------\n";

        if (LoginFaild) {
            cout << "Invlaid Username/Password!\n";
        }

        cout << "Enter Account Number ? ";
        getline(cin >> ws, AccountNumber);
        cout << "Enter PinCode ? ";
        getline(cin, Password);

        LoginFaild = !LoadClientInfo(AccountNumber, Password);

    } while (LoginFaild);

    ShowMainMenue();
}

// Application Entry point
int main() {
    Login();
    system("pause>0");
    return 0;
}
