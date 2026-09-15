#pragma once
#include<bits/stdc++.h> 
using namespace std;
class clsPerson{
    private:
  
    string _FristName ;
    string _LastName ; 
    string _Email ;
    string _Phone ;

    public:

    clsPerson(string FirstName , string LastName , string Email , string Phone){
     
        _FristName  = FirstName ;
        _LastName = LastName ;
        _Email = Email ;
        _Phone = Phone ;
    }

    // Property set 
    void setFirstName(string FirstName){
        _FristName = FirstName ;
    }
    // Prorerty get
    string getFirstName(){
        return _FristName ;
    }
    // Property set
    void setLastName(string LastName){
        _LastName=LastName;
    }
    // Prorerty get
    string getLastName(){
        return _LastName ;
    }

    // Property set
    void setEmail(string Email){
        _Email = Email ;
    }
    // Prorerty get
    string getEmail(){
        return _Email;
    }
    // Property set
    void setPhone(string Phon){
        _Phone = Phon ;
    }
    // Prorerty get
    string getPhone(){
        return _Phone ;
    }

    
    string FullName(){
        return _FristName  +" "+ _LastName ;
    }

    
};