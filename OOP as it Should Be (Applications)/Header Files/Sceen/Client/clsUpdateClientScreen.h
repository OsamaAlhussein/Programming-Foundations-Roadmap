#pragma once
#include<bits/stdc++.h> 
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

using namespace std ;

class clsUpdateClientScreen : protected clsScreen{


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

    static void ShowUpdateClientScreen(){  

        if(!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return ;
        }

        _DrawScreenHeader("\tUpdate Client Screen");

        string AccountNumber = "";
        cout << "\nPlease Enter client Accout Number : ";
        AccountNumber = clsInputValidate::ReadString() ;

        while(!clsBankClient::IsClientExist(AccountNumber)){

            cout << "\nAccount number is not found , choose another one :  ";
            AccountNumber = clsInputValidate::ReadString() ;
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber) ;
        _PrintClient(Client) ;

        cout << "\n\nUpdate Client Info : ";
        cout << "\n________________________\n";
        _ReadClientInfo(Client) ; 

        clsBankClient::enSaveResult SaveResult ;
        SaveResult = Client.Save() ;

        switch(SaveResult){

            case clsBankClient::enSaveResult::svSucceeded :
            {
                cout << "\nAccount Update Successfully : -)\n";
                _PrintClient(Client);
                break;
            }
            case clsBankClient::enSaveResult::svFialdEmptyObject:
            {
                cout << "\n Error account was not saved because it's Empty";
                break;
            }
        }

    }


};