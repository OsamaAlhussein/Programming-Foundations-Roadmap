#pragma once
#include<bits/stdc++.h>
#include"clsPerson.h"
#include"clsStirng.h"
#include"Global.h"
#include"clsUtility.h"
using namespace std ;

class clsUser : public clsPerson{

    public:
    struct stLoginRegisterRecord;
    private:

    enum enMode{EmptyMode= 0 , UpdateMode= 1 , AddNewMode=2};
    enMode _Mode ;
    string _UserName ;
    string _Passaword ;
    int _Permissions ;

    bool _MarkForDelete = false ;


    
    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
    {
        stLoginRegisterRecord LoginRegisterRecord;


        vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
        LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
        LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
        LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2]);
        LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

        return LoginRegisterRecord;

    }

    string _PrepareLogInRecord( string Seperator = "#//#")
    {
        string LoginRecord = "";
        LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
        
        LoginRecord += getUserName() + Seperator;

        // here we encrypt store the encrypted Password not the real one.
        LoginRecord += clsUtil::EncryptText(getPassword()) + Seperator;
        LoginRecord += to_string(getPermissions());

        return LoginRecord;
    }


    static clsUser _ConvertLinetoUserObject(string Line , string Seperator="#//#"){
        vector <string> vUserData ;
        vUserData = clsString::Split(Line,Seperator);

        return clsUser(enMode::UpdateMode , vUserData[0] , vUserData[1] , vUserData[2]
             ,vUserData[3] , vUserData[4] ,clsUtil::DecryptText(vUserData[5]) ,stoi(vUserData[6]));
    }

    static string _ConvertObjectUserToLine(clsUser User , string Seperator="#//#")
    {
        string UserRecord="";
        UserRecord += User.getFirstName() + Seperator;
        UserRecord += User.getLastName() + Seperator;
        UserRecord += User.getEmail() + Seperator;
        UserRecord += User.getPhone() +  Seperator;
        UserRecord += User.getUserName() + Seperator ;
        // here we encrypt store the encrypted Password not the real one.
        UserRecord += clsUtil::EncryptText(User.getPassword()) +Seperator;
        UserRecord += to_string(User.getPermissions());

        return UserRecord ;

    }



    static vector <clsUser> _LoadUsersDataFromFile(){
        vector <clsUser> vUsser ;
        fstream MyFile ;

        MyFile.open("Users.txt" , ios::in); // ReadMore

        if(MyFile.is_open()){

            string Line ;
            

            while(getline(MyFile,Line)){
               clsUser Users  = _ConvertLinetoUserObject(Line);
                vUsser.push_back(Users) ;
            }
            MyFile.close();
        }
        return vUsser ; 
    }

    static void _SaveUsersDataFromFile(vector <clsUser> vUser)
    {
        fstream MyFile ;
        MyFile.open("Users.txt" , ios::out);
        string DataLine ;
        if(MyFile.is_open())
        {
            for(clsUser & U : vUser)
            {
                if(U._MarkForDelete == false)
                {
                    DataLine = _ConvertObjectUserToLine(U);
                    MyFile << DataLine << endl ;
                }
            }
            MyFile.close();
        }
    }


    void _Update()
    {
        vector <clsUser> _vUsers ;
        _vUsers = _LoadUsersDataFromFile();

        for(clsUser & U : _vUsers)
        {
            if(U.getUserName() == getUserName())
            {
                U = *this ;
                break;
            }
        }
        _SaveUsersDataFromFile(_vUsers);
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertObjectUserToLine(*this));
    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    public:

    enum enPermissions{
        eAll=-1  ,pListClients=1 , pAddNewClient=2 , pDeleteClient=4 , pUpdateClients=8 ,
        pFindClient = 16 , pTranactions =32 , pManageUsers =64  , pLoginRegister = 128
    };


    struct stLoginRegisterRecord
    {
        string DateTime;
        string UserName;
        string Password;
        int Permissions;

    };

    


    clsUser(enMode Mode , string FirstName , string LastName , string Email , string Phone ,
    string UserName , string Password , int Permissions) : clsPerson(FirstName,LastName,Email,Phone){

        _Mode = Mode ;
        _UserName = UserName;
        _Passaword = Password ;
        _Permissions = Permissions ;
    }


    bool IsEmpty(){
        return (_Mode == enMode::EmptyMode) ;
    }

    bool MardForDeleted(){
        return _MarkForDelete;
    }

    void setUserName(string UserName){
        _UserName = UserName ;
    }

     string getUserName(){
        return _UserName;
    }

    void setPassword(string Password){
        _Passaword = Password;
    }

    string getPassword()
    {
        return _Passaword;
    }

    void setPermissions(int Permission)
    {
        _Permissions = Permission;
    }

    int getPermissions()
    {
        return _Permissions ;
    }


    static clsUser Find(string UserName){
        
        fstream MyFile ;

        MyFile.open("Users.txt" , ios::in);

        if(MyFile.is_open()){
            string Line ;
            while(getline(MyFile,Line)){
                clsUser User = _ConvertLinetoUserObject(Line);

                if(User.getUserName() == UserName)
                {
                    MyFile.close();
                    return User;
                }


            }
            MyFile.close();
        }

        return _GetEmptyUserObject();
    }


    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.getUserName() == UserName && User.getPassword() == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults{ svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };


    enSaveResults Save()
    {

        switch(_Mode)
        {
            case enMode::EmptyMode:
            {
                if(IsEmpty())
                {
                    return enSaveResults::svFaildEmptyObject;
                }
            }

            case enMode::UpdateMode:
            {
                _Update();
                return enSaveResults::svSucceeded;
                break;
            }

            case enMode::AddNewMode:
            {
                if(clsUser::IsUserExist(_UserName))
                {
                    //This will add new record to file or database
                    return enSaveResults::svFaildUserExists;
                }
                else
                {
                    _AddNew();
                    //We need to set the mode to update after add new
                    _Mode = enMode::UpdateMode;
                    return enSaveResults::svSucceeded;
                }
                break;
            }
        }

    }

    static bool IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for(clsUser & U : _vUsers)
        {
            if(U.getUserName() == _UserName)
            {
                U._MarkForDelete = true ;
                break;
            }
        }
        _SaveUsersDataFromFile(_vUsers);
        *this = _GetEmptyUserObject();
        return true ;
    }


    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    bool CheckAccessPermission(enPermissions Permission)
    {
        if(this->_Permissions == enPermissions::eAll)
        {
            return true ;
        }

        if((Permission & this->getPermissions())== Permission)
        {
            return true ;
        }
        else
        {
            return false ;
        }
        
    }


    void RegisterLogIn()
    {

        string stDataLine = _PrepareLogInRecord();

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }





    static vector<stLoginRegisterRecord> GetLoginRegisterList()
    {
        vector<stLoginRegisterRecord> vLoginRegisterRecord;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in); // ملف تسجيل الدخول

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                if (!Line.empty())
                {
                    stLoginRegisterRecord Record = _ConvertLoginRegisterLineToRecord(Line);
                    vLoginRegisterRecord.push_back(Record);
                }
            }

            MyFile.close();
        }

        return vLoginRegisterRecord;
    }


};