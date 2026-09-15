#pragma once 
#include<bits/stdc++.h>
#include"Global.h"
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"clsUser.h"


class clsLoginScreen : protected clsScreen{
    private:


    static bool _Login()
    {
        bool LoginFaild = false;
        short FaildLoginCount = 0;
        string UserName , Password ;

        do{
            
            if(LoginFaild)
            {
                FaildLoginCount++;
                cout << "\nInvlaid UserName/Password\n";
                cout << "\nYou have " << (3-FaildLoginCount)
                << " Trial(s) to login.\n\n"; 
            }

            if(FaildLoginCount==3)
            {
                cout << "\nYour are Locked after 3 faild trails \n\n";
                return false;
            }

            cout << "\nEnter UserName ? ";
            cin >> UserName;
            cout << "\nEnter Password ? ";
            cin >> Password ;

            CurrentUser = clsUser::Find(UserName,Password);

            LoginFaild = CurrentUser.IsEmpty();


        }while(LoginFaild);
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true ;
    }


    public:

    static bool ShowLoginScreen(){
            system("cls");
            _DrawScreenHeader("   \t Login Screen");
            return _Login();
        }
};