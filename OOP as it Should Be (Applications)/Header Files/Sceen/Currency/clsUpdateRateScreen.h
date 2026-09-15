#pragma once 
#include<bits/stdc++.h>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std ;


class  clsUptadeRateScreen : protected clsScreen{

    private:


    static float _ReadRate()
    {
        cout << "\nEnter New Rate: ";
        float NewRate = 0;

        NewRate = clsInputValidate::ReadFloatNumber();
        return NewRate;
    }

    static void _PrintCurrencyCard(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();
        cout << "\n_____________________________\n";


    }


    public:


    static void ShowUpdateRateSceen()
    {
        _DrawScreenHeader("\t   Update Rate Screen");

        
        string CurrencyCode = "";

        cout << "\nPlease Enter Currency Code: ";
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrencyCard(Currency);

        cout << "\nAre you sure you want to update the rate of this Currency y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";

            Currency.UpdateRate( _ReadRate());

            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrencyCard(Currency);
          

        }


         
    }


};