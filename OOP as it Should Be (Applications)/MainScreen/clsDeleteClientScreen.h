#pragma once
#include<bits/stdc++.h> 
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

using namespace std ;

class clsDeleteClientScreen : protected clsScreen{

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

    static void ShowDeleteClientScreen(){

        if(!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return ;
        }

    _DrawScreenHeader(" \t Delete Client Screen ");
    string AccountNumber = "";
    cout << "Please Enter Account Number : " ;
    AccountNumber = clsInputValidate::ReadString() ;

    while(!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number Is Already uesd , Choose another one : ";
        AccountNumber = clsInputValidate::ReadString() ;
    }
    clsBankClient Client = clsBankClient::Find(AccountNumber) ;
    _PrintClient(Client) ;

    cout << "\nAre you sure you want delet this client y/n ? " ;
    char Answer = 'n';
    cin >> Answer ;

    if(Answer == 'Y' || Answer=='y')
    {
        if(Client.Delete())
        {
            cout << "\nClient Delete Successfully :-)\n" ;
            _PrintClient(Client);
        }
        else
        {
            cout << "\nError Client Was not Deleted\n";
        }

    }


}

};