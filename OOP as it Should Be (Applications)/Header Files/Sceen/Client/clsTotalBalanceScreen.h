#pragma once
#include<bits/stdc++.h> 
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUtility.h"

using namespace std ;

class clsTotalBalanceScreen : protected clsScreen{

    private:
    static void PrintClientRecordBalanceLine(clsBankClient Client)
    {   

        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.getAccountBalance();

    }   
    
    public:

    static void  ShowTotalBalancesScreen()
    {   

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t  Balance List Screen";
        string SubTitle = "\t   (" + to_string(vClients.size()) + " Client(s).";
        _DrawScreenHeader(Title,SubTitle);
        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {
                PrintClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
        cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";

    }

};