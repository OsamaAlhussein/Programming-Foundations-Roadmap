#pragma once
#include<bits/stdc++.h> 
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

using namespace std ;


class clsWithDrawScreen : protected clsScreen{

    private:
        static void _PrintClient(clsBankClient Client)
    {
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

        static string _ReadAccountNumber(){
        string AccountNumber = "";
        cout << "Please Enter Account Number ? ";
        cin >> AccountNumber ;
        return AccountNumber;
    }

    public:

    static void ShowWithDrawScreen(){

        _DrawScreenHeader("\t    With Draw Screen");

        string AccountNumber = _ReadAccountNumber(); 

        while(!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n Client with [ " << AccountNumber <<" ] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        
        cout << "\nPlease enter With Draw amount ? " ; 
        double Amount = 0;
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        
        if (Answer == 'Y' || Answer == 'y')
        {
            if(Client1.WithDraw(Amount))
            {
                cout << "\nAmount Withdrew Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.getAccountBalance();
            }else
            {
                cout << "\nyou can't withdraw this " << Client1.getAccountBalance() 
                << "becouse  your Balance Smaller than the drawn amount\n";
            }


        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }


    }
    
};