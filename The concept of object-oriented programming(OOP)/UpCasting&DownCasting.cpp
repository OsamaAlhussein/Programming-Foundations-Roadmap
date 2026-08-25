#include<iostream>
using namespace std ;

class clsPerson{
    public:
    string FullName = "Osama Al-Huseein";
};

class clsEmployee : public clsPerson {

    public:
    string Title = "CEO";

};

int main(){


    clsEmployee Employee1 ;
   cout <<  Employee1.FullName << endl ;

    // UpCasting 
   clsPerson * Person1 = &Employee1 ;
   cout << Person1->FullName ; 


   // DownCastion 
   //clsPerson Person2 ;
   //clsEmployee *Employee2 = &Person2 ; Error


    return 0;
}
