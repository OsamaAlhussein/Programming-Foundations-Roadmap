#include<iostream>
using namespace std ;



class clsPerson{

    private:
    struct Address{
        string AddressLine1 ;
        string AddressLine2 ;
        string City ;
        string Country ;

    };

    public:
    string FullName ;
    Address Address1 ;

    clsPerson(){
        FullName = "Osama Al-Huseein";
        Address1.AddressLine1 = "Building 10 ";
        Address1.AddressLine2 = "Akrama Street ";
        Address1.City = "DerAlzore ";
        Address1.Country = "Syria ";
    }

    void PrintAddress(){
        cout << FullName << endl ;
        cout << Address1.AddressLine1 << endl ;
        cout << Address1.AddressLine2 << endl ;
        cout << Address1.City << endl ;
        cout << Address1.Country << endl ;
    }
    
};

int main(){

    clsPerson Person1 ;

    Person1.PrintAddress();


    return 0;
}
