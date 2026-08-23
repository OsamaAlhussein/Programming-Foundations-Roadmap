#include<iostream>
using namespace std ;


class clsAddress{
    private:
    string _AddressLine1 ;
    string _AddresLine2 ;
    string _POBox;
    string _ZipCode ;

    public:

    clsAddress(string AddressLine1 , string AddressLine2 , string POBox , string ZipCode){
        _AddressLine1 = AddressLine1 ;
        _AddresLine2 = AddressLine2 ;
        _POBox = POBox ;
        _ZipCode = ZipCode ;
    }

 

    void Print(){
        cout << "\nAddress Details:\n";
        cout << "------------------------";
        cout << "\nAddressLine1: " << _AddressLine1 <<endl;
        cout << "AddressLine2: " << _AddresLine2 << endl;
        cout << "POBox : " << _POBox << endl;
        cout << "ZipCode : " << _ZipCode << endl;
    }



};



int main(){

    clsAddress Address1("Queen Alia street " , "B 302" , "2653" , "4444") ;
    Address1.Print();


    return 0;
}
