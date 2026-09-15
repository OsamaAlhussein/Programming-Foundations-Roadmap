#pragma once
#include<bits/stdc++.h>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsStirng.h"
//=========
#include"clsListCurrencyScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateRateScreen.h"
#include"clsCalculatorScreen.h"




class clsCurrencyMainScreen : protected clsScreen{

    private :

    enum enCurrenciesMainMenueOptions{eListCurrency=1 , eFindCurrency=2 , eUpdateRate=3
    , eCurrencyCalculator=4 , eMainMenue=5};


    static short _ReadCurrencyExhangeMenurOption(){
        cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 5] ? ";
        short Choise = clsInputValidate::ReadShortNumberBetween(1,5,"Enter Number between 1 to 5");
        return Choise ;
    }

    static void _GoBackToCurrenciesMenue()
    {
        cout << "\n\nPress any key to go back to Currencies Menue...";
        system("pause>0");
        ShowCurrencyMainScreen();
    }

    static void _ShowListCurrencyScreen()
    {
        // "\nList Currencies List will be here ";
        clsListCurrecnyScreen::ShowListCurrencyScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        // "\nFind Currencies Find will be here ";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        // "\nUpdate Currencies Updat will be here ";
        clsUptadeRateScreen::ShowUpdateRateSceen();
    }

    static void _ShowCalculatorScreen()
    {
        //"\nCaluclator Currencies Calculator will be here ";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void  _PerformCurrencyExhangeMenue(enCurrenciesMainMenueOptions  CurrncyOptions)
    {

        switch(CurrncyOptions)
        {
            case enCurrenciesMainMenueOptions ::eListCurrency:
            {
                system("cls");
                _ShowListCurrencyScreen();
                _GoBackToCurrenciesMenue();
                break;
            }

            case enCurrenciesMainMenueOptions::eFindCurrency:
            {
                system("cls");
                _ShowFindCurrencyScreen();
                _GoBackToCurrenciesMenue();
                break;
            }

            case enCurrenciesMainMenueOptions::eUpdateRate:
            {
                system("cls");
                _ShowUpdateRateScreen();
                _GoBackToCurrenciesMenue();
                break;
            }

            case enCurrenciesMainMenueOptions::eCurrencyCalculator:
            {
                system("cls");
                _ShowCalculatorScreen();
                _GoBackToCurrenciesMenue();
                break;
            }

            case enCurrenciesMainMenueOptions::eMainMenue:
            {
               
            }

        }
    }


    public:

    static void ShowCurrencyMainScreen()
    {
        system("cls");
        _DrawScreenHeader("\tCurrency Exhange Main Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tCurrency Exhange Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
            cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
            cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
            cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
            cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";
            _PerformCurrencyExhangeMenue((enCurrenciesMainMenueOptions) _ReadCurrencyExhangeMenurOption());
    }
};