#pragma once 
#include<bits/stdc++.h>
#include"clsPerson.h"
#include"clsStirng.h"
#include"clsDate1.h"
#include"Global.h"
using namespace std ;

class clsBankClient : public clsPerson{
    
    public:
    struct stTrnsferLogRecord;

    private :




    enum enMode{EmptyMode =0 , UpdateMode=1 , AddNewMode=2};
    enMode _Mode ;
    string _AccountNumber ;
    string _PinCode ;
    float _AccountBalance ;
    bool _MarkForDelete = false  ;






    static clsBankClient _ConvertLineToClientObject(string Line , string Seperator="#//#"){
        vector <string> vClientData ;
        vClientData = clsString::Split(Line,Seperator) ;

        return clsBankClient(enMode::UpdateMode , vClientData[0] , vClientData[1] , vClientData[2] , vClientData[3] , vClientData[4] ,
        vClientData[5] , stof(vClientData[6]) );
    }

    static string _ConvertClientObjectToLine(clsBankClient Client , string Sepertor="#//#"){
        string S1 ;
        S1 += Client.getFirstName() + Sepertor ; 
        S1 += Client.getLastName() + Sepertor ; 
        S1 += Client.getEmail() + Sepertor ; 
        S1 += Client.getPhone() + Sepertor ; 
        S1 += Client.AccountNumber() + Sepertor ; 
        S1 += Client.getPinCode() + Sepertor ;
        S1 += to_string(Client.getAccountBalance())  ; 

        return S1 ;
    }

    static vector <clsBankClient> _LoadClientDataFromFile(){
        fstream MyFile ;
        vector <clsBankClient> vClient ;
        MyFile.open("Clients.txt" , ios::in) ;

        if(MyFile.is_open()){

            string Line ;
            while(getline(MyFile,Line)){

                clsBankClient Client = _ConvertLineToClientObject(Line) ;
                vClient.push_back(Client);

            }
            MyFile.close();
        }
        return vClient ;
    }

    static void _SaveClientDataToFile(vector <clsBankClient> vClient){
        fstream MyFile ;
        MyFile.open("Clients.txt" , ios::out) ; //over write
        string DataLine ;
        if(MyFile.is_open()){
            for(clsBankClient & C : vClient){
                if(C._MarkForDelete == false)
                {
                    DataLine = _ConvertClientObjectToLine(C) ;
                    MyFile << DataLine << endl;
                }
 
            }
            MyFile.close() ;

        }
    }

    void _Update(){

        vector <clsBankClient> _vClient ;
        _vClient = _LoadClientDataFromFile() ;

        for(clsBankClient & C : _vClient){
            if(C.AccountNumber() == AccountNumber()){
                C = *this ;
                break; 
            }
        }
        _SaveClientDataToFile(_vClient);
    }

    void _AddNew(){
        return _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    string _PerpaerTransferLogRecord(float Amount , clsBankClient DestinationClient ,string UserName , string Separetor="#//#")
    {
        string TransferLogRecord ;
        TransferLogRecord += clsDate::GetSystemDateTimeString() + Separetor;
        TransferLogRecord += AccountNumber() + Separetor ;
        TransferLogRecord += DestinationClient.AccountNumber() + Separetor;
        TransferLogRecord += to_string(Amount) + Separetor ;
        TransferLogRecord += to_string(getAccountBalance()) + Separetor;
        TransferLogRecord += to_string(DestinationClient.getAccountBalance()) + Separetor ;
        TransferLogRecord += UserName ;

        return TransferLogRecord ;

    }



    void _RegisterTransferLog(float Amount , clsBankClient DestinationClient , string UserName)
    {

        fstream MyFile ;
        MyFile.open("TransferLog.txt" , ios::out | ios::app);

        string DataLine = _PerpaerTransferLogRecord(Amount,DestinationClient,UserName);

        if(MyFile.is_open())
        {
            MyFile << DataLine << endl ;
            MyFile.close();
        }
        
    }

    static clsBankClient _GetEmptyClientObject(){
        return clsBankClient(enMode::EmptyMode ,"","","","","","",0);
    }


    
    

    static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
    {
        stTrnsferLogRecord TrnsferLogRecord;

        vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
        TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
        TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
        TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
        TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
        TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
        TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
        TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

        return TrnsferLogRecord;

    }
    
    

    public:


    struct stTrnsferLogRecord{
        string DateTime ;
        string SourceAccountNumber;  
        string DestinationAccountNumber;
        int Amount ;
        float srcBalanceAfter ;
        float destBalanceAfter ;
        string UserName ;

    };


    clsBankClient(enMode Mode , string FirstName , string LastName , string Email 
     , string Phone , string AccountNumber , string PinCode , float AccountBalanc) 
     : clsPerson(FirstName , LastName , Email , Phone){

        _Mode = Mode ;
        _AccountNumber = AccountNumber ;
        _PinCode = PinCode ;
        _AccountBalance = AccountBalanc ;

     }

     bool IsEmpty(){
        return (_Mode == enMode::EmptyMode) ;
     }


     string AccountNumber(){
        return _AccountNumber ;
     }

    void setPinCode(string PinCode){
        _PinCode = PinCode ;
    } 
    string getPinCode(){
        return _PinCode;
    }
    
    void setAccountBalance(float AccountBalance){
        _AccountBalance = AccountBalance ;
    }

    float getAccountBalance(){
        return _AccountBalance ;
    }

    /*
        No Ui Related code isid object.
    void Print(){
        cout << "\nClient Card\n" ;
        cout << "\n-------------------------------\n";
        cout << "\nFirst Name   : " << getFirstName() ;
        cout << "\nLast Name    : " << getLastName() ;
        cout << "\nFull Name    : " << FullName() ;
        cout << "\nEmail        : " << getEmail() ;
        cout << "\nPhon         : " << getPhone() ;
        cout << "\nAcc. Number  : " << _AccountNumber ;
        cout << "\nPassword     : " << _PinCode ;
        cout << "\nBalance      : " << _AccountBalance ;
        cout << "\n-------------------------------\n";
    }*/


    static clsBankClient Find(string AccountNumber){

        vector <clsBankClient> vClient ;

        fstream MyFile ;
        MyFile.open("Clients.txt" , ios::in) ;// read mode 

        if(MyFile.is_open()){
            string Line ;
            while(getline(MyFile,Line)){
                clsBankClient Client  = _ConvertLineToClientObject(Line) ;
                if(Client.AccountNumber() == AccountNumber){
                    MyFile.close();
                    return Client ;
                }
                vClient.push_back(Client);
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber , string PinCode){
        
        vector <clsBankClient> vClient ;
        fstream MyFile ;
        MyFile.open("Clients.txt" , ios::in) ;// read mode 

        if(MyFile.is_open()){
            string Line ;
            while(getline(MyFile,Line)){
                clsBankClient Client  = _ConvertLineToClientObject(Line) ;
                if(Client.AccountNumber() == AccountNumber && Client.getPinCode() == PinCode){
                    MyFile.close();
                    return Client ;
                }
                vClient.push_back(Client);
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }



    enum  enSaveResult{svFialdEmptyObject=0 , svSucceeded=1 , svFialdAccountNumberExists=2} ;

    enSaveResult Save(){
        switch(_Mode){

            case enMode::EmptyMode:
            {
                if(IsEmpty())
                {
                    return enSaveResult::svFialdEmptyObject;
                    break;
                }

            }
            case enMode::UpdateMode:
            {
                _Update();

                return enSaveResult::svSucceeded ;
                  
                break;        
            }
            case enMode::AddNewMode:
            {
                //This will add new record to file or database
                if(clsBankClient::IsClientExist(_AccountNumber))
                {
                    return enSaveResult::svFialdAccountNumberExists;
                }
                else
                {
                    _AddNew();
                    //We need to set the mode to update after add new
                    _Mode = enMode::UpdateMode;
                    return enSaveResult::svSucceeded ;
                }
                break;
            }

        }
    }

    static bool IsClientExist(string AccountNumber){
        clsBankClient Client = clsBankClient::Find(AccountNumber) ;
        return (!Client.IsEmpty()) ;
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber){
        return clsBankClient(enMode::AddNewMode , "" , "" , "" ,"" ,AccountNumber , "" ,0); 
    }


    bool Delete()
    {
        vector <clsBankClient> _vClients ;
        _vClients = _LoadClientDataFromFile();

        for(clsBankClient & C : _vClients)
        {
            if(C.AccountNumber() == _AccountNumber)
            {
                C._MarkForDelete = true ;
                break; 
            }
        }

        _SaveClientDataToFile(_vClients);
        *this = _GetEmptyClientObject();
        return true ;
    }

    static vector <clsBankClient> GetClientsList(){
        return _LoadClientDataFromFile();
    }

    static double GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList() ;
    
        double TotalBalances = 0;

        for(clsBankClient & Client : vClients)
        {
            TotalBalances += Client._AccountBalance ;
        }
        return TotalBalances ;
    }
    
    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool WithDraw(double Amount)
    {
        if(Amount > _AccountBalance)
        {
            return false;
        }
        else{
            _AccountBalance -= Amount;
            Save();
            return true;
        }

    }

    bool Transfer(float Amount, clsBankClient &DestinationClient , string UserName)
    {
        if (Amount > getAccountBalance())
        {
            return false;
        }
    
        WithDraw(Amount);
        DestinationClient.Deposit(Amount);
        _RegisterTransferLog(Amount,DestinationClient,UserName);
        return true;
    }



    static vector <stTrnsferLogRecord> GetTransfersLogList(){

        vector <stTrnsferLogRecord> vTransferRecord ;
        fstream MyFile ;
        MyFile.open("TransferLog.txt" , ios::in);

        if(MyFile.is_open())
        {

            string Line ;

            stTrnsferLogRecord TransferRecord ;

            while(getline(MyFile,Line))
            {

                TransferRecord = _ConvertTransferLogLineToRecord(Line);
                vTransferRecord.push_back(TransferRecord);

            }

            MyFile.close();
        }
        return vTransferRecord ;
    }






};