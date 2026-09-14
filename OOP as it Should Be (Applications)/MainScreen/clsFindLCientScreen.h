#pragma once
#include<bits/stdc++.h> 
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

using namespace std ;

class clsFindClientScreen : protected clsScreen{

    private:

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

    static void ShowFindClientScreen(){

        if(!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return ;
        }

        _DrawScreenHeader("\t Find Client Screen ");
                string AccountNumber = "";
        cout << "\nPlease Enter client Accout Number : ";
        AccountNumber = clsInputValidate::ReadString() ;

        while(!clsBankClient::IsClientExist(AccountNumber)){

            cout << "\nAccount number is not found , choose another one :  ";
            AccountNumber = clsInputValidate::ReadString() ;
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber) ;

        if(!Client.IsEmpty()){
            cout << "\nClient Found -)\n";
        }
        else{
            cout << "\nClient Was not Found : -(\n";
        }

        _PrintClient(Client) ;

    }

};