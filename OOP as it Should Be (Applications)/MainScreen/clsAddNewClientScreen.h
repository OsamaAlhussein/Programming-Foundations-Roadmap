#pragma once 
#include<bits/stdc++.h> 
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

using namespace std ;

class clsAddNewClientScreen : protected clsScreen{

    private:

    static void _ReadClientInfo(clsBankClient & Client){

    cout << "\nEnter First Name : " ;
    Client.setFirstName(clsInputValidate::ReadString());

    cout << "\nEnter Last Name  : " ;
    Client.setLastName(clsInputValidate::ReadString());

    cout <<"\nEnter Email       : " ;
    Client.setEmail(clsInputValidate::ReadString());

    cout << "\nEnter Phone      : ";
    Client.setPhone(clsInputValidate::ReadString());

    cout << "\nEnter PinCode    : " ;
    Client.setPinCode(clsInputValidate::ReadString());

    cout << "\nEnter Account Balance : " ;
    Client.setAccountBalance(clsInputValidate::ReadFloatNumber());

    }

    static void _PrintClient(clsBankClient Client){
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.getFirstName();
        cout << "\nLastName    : " << Client.getLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.getEmail();
        cout << "\nPhone       : " << Client.getPhone();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.getPinCode();
        cout << "\nBalance     : " << Client.getAccountBalance();
        cout << "\n___________________\n";
    }

    public:

    static void ShowAddNewClientScreen(){

        if(!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return ;
        }

        _DrawScreenHeader("\t Add New Client Screen ");

        string AccountNumber = "";
        cout << "Please Enter Account Number : " ;
        AccountNumber = clsInputValidate::ReadString() ;

        while(clsBankClient::IsClientExist(AccountNumber)){

            cout << "\nAccount Number Is Already uesd , Choose another one : ";
            AccountNumber = clsInputValidate::ReadString() ;
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber) ;

        _ReadClientInfo(NewClient) ;

        clsBankClient::enSaveResult SaveResult ;
        SaveResult = NewClient.Save() ;

        switch(SaveResult)
        {
            case clsBankClient::enSaveResult::svSucceeded:
            {
                cout << "\nAccount Update Successfully : -)\n";
                _PrintClient(NewClient);
                break ;
            }

            case clsBankClient::enSaveResult::svFialdEmptyObject:
            {
                cout << "\n Error account was not saved because it's Empty";
                break;
            }

            case clsBankClient::enSaveResult::svFialdAccountNumberExists:
            {
                cout << "\nError account was not saved because account number is used!\n";
                break;        
            }
        
        }
    }
};
