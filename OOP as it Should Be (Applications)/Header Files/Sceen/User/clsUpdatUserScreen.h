#pragma once
#include<bits/stdc++.h>
#include "clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"


using namespace std ;

class clsUpdateUserScreen : protected clsScreen{

    private:

    static void _ReadUserInfor(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.setFirstName(clsInputValidate::ReadString());

        cout << "\nEnter LastName: ";
        User.setLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email: ";
        User.setEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone: ";
        User.setPhone(clsInputValidate::ReadString());

        cout << "\nEnter Password: ";
        User.setPassword(clsInputValidate::ReadString());

        cout << "\nEnter Permission: ";
        User.setPermissions(_ReadPermissionsToSet());
    }

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
    
    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        return Permissions;

    }

    public:

    static void ShowUpdateUserScreen(){

        _DrawScreenHeader("   \t Update User Screen");

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

        cout << "Are you suer you want to Update this User y/n ? ";
        char answer = 'n';
        cin >> answer ;

        if(answer=='y' || answer=='Y')
        {
            
                    cout << "\nUpdate User Info \n";
        cout <<"_____________________\n";
        _ReadUserInfor(User1) ;

        

        clsUser::enSaveResults SaveResult ;

        SaveResult = User1.Save();

        switch (SaveResult)
        {
            case  clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nUser Addeded Successfully :-)\n";
                _PrintUser(User1);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError User was not saved because it's Empty";
                break;

            }
            case clsUser::enSaveResults::svFaildUserExists:
            {
                cout << "\nError User was not saved because UserName is used!\n";
                break;

            }
        }
    }





    }


};