#pragma once
#include<bits/stdc++.h>
#include "clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

using namespace std ;

class clsDeleteUserScreen : protected clsScreen{

    private:

        static void _PrintUser(clsUser User)
        {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.getFirstName();
        cout << "\nLastName    : " << User.getLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.getEmail();
        cout << "\nPhone       : " << User.getPhone();
        cout << "\nUser Name   : " << User.getUserName();
        cout << "\nPassword    : " << User.getPassword();
        cout << "\nPermissions : " << User.getPermissions();
        cout << "\n___________________\n";

    }

    public:

    static void ShowDeletUser(){

        _DrawScreenHeader("   \t Delet User Screen");

        string UserName="";
        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Already Used, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);

        _PrintUser(User1); 

        cout << "Are you sure you want to delete this User y/n ? ";
        char answer ='n';
        cin >> answer;

        if(answer == 'Y' || answer == 'y')
        {
            if(User1.Delete())
            {
                cout << "\nUser Deleted Successfully : -)\n";
                _PrintUser(User1);
            }
            else{
                cout << "\nError User was not Deleted \n";
            }
        }


    }
};