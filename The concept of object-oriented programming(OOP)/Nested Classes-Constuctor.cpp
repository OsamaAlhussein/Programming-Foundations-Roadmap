#include<iostream>
using namespace std;


class clsPerson{
    string _FullName ;

    class clsAddress{
        private:
        string _AddressLine1 ;
        string _AddressLine2 ;
        string _City ;
        string _Country ;

        public:
        clsAddress(string AddressLine1 , string AddressLine2 , string City , string Country){
            _AddressLine1 =AddressLine1;
            _AddressLine2 = AddressLine2 ;
            _City = City ;
            _Country =Country ;
        }

        void setAddressLine1(string AddressLine1){
            _AddressLine1 =AddressLine1 ;
        }

        string getAddressLine1(){
            return _AddressLine1 ;
        }


        void setAddressLine2(string AddressLine2){
            _AddressLine2 = AddressLine2 ;
        }

        string getAddressLine2(){
            return _AddressLine2 ;
        }


        void setCity(string City){
            _City = City ;
        }

        string getCity(){
            return _City ;
        }

        void setCountry(string Country){
            _Country = Country ;
        }

        string setCountry(){
            return _Country ;
        }

        void Print(){

            cout << "Address : \n";
            cout << _AddressLine1 << endl ;
            cout << _AddressLine2 << endl ;
            cout << _City << endl ;
            cout << _Country << endl ;
        }
    };

    public:
    
    void setFullName(string FullName){
        _FullName = FullName ;
    }

    string getFullName(){
        return _FullName ;
    }


    clsAddress Address = clsAddress("","","","");

    clsPerson(string FullName , string AddressLine1 , string AddressLine2 , string City , string Country){

        _FullName = FullName;

        //initiate address class by it's constructor
        Address = clsAddress(AddressLine1,AddressLine2,City,Country);
    }
};


int main()

{

    clsPerson Person("Osama Al-Huseein" , "Building 10 " , "Akarma street" , "DerAlzore" , "Syria");
    
    Person.Address.Print() ;
    
    

    return 0;
}
