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

    clsPerson(){

    }

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


class clsEmployee : public clsPerson{

    private:
    string _Title;
    string _Department;
    float _Salary;

    public:

    clsEmployee(int Id , string FirstName , string LastName , string Email , string Phon , string Title , string  Department , float Salary) 
    : clsPerson(Id , FirstName , LastName , Email , Phon){

        _Title = Title ;
        _Department = Department ;
        _Salary = Salary ;
    }


    // Property set
    void setTitle(string Title){
        _Title = Title ;
    }
    // Prorerty get
    string getTitle(){
        return _Title;
    }
    // Property set
    void setDepartment(string Department){
        _Department = Department ;
    }
    // Prorerty get
    string getDepartment(){
        return _Department ;
    }
    // Property set
    void setSalary(float Salary){
        _Salary = Salary;
    }
    // Prorerty get
    float getSalary(){
        return _Salary ;
    }


    void Print(){ 
        cout << "\nInfo\n" ;
        cout << "\n-------------------------------\n";
        cout << "\nID         : "<< ID() ;
        cout << "\nFirst Name : " << getFirstName() ;
        cout << "\nLast Name  : " << getLastName() ;
        cout << "\nFull Name  : " << FullName() ;
        cout << "\nEmail      : " << getEmail() ;
        cout << "\nPhon       : " << getPhon() ;
        cout << "\nTitle      : " << _Title ;
        cout << "\nDepartment : " << _Department ;
        cout << "\nSalary     : " << _Salary ;
        cout << "\n-------------------------------\n";
    }

};


class clsDeveloper : public clsEmployee{

    private:
    string _ProgrammingLanguage ;

    public:

    clsDeveloper(int Id , string FirstName , string LastName , string Email , string Phon , string Title ,
        string Department , float Salary , string ProgrammingLanguage) 
        : clsEmployee(Id , FirstName , LastName , Email , Phon , Title , Department , Salary)
        {
            _ProgrammingLanguage = ProgrammingLanguage ;
        }

        void setProgrammingLanguage(string ProgrammingLanguage){
            _ProgrammingLanguage = ProgrammingLanguage ;
        }

        string getProgrammingLanguage(){
            return _ProgrammingLanguage ;
        }

    void Print(){
        cout << "\nInfo\n" ;
        cout << "\n-------------------------------\n";
        cout << "\nID                   : "<< ID() ;
        cout << "\nFirst Name           : " << getFirstName() ;
        cout << "\nLast Name            : " << getLastName() ;
        cout << "\nFull Name            : " << FullName() ;
        cout << "\nEmail                : " << getEmail() ;
        cout << "\nPhon                 : " << getPhon() ;
        cout << "\nTitle                : " << getTitle() ;
        cout << "\nDepartment           : " << getDepartment() ;
        cout << "\nSalary               : " << getSalary() ;
        cout << "\nProgramming Language : " << _ProgrammingLanguage ;
        cout << "\n-------------------------------\n";
    }
};

int main(){

clsDeveloper Developer(10,"Osama","Al-Housein" , "OS@gmail.com" , "096435" , "COE" , "Algo" , 5000 , "C++") ;

Developer.Print();

Developer.SendSMS("Hi Mr Developer ");

    return 0;
}
