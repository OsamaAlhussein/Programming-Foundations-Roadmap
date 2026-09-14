#pragma once
#include<bits/stdc++.h> 
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsBankClient.h"

using namespace std ;

class clsTransferScreen : protected clsScreen{

    private:

    static void _PrintClientInfo(clsBankClient Client)
    {
        cout << "\nClient Card : ";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.getAccountBalance();
        cout << "\n___________________\n";
    }


    static string _ReadAccountNumber(){
                string AccountNumber ="";
            cout << "Please Enter Account Number to Transfer From : ";
            AccountNumber = clsInputValidate::ReadString();

            while(!clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "\nAccount Number is not found , choose another one : ";
                AccountNumber = clsInputValidate::ReadString();
            }
            return AccountNumber;
       }


    static float ReadAmount(clsBankClient SourceClient)
   {
       float Amount;

       cout << "\nEnter Transfer Amount? ";

       Amount = clsInputValidate::ReadFloatNumber();

       while (Amount > SourceClient.getAccountBalance())
       {
           cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
           Amount = clsInputValidate::ReadDblNumber();
       }
       return Amount;
   }   

    public:

    static void ShowTransferScreen()
    {

        _DrawScreenHeader("    \tTransfer Screen");



        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClientInfo(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClientInfo(DestinationClient);

        float Amount = ReadAmount(SourceClient) ;

        char Answer ='n';
        cout << "Are you sure you want to perform this peration y/n? ";
        cin >> Answer ;

        if(Answer == 'Y' || Answer == 'y')
        {
            if(SourceClient.Transfer(Amount , DestinationClient,CurrentUser.getUserName()))
            {
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }
            
            _PrintClientInfo(SourceClient);
            _PrintClientInfo(DestinationClient);
        }
        


    }

};