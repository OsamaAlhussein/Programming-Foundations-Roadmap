#include<iostream>
using namespace std ;


class clsPerson{
    private:
    int _Id ;
    string _FristName ;
    string _LastName ; 
    string _Email ;
    string _Phon ;

    public:

    clsPerson(int Id , string FirstName , string LastName , string Email , string Phon){
        _Id = Id ;
        _FristName  = FirstName ;
        _LastName = LastName ;
        _Email = Email ;
        _Phon = Phon ;
    }
    // Read Only Property
    int ID(){
        return _Id ;
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

    string FullName(){
        return _FristName  +" "+ _LastName ;
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
    void setPhon(string Phon){
        _Phon = Phon ;
    }
    // Prorerty get
    string getPhon(){
        return _Phon ;
    }

    void Print(){
        cout << "\nInfo\n" ;
        cout << "\n-------------------------------\n";
        cout << "\nID         : "<< _Id ;
        cout << "\nFirst Name : " << _FristName ;
        cout << "\nLast Name  : " << _LastName;
        cout << "\nFull Name  : " << FullName() ;
        cout << "\nEmail      : " << _Email ;
        cout << "\nPhon       : " << _Phon ;
        cout << "\n-------------------------------\n";
    }

    void SendEmail(string Subject, string Body){
        cout << "\n\nThe following message sent successfully to email : " << _Email << endl ;
        cout << "Subject : " << Subject << endl ;
        cout << "Body : " << Body << endl ; 
    }

    void SendSMS(string TextMessage){
        cout << "\n\nThe Follwing SMS sent successfully to phone : " << _Phon << endl ;
        cout << TextMessage << endl ;
    }
};


int main(){

    clsPerson Person1(10 , "Osama" , "Al-Hosein" , "OS@gamil.com" , "096435");

    Person1.Print() ;

    Person1.SendEmail("Hi" , "How are you ?");

    Person1.SendSMS("How are you ?");

    

    return 0;
}
