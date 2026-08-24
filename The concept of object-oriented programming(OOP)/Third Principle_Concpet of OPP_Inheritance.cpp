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

};

int main(){

clsEmployee Employee1 ;

Employee1.setFirstName("Osama");
Employee1.setLastName("Al-Housein");
Employee1.setPhon("096435");
Employee1.setEmail("OS@gmail.com");
Employee1.Print();

Employee1.SendSMS("How are you ?? ");

Employee1.SendEmail("Hi Osama " , "How are you ??");

Employee1.setSalary(5000);
cout << endl << Employee1.getSalary();

    return 0;
}
