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


    //Copy Constructors , I delved deeper and understood what was happening , This is what the compiler writes.
    clsAddress(clsAddress & Old_Obj){
        _AddressLine1 = Old_Obj.getAddressLine1();
        _AddresLine2 = Old_Obj.getAddressLine2();
        _POBox = Old_Obj.getPOBox();
        _ZipCode = Old_Obj.getZipCode();
    }

    void setAddressLine1(string AddressLine1){
    _AddressLine1 = AddressLine1 ;
    }

    string getAddressLine1(){
        return _AddressLine1;
    }

    void setAddressLine2(string AddressLine2){
        _AddresLine2 = AddressLine2;
    }

    
    string getAddressLine2(){
        return _AddresLine2;
    }

    void setPOBox(string POBox){
        _POBox = POBox ;
    }

    string getPOBox(){
        return _POBox;
    }

    void setZipCode(string ZipCode){
        _ZipCode = ZipCode;
    }

    string getZipCode(){
        return _ZipCode ;
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


    clsAddress Address2 = Address1 ;
    Address2.Print();


    return 0;
}
