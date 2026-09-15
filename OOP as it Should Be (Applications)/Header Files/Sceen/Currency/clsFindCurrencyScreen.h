#pragma once 
#include<bits/stdc++.h>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std ;

class clsFindCurrencyScreen : protected clsScreen{

    private:

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

    static void  _ShowResult(clsCurrency Currency)
    {
        if(!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :)\n";
            _PrintCurrencyCard(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :(\n";
        }
    }


    public:

    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\t   Find Currency Screen");

        cout << "Find By : [1] Code  (or)  [2] Country ? ";
        short Num = clsInputValidate::ReadShortNumberBetween(1,2,"Enter 1 or 2 ?");

        if(Num==1)
        {
            cout << "Please Enter CurrencyCode : ";
            string Code = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(Code);
            _ShowResult(Currency);
        }
        else
        {
            cout << "Please Enter Country Name : ";
            string Country = clsInputValidate::ReadString();
            clsCurrency Currecny = clsCurrency::FindByCountry(Country);
            _ShowResult(Currecny);
            
        }
    }
};